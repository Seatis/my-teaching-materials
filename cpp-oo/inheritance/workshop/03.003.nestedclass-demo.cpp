#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

// Just as namespaces can be nested, so can classes be nested as well.
// In this case the nodes of the LinkedList are only accessible for the 
// Linked list. No one outside needs to know about them.
// This is pretty much the same as before. You just need to type more.
// Think about it this way:
// You've got the class of Vehicles
// You've got subclasses of Vehicle like Car, Bus, Tank.
// They've all got Motors. Those Motors are specific to them.
// So You declare them inside those classes.

class Vehicle {
	private:
		int mMaxSpeed;
		float mAcceleration;
	protected: 
		class Motor {
			protected:
				char* type;
			pubic:
				virtual void start() = 0;
				virtual void stop() = 0;
				virtual ~Motor() = 0;
		};
// After having declared the inner class fully, now I can use it for delcaring
// variables in this type.
		Motor* mMotor;
	public:
		virtual void goForward() = 0;
		virtual void stop() = 0;
		virtual void accelerate(float _acc) = 0;
		virtual ~Vehicle() = 0;
};

class Car : public Vehicle {
	protected:
		class Motor : public Vehicle::Motor {
			private:
				int mVolume;
			public:
				virtual void start();
				virtual void stop();
				virtual void ~Motor();			
		};
	public:
		virtual void goForward();
                virtual void stop();
                virtual void accelerate(float _acc);
                virtual ~Vehicle();
};


void Car::goForward() {
	// Code comes here...
}

void Car::Motor::start() {
	// Code comes here
}



// Now, to demonstrate this on a concept more familiar to You. 
// How would this help make a safely usable LinkedList?



class LinkedList {
	private:
// I have to have this before declaring the two pointer below it.
		class ListNode {
        		private:
                		double* mValue;
                		ListNode* mNext;
                		ListNode* mPrev;
        		public:
				void setPrev(ListNode* _node);

		};
// Declaring the pointers
                ListNode* mFirst;
                ListNode* mLast;
	public:


};

void LinkedList::ListNode::setPrev(LnkedList::ListNode* _node) {
	mPrev = _node;
}





#endif
