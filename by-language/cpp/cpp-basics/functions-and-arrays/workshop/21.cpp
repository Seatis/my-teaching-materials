#include <iostream>
using namespace std;

void alphabetSlicer(char beginner, char array[6]);

//Implement the above declared function to return the next 5 characters in the english alphabet 
//after the character 'beginner' in an array of characters. 
//The last chracter of the array should be '\0'. 
//If there are less then 5 characters left after 'beginner' start from the beginning.
//So, alphabetSlicer(y) should return {'z','a','b','c','d','\0'}

int main(int argc, char** argv){
	char arr[6];
	alphabetSlicer('d', arr); 
	cout << arr << endl;
	alphabetSlicer('w', arr); 
	cout << arr << endl;

	return 0;
}
