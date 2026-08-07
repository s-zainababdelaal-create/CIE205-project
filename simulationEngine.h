#pragma once
#include "Patient.h"
#include "Doctor.h"
#include "Branch.h"
#include "Event.h"
#include "Utilities.h"
#include "Queue.h"
#include "LinkedList.h"
#include "Priority_Queue.h"

class simulationEngine {


	int Advancecounter = 0;
	//
	LinkedList<Event*> events;
	LinkedList<Branch*> branches;
	Queue<Patient*> emergencyQueue;
	PriorityQueue<Patient*> regularQueue;
	;

public:
	void runMainLoop();

};