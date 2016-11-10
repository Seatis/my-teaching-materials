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


// First, we declare the nems of the classes we will use. This is not necesarily 
// needed. But we can not have a pointer or reference before we have declared that
// such a class will exist.
class LinkedList;
class LinkedList::ListNode;

class LinkedList {
	private:
// I can have these here, because I've declared before that I'll have the class
// LinkedList::ListNode...
		ListNode* mFirst;
		ListNode* mLast;
// Otherwise I'd have to have this before declaring the two pointer above.
		class ListNode {
        		private:
                		double* mValue;
                		ListNode* mNext;
                		ListNode* mPrev;
        		public:
				void setPrev(ListNode* _node);

		};
	public:


};

void LinkedList::ListNode::setPrev(LnkedList::ListNode* _node) {
	mPrev = _node;
}





#endif
