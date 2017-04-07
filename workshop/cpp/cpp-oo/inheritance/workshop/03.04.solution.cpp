#include <iostream>
#include <string>
using namespace std;

class ParentClass {
	private:
	public:
		string getNonVirtualText();
		virtual string getVirtualText();

};

string ParentClass::getNonVirtualText() {
	return string("Non-Virtual ParentClass here.");
}

string ParentClass::getVirtualText() {
	return string("Virtual ParentClass String");
}

class ChildClass : public ParentClass {
	private:
	public:
		string getNonVirtualText();
		virtual string getVirtualText();
};

string ChildClass::getNonVirtualText() {
	return string("Non Virtual ChildClass");
}

string ChildClass::getVirtualText() {
	return string("Vritual ChildClass Stringing hereeeeeeeee....");
}

int main() {
	ParentClass* a = new ChildClass();
	cout << "As ParentClass:  " << a->getNonVirtualText() << "   ||   " << a->getVirtualText() << endl;
	cout << "As Child Class:  " << ((ChildClass*)a)->getNonVirtualText() << "   ||   " <<((ChildClass*)a)->getVirtualText() << endl;
	return 0;
};
