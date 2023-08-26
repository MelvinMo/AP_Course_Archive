#include <stdio.h>
#include <stdlib.h>

void writeToFile();
void readFromFile();

struct customer {
	int id;
	char name[150];
	unsigned long int balance;
}p[100];

FILE *fptr;

int main()
{
	int number;
	printf("Enter number of customers:");
	scanf("%d", &number);
	writeToFile();
	readFromFile();
	return 0;
}

void writeToFile()
{
	fptr = fopen("customers.bin", "wb");
	int j = 0,i = 0;
	printf("If you want to continue press 1 or if you want to exit press ctrl+z\n");
	while (scanf("%d", &j) != EOF)
	{
		printf("Enter id:\n ");
		scanf("%d", &p[i].id);
		printf("Enter name:\n ");
		scanf("%s", &p[i].name);
		printf("Enter balance:\n ");
		scanf("%lu", &p[i].balance);
		fprintf(fptr, "%d%s%lu", p[i].id, p[i].name, p[i].balance);
		fclose(fptr);
		i++;
	}
}

void readFromFile()
{
	if ((fptr = fopen("customer.bin", "rb")) == NULL)
	{
		printf("Error in opening file!");
	}
	else
	{
		int i = 0;
		while (true)
		{
			fscanf(fptr, "%d%s%lu", p[i].id, p[i].name, p[i].balance);
			printf("%d%s%lu", p[i].id, p[i].name, p[i].balance);
			fclose(fptr);
			i++;
		}
	}
}
