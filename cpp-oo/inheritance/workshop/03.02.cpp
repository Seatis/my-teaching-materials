#include <iostream>
#include <string>
using namespace std;

// EdgeCase #1.1 - protected variables, and even publics can be overriden as well. See for Yourself.

class ParentClass {
	protected:
		int mVariable;
	public:
		// Please note, that none of these are virtual. This will be important.
		void setVariable(int _var);
		ParentClass();
		int getVariable();
};

void ParentClass::setVariable(int _var) {
	this->mVariable = _var;
}

ParentClass::ParentClass() {
	this->mVariable = 0;
}

int ParentClass::getVariable() {
	return this->mVariable;
}

class ChildClass : public ParentClass {
	// Please note, that here I'm creating variables with the same name in
	// a descendant class. Which will also inherit the variable of the same
	// name from it's parent. Possibility of confusion ensues.
	protected:
		int mVariable;
	public:
		void setVariable(int _var);
		int getVariable();
		// These two methods are here to demonstrate how We can reach the 
		// variable of the same name from the parent class.
		int getParentVariable();
		void setParentVariable(int _var);
};

void ChildClass::setVariable(int _var) {
	this->mVariable = _var;
}

int ChildClass::getVariable() {
	return this->mVariable;
}

int ChildClass::getParentVariable() {
	return this->ParentClass::mVariable;
}

void ChildClass::setParentVariable(int _var) {
	this->ParentClass::mVariable = _var;
}

int main() {
	ParentClass* a = new ChildClass();
	cout << "Calling the method of the same name sets two different variables" << endl;
	cout << "if I call them on the same object, but once I look at it as ParentClass*" << endl;
	cout << "Once I look at it as ChildClass* after casting it so." << endl; 
	a->setVariable(2);
	((ChildClass*)a)->setVariable(4);
	cout << "Se the resulting variables for Yourself:" << endl;
	cout << a->getVariable() << "  " << ((ChildClass*)a)->getVariable() << endl;
	cout << "Now let's see how we can deal with them still by referencing them trough their original calsses namespace:" << endl;
	((ChildClass*)a)->setParentVariable(8);
	cout << a->getVariable() << "  " << ((ChildClass*)a)->getVariable() << endl;
	return 0;
}
