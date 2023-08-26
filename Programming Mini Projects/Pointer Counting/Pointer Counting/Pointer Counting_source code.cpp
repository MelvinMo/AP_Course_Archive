#include <stdio.h>
#include <iostream>
#include <string.h>
#include <ctype.h> 

using namespace std;
int main()
{
	int length = 0;
	int sdd = 0;
	int bsd = 0;
	int qsd = 0;
	char satz[101];
	char *ptr = satz;
	cin.getline(satz, 101);
	length = strlen(satz);
	for (; *ptr != '\0'; ptr++)
	{
		if (*ptr == 'a' || *ptr == 'A' || *ptr == 'i' || *ptr == 'I' || *ptr == 'o' || *ptr == 'O' || *ptr == 'u' || *ptr == 'U' || *ptr == 'e' || *ptr == 'E')
			sdd++;
		else if (*ptr == ' ')
			bsd++;
		else if (ispunct(*ptr))
			qsd++;
	}
	cout << sdd << '\n';
	cout << length - bsd - sdd - qsd << '\n';
	return 0;
}