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
		void unsafeSetString(string _str);
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

// This is only here to illustrate the effects of improper memory handling.
void ParentClass::unsafeSetString(string _str) {
	mParentString = new string(_str);
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

// This is only here to demonstrate possible effects of improper encaspulation.
// How it can spoil You're porgram if You don't pay attention who can access 
// Your pointers and how.
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
	cout << "You have two different strings. As illustrated below" << endl;
	cout << *stra << endl << *strb << endl;
	
	// This should illustrate, how a memory leak works.
	// If You set this with the unsafe set method. It lingers in hte memory.
	a->unsafeSetString("muhahhhahaaaaaa");
	cout << endl << "The old string is still in the memory when the new is set unsafely" << endl;
	cout << "See them both below: " << endl;
	cout << *stra << endl << a->getString()<<endl;	
	
	stra = a->getStringAddress();
	delete a;
	cout << "a deleted: -- And yet, there is a good chance Your string is " << endl;
	cout << "Still in memory if You didn't do Your ~destructor right. Let's see!" << endl;
	// You're solution will be good when on Windows You get a "segfault". 
	// Then You need to comment out the next line.
	cout << *stra << endl;
}
