#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Rational
{
	int a;
	int b;
}rat1, rat2, result;

void get (Rational *i)
{
	scanf("%d%d", &i->a, &i->b);
}

void print(Rational o)
{
	printf("%d/%d\n", o.a, o.b);
}

void simplify(Rational *q)
{
	int i, gcd;
	for (i = 1; i <= q->a && i <= q->b; ++i)
	{
		if (q->a%i == 0 && q->b%i == 0)
			gcd = i;
	}
	q->a = q->a / gcd;
	q->b = q->b / gcd;
}

Rational add(Rational q1, Rational q2)
{
	result.a = (q1.a)*(q2.b) + (q1.b)*(q2.a);
	result.b = (q1.b)*(q2.b);
	simplify(&result);
	print(result);
	return result;
}

Rational subtract(Rational q1, Rational q2)
{
	result.a = (q1.a)*(q2.b) - (q1.b)*(q2.a);
	result.b = (q1.b)*(q2.b);
	simplify(&result);
	print(result);
	return result;
}

Rational multiply(Rational q1, Rational q2)
{
	result.a = (q1.a)*(q2.a);
	result.b = (q1.b)*(q2.b);
	simplify(&result);
	print(result);
	return result;
}

Rational division(Rational q1, Rational q2)
{
	result.a = (q1.a)*(q2.b);
	result.b = (q1.b)*(q2.a);
	simplify(&result);
	print(result);
	return result;
}

int main()
{
	char letter_a[2], letter_b[2], operation[5], useroperation_1[5], useroperation_2[5], addition[5], subtraction[5], multiplication[5], spliting[5];
	int flag = 0;
	do
	{
		scanf("%s", &operation);
		if (strcmp(operation, "new") == 0)
		{
			if (flag == 0)
			{
				scanf("%s", &letter_a);
				get(&rat1);
				flag++;
			}
			else
			{
				scanf("%s", &letter_b);
				get(&rat2);
				strcpy(useroperation_1, letter_a);
				strcpy(useroperation_2, letter_b);
				strcat(useroperation_1, "+");
				strcat(useroperation_1, useroperation_2);
				strcpy(addition, useroperation_1);
				memset(useroperation_1, 0, 5);
				memset(useroperation_2, 0, 5);
				strcpy(useroperation_1, letter_a);
				strcpy(useroperation_2, letter_b);
				strcat(useroperation_1, "-");
				strcat(useroperation_1, useroperation_2);
				strcpy(subtraction, useroperation_1);
				memset(useroperation_1, 0, 5);
				memset(useroperation_2, 0, 5);
				strcpy(useroperation_1, letter_a);
				strcpy(useroperation_2, letter_b);
				strcat(useroperation_1, "*");
				strcat(useroperation_1, useroperation_2);
				strcpy(multiplication, useroperation_1);
				memset(useroperation_1, 0, 5);
				memset(useroperation_2, 0, 5);
				strcpy(useroperation_1, letter_a);
				strcpy(useroperation_2, letter_b);
				strcat(useroperation_1, "/");
				strcat(useroperation_1, useroperation_2);
				strcpy(spliting, useroperation_1);
			}
		}
		else if (strcmp(operation, addition) == 0)
			add(rat1, rat2);
		else if (strcmp(operation, subtraction) == 0)
			subtract(rat1, rat2);
		else if (strcmp(operation, multiplication) == 0)
			multiply(rat1, rat2);
		else if (strcmp(operation, spliting) == 0)
			division(rat1, rat2);
		else if (strcmp(operation, letter_a) == 0)
			print(rat1);
		else if (strcmp(operation, letter_b) == 0)
			print(rat2);
	} while (strcmp(operation, "end") != 0);
	return 0;
}