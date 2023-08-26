#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct staff
{
	char name[21];
	char id[5];
	char raiting[2];
}yourstaffs[100];

struct team_member
{
	char idnum[5];
	char raiting[2];
}tm_mbr[100];

int main()
{
	int n_staffs = 0, n_teams = 0, n_raitings = 0, flag = 1;
	int numberofmembersofagroup = n_staffs / n_teams;
	char t_raitings[30];
	scanf("%d", &n_staffs);
	for (int i = 0; i < n_staffs; i++)
		scanf("%s %s %s", &yourstaffs[i].name, &yourstaffs[i].id, &yourstaffs[i].raiting);
	scanf("%d", &n_teams);
	scanf("%d", &n_raitings);
	for (int j = 0; j < n_raitings; j++)
		scanf("%s", &t_raitings[j]);
	if (numberofmembersofagroup>11)
	{
		printf("impossible\n");
		return 0;
	}
	if (n_staffs / n_teams != 0)
	{
		printf("impossible\n");
		return 0;
	}
	for (int i = 0; i < n_staffs - 1; i++)
		for (int j = 0; j < n_staffs - i - 1; j++)
			if (strcmp(yourstaffs[j].raiting, yourstaffs[j + 1].raiting) == 0)
				flag++;
	if (flag / n_raitings != 0)
	{
		printf("impossible");
		return 0;
	}
	for (int i = 0; i < n_staffs - 1; i++)
		for (int j = 0; j < n_staffs - i - 1; j++)
		{
			printf("%s\n", yourstaffs[j].id);
			if (!(strcmp(yourstaffs[j].raiting, yourstaffs[j + numberofmembersofagroup].raiting) == 0))
			{
				printf("%s\n", yourstaffs[j + numberofmembersofagroup].id);
			}
		}
	for (int h = 0; h < n_staffs; h++)
		for (int l = 0; l < n_staffs - 1; (l++)*numberofmembersofagroup)
		{
			strcpy(yourstaffs[h].id, tm_mbr[l].idnum);
		}
	for (int h = 0; h < n_staffs; h++)
		for (int l = 0; l < n_staffs - 1; (l++)*(numberofmembersofagroup - 1))
		{
			if (strcmp(yourstaffs[h].raiting, tm_mbr[l].raiting))
				strcpy(yourstaffs[h].id, tm_mbr[l].idnum);
		}
}