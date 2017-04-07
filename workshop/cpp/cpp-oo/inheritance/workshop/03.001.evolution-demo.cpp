#include <iostream>


// Long long time ago, in a Galaxy far far away...
// Someone decided that it would be nice to have a structure
// For values that belong together.
// Thus they created the keyword "struct" 
struct Tuple {
	int a;
	int b;
};

// First they started out with creating functions that just received
// a pointer to the given struct in order to do something with it.
void tuple_swap(Tuple* _tup) {
	int tmp = _tup->a;
	_tup->a = _tup->b;
	_tup->b = tmp;
}

struct FloatTuple {
	float a;
	float b;
};

void float_tuple_swap(FloatTuple& _tup) {
	float tmp = _tup.a;
	_tup.a = _tup.b;
	_tup.b = tmp;
}

// As they created similar structures and new functions to operate on each,
// The wise coders of ancient times noticed that they needed to write too 
// darned much. And long function names are hard to read, hard to spell.
// In their infinite wisdom - and lzyness - they created namespaces.
// In different namespaces they could use the same name again and again.
// Namespaces were a new category, a new hierarchical element. A new distinction.
// This merited some new notations to make their code more legible.

namespace Float {
	struct Tuple {
		float a;
		float b;
	};
	void swap(Tuple& _tup);
};

// They started denoting what was inside a namespace with '::' when referenced from
// outisde of it. This way it was easily distinguishable.

void Float::swap(Float::Tuple& _tup) {
	float tmp = _tup.a;
        _tup.a = _tup.b;
        _tup.b = tmp;
}

// Later they realized that what they had wrapped into a namespace are a data structure
// And functions that operate on it. These belong together.
// Thus the new unit was born. Hail the concept of CLASS!
// Classes have data elements and methods operating on them.
// They can also control who can access which data element and which method.
// The notation got simplified to make code even more legible.
// But the concept of namespaces remains in a new form. Each class is it's own namespace.
// Though we don't usually refer to it by that.
// This basically means that I can name a variable or method in a name in a class,
// And use the same name in a different class. C++ will know which one to look for
// based on the type (class) of the object I'm working with.
// As a side effect this can be used even within the same inheritance hierarchy.
// This is a really easy way to make things confusing. You can see some examples
// Of this in 03.01, 03.02 and 03.03. Play around with them until 
// You understand what's going on.

class DoubleTuple {
	private:
		double mFirst;
		double mSecond;
	public:
		void swap();
		void add(DoubleTuple* _other);
};

// See how functions worked before. They all received a pointer to the data structure.
// Now they automatically receive a pointer called "this". 
// This is of historical relevance. And it's also practical, to have a similar
// strucurte and look and feel in Your code.
// You can omit using it though. As You can see it in the swap method below.

void DoubleTuple::add(DoubleTuple* _other) {
	this->mFirst += _other->mFirst;
	this->mSecond += _other->mSecond;
}


void DoubleTuple::swap() {
	double tmp = this->mFirst;
	double tmb = mFirst;
}


// Write setter and getter functions for DoubleTuple and try it out in the main()
// function below.

int main() {
	Float::Tuple a = Float::Tuple();
	a.a = 1.23;
	a.b = 1.42;
	std::cout << a.a << "  " << a.b << std::endl;
	Float::swap(a);
	std::cout << a.a << "  " << a.b << std::endl; 

	DoubleTuple dt = DoubleTuple();
	return 0;
}
