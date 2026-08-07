

void simulationEngine::runMainLoop()
{
    if (events.isEmpty()) return;

    while (!events.isEmpty() || !emergencyQueue.isEmpty() || !regularQueue.isEmpty())
    {

        while (!events.isEmpty() &&
            events.getHead()->data->getTimestamp() == Advancecounter)
        {
            Event* currentEvent = nullptr;
            events.removeHead(currentEvent);

            switch (currentEvent->getKind())
            {
            case CHECK_IN:
            {
                Patient* p = new Patient(currentEvent->getPatientId(),
                    currentEvent->getTimestamp(),
                    currentEvent->getBranch(),
                    currentEvent->getNumTests(),
                    currentEvent->getPatientType());

                if (p->getType() == EMERGENCY)
                    emergencyQueue.enqueue(p);
                else
                    int priority;//priorityQueue formula

                regularQueue.enqueue(p, priority);

                break;
            }
            case LEAVE:
            {
                Patient* leaving = regularQueue.removeByID(currentEvent->getPatientId());
                if (leaving != nullptr) delete leaving;
                break;
            }
            case ESCALATE:            //priority will be less
            {
                Patient* p = regularQueue.removeByID(currentEvent->getPatientId());
                if (p != nullptr) {
                    p->setType(EMERGENCY);
                    emergencyQueue.enqueue(p);
                }
                break;
            }
            }

            delete currentEvent;
        }



        auto* branchNode = branches.getHead();
        while (branchNode != nullptr)
        {
            Branch* b = branchNode->data;
            auto* docNode = b->getDoctors().getHead();

            while (docNode != nullptr)
            {
                Doctor& doc = docNode->data;
                // لو الدكتور شغال ووقت انتهاء كشفه جه دلوقتي
                if (doc.isBusy() && doc.getFinishTime() == Advancecounter)
                {
                    Patient* finishedPatient = doc.getAssignedPatient();
                    if (finishedPatient != nullptr) {
                        donePatients.enqueue(finishedPatient); // نقل المريض للمنتهين
                        doc.setAssignedPatient(nullptr);
                    }
                    doc.setFree(); // تغيير حالته لـ Free ليكون جاهز للدفعة الجديدة
                }
                docNode = docNode->next;
            }
            branchNode = branchNode->next;
        }

        // Step B: Auto-Escalation (ترقية المرضى اللي طولوا في الانتظار للطوارئ)
        // بنفحص أول مريض في طابور العاديين، لو بقاله واقف أكتر من المسموح بيروح للطوارئ
        while (!regularQueue.isEmpty() &&
            (Advancecounter - regularQueue.getFront()->getArrivalTime()) >= utilities.getAutoEscalateLimit())
        {
            Patient* p = regularQueue.dequeue();
            p->setType(EMERGENCY);
            emergencyQueue.enqueue(p);
        }

        // Step C: تسكين الأطباء المتاحين (الطوارئ أولوية أولاً، ثم العاديين)
        branchNode = branches.getHead();
        while (branchNode != nullptr)
        {
            Branch* b = branchNode->data;
            auto* docNode = b->getDoctors().getHead();

            while (docNode != nullptr)
            {
                Doctor& doc = docNode->data;

                // لو الدكتور فاضي، بنسكنله مريض من الطوارئ الأول، ولو مفيش بناخد من العاديين
                if (!doc.isBusy())
                {
                    Patient* pToServe = nullptr;

                    if (!emergencyQueue.isEmpty()) {
                        pToServe = emergencyQueue.dequeue();
                    }
                    else if (!regularQueue.isEmpty()) {
                        pToServe = regularQueue.dequeue();
                    }

                    if (pToServe != nullptr) {
                        int visitTime = calculateVisitTime(pToServe, &doc);
                        doc.setBusy(Advancecounter + visitTime); // وقت الانتهاء = الحالي + وقت الزيارة
                        doc.setAssignedPatient(pToServe);
                    }
                }
                docNode = docNode->next;
            }
            branchNode = branchNode->next;
        }

        Advancecounter++;
    }
}
