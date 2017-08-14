#include <stdio.h>
#include <string.h>

char is_anagram(char *str1, char *str2);

int main()
{
	char str1[] = "dog";
	char str2[] = "god";
	if (is_anagram(str1, str2))
		printf("The two strings are anagram of each other");
	else
		printf("The two strings are not anagram of each other");
	return 0;
}

char is_anagram(char *str1, char *str2)
{
	int str1_len = strlen(str1);
	int str2_len = strlen(str2);

	if (str1_len != str2_len)
		return 0;

	int i, j, tmp;
	for (i = 0; i < str1_len; i++) {
		for (j = i + 1; j < str1_len; j++) {
			if ( str1[i] > str1[j]) {
				tmp = str1[i];
				str1[i] = str1[j];
				str1[j] = tmp;
			}
		}
	}
	for (i = 0; i < str1_len; i++) {
		for (j = i + 1; j < str1_len; j++) {
			if ( str2[i] > str2[j]) {
				tmp = str2[i];
				str2[i] = str2[j];
				str2[j] = tmp;
			}
		}
	}

	for (i = 0; i < str1_len;  i++)
		if (str1[i] != str2[i])
			return 0;
	return 1;
}
