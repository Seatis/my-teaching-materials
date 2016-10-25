#include <iostream>
using namespace std;

//Divides two floating point numbers
float divide(float a, float b);
//Creates the reciproc of a floating point value
float reciproc(float a);


int main(int argc, char** argv){
	//Implement the functions declared above.
	//Maybe You can use one function in the implementation of an other one...

	cout << "Dividing 1 by 4: " << divide(1, 4) << endl;
	cout << "Dividign 1.0 by 5.0: " << divide(1.0, 5.0) << endl;
	cout << "The repciproc of 6 is: " << reciproc(6) << endl;

	return 0;
}
