#include <iostream>
#include <string>

namespace new_namespace1 {
	int gimmeANumber();
	int gimmeAnOther();	
};

namespace new_namespace2 {
	int gimmeANumber();
        int gimmeAnOther();
// Namespaces can be nested. This is a nice wayto categorize stuff that belongs together.
// Like the namespace std. It packages together everything in the STD Library.
	namespace asd {
		int gimmeANumber();
	};
};

int new_namespace1::gimmeANumber() {
	return 1;
}

int new_namespace2::gimmeANumber() {
        return 11;
}

int new_namespace1::gimmeAnOther() {
	return 2;
}

int new_namespace2::gimmeAnOther() {
        return 22;
}

int new_namespace2::asd::gimmeANumber() {
	return 333;
}

using namespace std;

int main() {
	cout << new_namespace1::gimmeANumber() << "   " << new_namespace2::gimmeANumber() << endl;
	cout << new_namespace2::gimmeAnOther() << "   " << new_namespace1::gimmeAnOther() << endl;
	cout << new_namespace2::asd::gimmeANumber() << endl;
	using namespace new_namespace1;
	cout << gimmeANumber() << "   " << new_namespace2::gimmeANumber() << endl;
}

