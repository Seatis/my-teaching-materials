#include <iostream>
#include <string>
using namespace std;

// Destructors: Why we use them, and how they work. Illustration.
// Check what the code does. Read, understand!
// Correct the code, so that the destructors work as intended. 
// i.e.: They clear up everything after themselves from the memory.


class ParentClass {
	private:
		string* mParentString;
	public:
		ParentClass();
		void setString(string _str);
		string getString();
		string* getStringAddress();
		virtual ~ParentClass();	
}; 

ParentClass::ParentClass() {
	mParentString = new string("parent string, stringing here!");
}

void ParentClass::setString(string _str) {
	string* tmp = mParentString;
	mParentString = new string(_str);
	delete tmp;
}

string ParentClass::getString() {
	return string(*mParentString);
}

string* ParentClass::getStringAddress() {
	return mParentString;
}

ParentClass::~ParentClass() {
}

class ChildClass : public ParentClass {
	private:
		string* mChildString;
	public:
		ChildClass();
		ChildClass(string _str);
		virtual ~ChildClass();
		string* getChildStringAddress();
};

string* ChildClass::getChildStringAddress() {
	return mChildString;
}

ChildClass::ChildClass() {
	mChildString = new string("Child String, it's getting late...");
}

ChildClass::ChildClass(string _str) {
	mChildString = new string(_str);
}

ChildClass::~ChildClass() {
}

int main() {
	ParentClass* a = new ChildClass();
	string* stra = a->getStringAddress();
	string* strb = ((ChildClass*)a)->getChildStringAddress();
	cout << *stra << endl << *strb << endl;
	delete a;
	cout << "a deleted: ----------------------------------------" << endl;
	cout << *stra << endl << *strb << endl;
}
