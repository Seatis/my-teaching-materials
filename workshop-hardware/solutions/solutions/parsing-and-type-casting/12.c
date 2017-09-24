#include <stdio.h>
#include <string.h>
int main ()
{
	char string[55] ="This is a string for testing";
	char *p;
	
	//TODO: write a program, which lists all position where character 'i' is found
	
	int k = 1;
	p = strchr (string,'i');
	while (p!=NULL) {
		printf ("Character i found at position %d\n", p-string+1);
		p=strchr(p+1,'i');
	}
	return 0;
}