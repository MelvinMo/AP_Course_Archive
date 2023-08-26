#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long int price_v(long long int ppsm, int cons_area, int yard_area)
{
	long long int price;
	price = (ppsm*cons_area) + (ppsm*yard_area*0.3);
	return price;
}

long long int price_a(long long int ppsm, int cons_area)
{
	long long int price;
	price = (ppsm*cons_area);
	return price;
}

struct villa
{
	int cons_area = 0;
	int yard_area = 0;
	long long int ppsm = 0;//price per square meter
	int floors_count = 0;
	char city[50];
	char street[50];
	char alley[50];
	long long int zipcode = 0;
	long long int price = 0;
}yourvilla[100] = { 0 }, temp_v = { 0 };

struct apartment
{
	int cons_area = 0;
	long long int ppsm = 0;//price per square meter
	int floor_num = 0;
	char lift[10];
	char city[50];
	char street[50];
	char alley[50];
	long long int zipcode = 0;
	long long int price = 0;
}yourapartment[100] = { 0 }, temp_a = { 0 };

struct sales
{
	char house_type[20];
	struct villa info_v;
	struct apartment info_a;
	long long int commission;
	char payment[20];
}yoursalecase[100] = { 0 };

int main()
{
	int vc = 0, ac = 0, sc = 0, pc = 0, counter_vc = 0, counter_ac = 0, counter_sc = 0, counter_pc = 0;
	int x = 0, q = 0, a = 0, o = 0, so = 0;
	long long int p = 0;
	char s_name[20];
	printf("*************************Welcome To Amirmahdi Mokhtari's Real Estate Agency!*************************\n\n");
repeat:
	printf("If you want to add new property or sale case to the database, Please press 1.\n");
	printf("If you want to see the properties' prices in an order, Please press 2.\n");
	printf("If you want to search the properties based on specific critiria, Please press 3.\n");
	printf("Or if you just want to surf the database, Please press 4.\n");
	printf("If you want to exit the program, Please press 5.\n");

	scanf("%d", &x);
	system("cls");
	if (x == 1)
	{
		int z = 0;
		printf("Please choose an option:\n");
		printf("1 for Villa / 2 for Apartment / 3 for Sale case\n");
		scanf("%d", &z);
		system("cls");
		if (z == 1)
		{
			printf("Now you're going to add new Villa to the database!\n\n\n");
			do
			{
				printf("What is constructable area of this property?\n");
				scanf("%d", &yourvilla[vc].cons_area);
				printf("What is yard area of this property?\n");
				scanf("%d", &yourvilla[vc].yard_area);
				printf("What is price per square meter of this property?\n");
				scanf("%lld", &yourvilla[vc].ppsm);
				printf("How many floors does this property have?\n");
				scanf("%d", &yourvilla[vc].floors_count);
				printf("Type the address of this property:\n");
				printf("What is the city?\n");
				scanf("%s", &yourvilla[vc].city);
				printf("What is the street?\n");
				scanf("%s", &yourvilla[vc].street);
				printf("What is the alley?\n");
				scanf("%s", &yourvilla[vc].alley);
				printf("What is the zipcode?\n");
				scanf("%lld", &yourvilla[vc].zipcode);
				yourvilla[vc].price = price_v(yourvilla[vc].ppsm, yourvilla[vc].cons_area, yourvilla[vc].yard_area);
				vc++;
				system("cls");
				printf("The property was added to the database successfuly!!!\n\n");
			} while (false);
			counter_vc = vc - 1;
		}
		else if (z == 2)
		{
			printf("Now you're going to add new Apartment to the database!\n\n\n");
			do
			{
				printf("What is constructable area of this property?\n");
				scanf("%d", &yourapartment[ac].cons_area);
				printf("What is price per square meter of this property?\n");
				scanf("%lld", &yourapartment[ac].ppsm);
				printf("What is this property's floor number?\n");
				scanf("%d", &yourapartment[ac].floor_num);
				printf("Does this apartment have lift? Yes/No\n");
				scanf("%s", &yourapartment[ac].lift);
				printf("Type the address of this property:\n");
				printf("What is the city?\n");
				scanf("%s", &yourapartment[ac].city);
				printf("What is the street?\n");
				scanf("%s", &yourapartment[ac].street);
				printf("What is the alley?\n");
				scanf("%s", &yourapartment[ac].alley);
				printf("What is the zipcode?\n");
				scanf("%lld", &yourapartment[ac].zipcode);
				yourapartment[ac].price = price_a(yourapartment[ac].ppsm, yourapartment[ac].cons_area);
				ac++;
				system("cls");
				printf("The property was added to the database successfuly!!!\n\n");
			} while (false);
			counter_ac = ac - 1;
		}
		else if (z == 3)
		{
			printf("Now you're going to add new Sale case to the database!\n\n\n");
			do
			{
				printf("Please define the type of this property.Is this a villa or an apartment?\n");
				scanf("%s", yoursalecase[sc].house_type);
				if (strcmp(yoursalecase[sc].house_type, "villa") == 0)
				{
					printf("What is constructable area of this property?\n");
					scanf("%d", &yoursalecase[sc].info_v.cons_area);
					printf("What is yard area of this property?\n");
					scanf("%d", &yoursalecase[sc].info_v.yard_area);
					printf("What is price per square meter of this property?\n");
					scanf("%lld", &yoursalecase[sc].info_v.ppsm);
					printf("How many floors does this property have?\n");
					scanf("%d", &yoursalecase[sc].info_v.floors_count);
					printf("Type the address of this property:\n");
					printf("What is the city?\n");
					scanf("%s", &yoursalecase[sc].info_v.city);
					printf("What is the street?\n");
					scanf("%s", &yoursalecase[sc].info_v.street);
					printf("What is the alley?\n");
					scanf("%s", &yoursalecase[sc].info_v.alley);
					printf("What is the zipcode?\n");
					scanf("%lld", &yoursalecase[sc].info_v.zipcode);
					printf("Manager!How much is your own commission?\n");
					scanf("%lld", &yoursalecase[sc].commission);
					printf("Which method of payment does this property have? Cash/Drafts\n");
					scanf("%s", &yoursalecase[sc].payment);
					sc++;
					system("cls");
					printf("The property was added to the database successfuly!!!\n\n");
				}
				else if (strcmp(yoursalecase[sc].house_type, "apartment") == 0)
				{
					printf("What is constructable area of this property?\n");
					scanf("%d", &yoursalecase[sc].info_a.cons_area);
					printf("What is price per square meter of this property?\n");
					scanf("%lld", &yoursalecase[sc].info_a.ppsm);
					printf("What is this property's floor number?\n");
					scanf("%d", &yoursalecase[sc].info_a.floor_num);
					printf("Does this apartment have lift? Yes/No\n");
					scanf("%s", &yoursalecase[sc].info_a.lift);
					printf("Type the address of this property:\n");
					printf("What is the city?\n");
					scanf("%s", &yoursalecase[sc].info_a.city);
					printf("What is the street?\n");
					scanf("%s", &yoursalecase[sc].info_a.street);
					printf("What is the alley?\n");
					scanf("%s", &yoursalecase[sc].info_a.alley);
					printf("What is the zipcode?\n");
					scanf("%lld", &yoursalecase[sc].info_a.zipcode);
					printf("Manager!How much is your own commission?\n");
					scanf("%lld", &yoursalecase[sc].commission);
					printf("Which method of payment does this property have? Cash/Drafts\n");
					scanf("%s", &yoursalecase[sc].payment);
					sc++;
					system("cls");
					printf("The property was added to the database successfuly!!!\n\n");
				}
				else
					printf("WRONG CHOICE!\n");
			} while (false);
			counter_sc = sc - 1;
		}
		else
			printf("WRONG CHOICE!\n");
		goto repeat;
	}
	if (x == 2)
	{
		printf("Now you're watching the list of properties based on their prices in an descending order!\n\n\n");
		counter_pc = counter_vc + counter_ac;
		if (counter_vc == 0 && vc == 0 && counter_ac == 0 && ac == 0)
		{
			printf("There is No Data on the database!\n");
			printf("Please fisrt add a property to the database then visit this section!\n\n\n");
		}
		else
		{
			if (!(counter_vc == 0 && vc == 0))
			{
				for (int i = 1; i <= counter_vc; i++)
					for (int j = 0; j <= counter_vc - i; j++)
					{
						if (yourvilla[j].price < yourvilla[j + 1].price)
						{
							temp_v = yourvilla[j];
							yourvilla[j] = yourvilla[j + 1];
							yourvilla[j + 1] = temp_v;
						}
					}
				for (vc = 0; vc <= counter_vc; vc++)
				{
					printf("**********************Villa Case**********************\n");
					printf("Constructable area of this property:\n");
					printf("%d\n", yourvilla[vc].cons_area);
					printf("Yard area of this property:\n");
					printf("%d\n", yourvilla[vc].yard_area);
					printf("Price per square meter of this property:\n");
					printf("%lld\n", yourvilla[vc].ppsm);
					printf("Number of floors this property has:\n");
					printf("%d\n", yourvilla[vc].floors_count);
					printf("The address of this property:\n");
					printf("The city:\n");
					printf("%s\n", yourvilla[vc].city);
					printf("The street:\n");
					printf("%s\n", yourvilla[vc].street);
					printf("The alley:\n");
					printf("%s\n", yourvilla[vc].alley);
					printf("The zipcode:\n");
					printf("%lld\n", yourvilla[vc].zipcode);
					printf("price of this property:\n");
					yourvilla[vc].price = price_v(yourvilla[vc].ppsm, yourvilla[vc].cons_area, yourvilla[vc].yard_area);
					printf("%lld\n\n\n", yourvilla[vc].price);
				}
			}
			if (!(counter_ac == 0 && ac == 0))
			{
				for (int i = 1; i <= counter_ac; i++)
					for (int j = 0; j <= counter_ac - i; j++)
					{
						if (yourapartment[j].price < yourapartment[j + 1].price)
						{
							temp_a = yourapartment[j];
							yourapartment[j] = yourapartment[j + 1];
							yourapartment[j + 1] = temp_a;
						}
					}
				for (ac = 0; ac <= counter_ac; ac++)
				{
					printf("**********************Apartment Case**********************\n");
					printf("Constructable area of this property:\n");
					printf("%d\n", yourapartment[ac].cons_area);
					printf("Price per square meter of this property:\n");
					printf("%lld\n", yourapartment[ac].ppsm);
					printf("Floor number:\n");
					printf("%d\n", yourapartment[ac].floor_num);
					printf("lift existence:\n");
					printf("%s\n", yourapartment[ac].lift);
					printf("The address of this property:\n");
					printf("The city:\n");
					printf("%s\n", yourapartment[ac].city);
					printf("The street:\n");
					printf("%s\n", yourapartment[ac].street);
					printf("The alley:\n");
					printf("%s\n", yourapartment[ac].alley);
					printf("The zipcode:\n");
					printf("%lld\n", yourapartment[ac].zipcode);
					printf("price of this property:\n");
					yourapartment[ac].price = price_a(yourapartment[ac].ppsm, yourapartment[ac].cons_area);
					printf("%lld\n\n\n", yourapartment[ac].price);
				}
			}
		}
		goto repeat;
	}
	if (x == 3)
	{
		printf("Now you're going to search the properties on the database!\n\n\n");
		if (counter_ac == 0 && ac == 0 && counter_vc == 0 && vc == 0)
		{
			printf("There is No Data on the database!\n");
			printf("Please fisrt add a property to the database then visit this section!\n\n\n");
		}
		else
		{
			printf("Please choose an option:\n");
			printf("1 to search in Villa cases / 2 to search in Apartment cases\n");
			scanf("%d", &o);
			system("cls");
			if (o == 1)
			{
				printf("Now you're going to search for Villa cases!\n\n\n");
				printf("Please choose an option:\n");
				printf("1 to search based on price and counstructable area / 2 to search base on street name\n");
				scanf("%d", &so);
				system("cls");
				if (so == 1)
				{
					printf("You're going to search the properties with the price less than x Dollars, Please define x:\n");
					scanf("%lld", &p);
					printf("And with constructable area more than y meters, Please define y:\n");
					scanf("%d", &a);
					system("cls");
					printf("So you're searching for properties with price less than %lld Dollars and constructable area more than %d meters:\n\n", p, a);
					for (vc = 0; vc <= counter_vc; vc++)
					{
						int flag = 0;
						if (yourvilla[vc].price < p && yourvilla[vc].cons_area > a)
						{
							printf("**********************Villa Case**********************\n");
							printf("Constructable area of this property:\n");
							printf("%d\n", yourvilla[vc].cons_area);
							printf("Yard area of this property:\n");
							printf("%d\n", yourvilla[vc].yard_area);
							printf("Price per square meter of this property:\n");
							printf("%lld\n", yourvilla[vc].ppsm);
							printf("Number of floors this property has:\n");
							printf("%d\n", yourvilla[vc].floors_count);
							printf("The address of this property:\n");
							printf("The city:\n");
							printf("%s\n", yourvilla[vc].city);
							printf("The street:\n");
							printf("%s\n", yourvilla[vc].street);
							printf("The alley:\n");
							printf("%s\n", yourvilla[vc].alley);
							printf("The zipcode:\n");
							printf("%lld\n", yourvilla[vc].zipcode);
							printf("price of this property:\n");
							yourvilla[vc].price = price_v(yourvilla[vc].ppsm, yourvilla[vc].cons_area, yourvilla[vc].yard_area);
							printf("%lld\n\n\n", yourvilla[vc].price);
							flag++;
						}
						else if (flag == 0)
						{
							printf("There is no property with these qualities!Please change your filters and then try again.\n\n");
						}
					}
				}
				else if (so == 2)
				{
					printf("You're going to search the properties with the same street name, Please define the street name:\n");
					scanf("%s", &s_name);
					system("cls");
					printf("So you're searching for properties on %s street:\n\n", s_name);
					for (vc = 0; vc <= counter_vc; vc++)
					{
						int flag = 0;
						if (strcmp(yourvilla[vc].street, s_name) == 0)
						{
							printf("**********************Villa Case**********************\n");
							printf("Constructable area of this property:\n");
							printf("%d\n", yourvilla[vc].cons_area);
							printf("Yard area of this property:\n");
							printf("%d\n", yourvilla[vc].yard_area);
							printf("Price per square meter of this property:\n");
							printf("%lld\n", yourvilla[vc].ppsm);
							printf("Number of floors this property has:\n");
							printf("%d\n", yourvilla[vc].floors_count);
							printf("The address of this property:\n");
							printf("The city:\n");
							printf("%s\n", yourvilla[vc].city);
							printf("The street:\n");
							printf("%s\n", yourvilla[vc].street);
							printf("The alley:\n");
							printf("%s\n", yourvilla[vc].alley);
							printf("The zipcode:\n");
							printf("%lld\n", yourvilla[vc].zipcode);
							printf("price of this property:\n");
							yourvilla[vc].price = price_v(yourvilla[vc].ppsm, yourvilla[vc].cons_area, yourvilla[vc].yard_area);
							printf("%lld\n\n\n", yourvilla[vc].price);
							flag++;
						}
						else if (flag == 0)
						{
							printf("There is no property with these qualities!Please change your filters and then try again.\n\n");
							goto repeat;
						}
					}
				}
				else
				{
					printf("WRONG CHOICE!\n");
					goto repeat;
				}
				goto repeat;
			}
			else if (o == 2)
			{
				printf("Now you're going to search for Apartment cases!\n\n\n");
				printf("Please choose an option:\n");
				printf("1 to search based on price and counstructable area / 2 to search base on street name\n");
				scanf("%d", &so);
				system("cls");
				if (so == 1)
				{
					printf("You're going to search the properties with the price less than x Dollars, Please define x:\n");
					scanf("%lld", &p);
					printf("And with constructable area more than y meters, Please define y:\n");
					scanf("%d", &a);
					system("cls");
					printf("So you're searching for properties with price less than %lld Dollars and constructable area more than %d meters:\n\n", p, a);
					for (ac = 0; ac <= counter_ac; ac++)
					{
						int flag = 0;
						if (yourapartment[ac].price < p && yourapartment[ac].cons_area > a)
						{
							printf("**********************Apartment Case**********************\n");
							printf("Constructable area of this property:\n");
							printf("%d\n", yourapartment[ac].cons_area);
							printf("Price per square meter of this property:\n");
							printf("%lld\n", yourapartment[ac].ppsm);
							printf("Floor number:\n");
							printf("%d\n", yourapartment[ac].floor_num);
							printf("lift existence:\n");
							printf("%s\n", yourapartment[ac].lift);
							printf("The address of this property:\n");
							printf("The city:\n");
							printf("%s\n", yourapartment[ac].city);
							printf("The street:\n");
							printf("%s\n", yourapartment[ac].street);
							printf("The alley:\n");
							printf("%s\n", yourapartment[ac].alley);
							printf("The zipcode:\n");
							printf("%lld\n", yourapartment[ac].zipcode);
							printf("price of this property:\n");
							yourapartment[ac].price = price_a(yourapartment[ac].ppsm, yourapartment[ac].cons_area);
							printf("%lld\n\n\n", yourapartment[ac].price);
							flag++;
						}
						else if (flag == 0)
						{
							printf("There is no property with these qualities!Please change your filters and then try again.\n\n");
						}
					}
				}
				else if (so == 2)
				{
					printf("You're going to search the properties with the same street name, Please define the street name:\n");
					scanf("%s", &s_name);
					system("cls");
					printf("So you're searching for properties on %s street:\n\n", s_name);
					for (ac = 0; ac <= counter_ac; ac++)
					{
						int flag = 0;
						if (strcmp(yourapartment[ac].street, s_name) == 0)
						{
							printf("**********************Apartment Case**********************\n");
							printf("Constructable area of this property:\n");
							printf("%d\n", yourapartment[ac].cons_area);
							printf("Price per square meter of this property:\n");
							printf("%lld\n", yourapartment[ac].ppsm);
							printf("Floor number:\n");
							printf("%d\n", yourapartment[ac].floor_num);
							printf("lift existence:\n");
							printf("%s\n", yourapartment[ac].lift);
							printf("The address of this property:\n");
							printf("The city:\n");
							printf("%s\n", yourapartment[ac].city);
							printf("The street:\n");
			    			printf("%s\n", yourapartment[ac].street);
							printf("The alley:\n");
							printf("%s\n", yourapartment[ac].alley);
							printf("The zipcode:\n");
							printf("%lld\n", yourapartment[ac].zipcode);
							printf("price of this property:\n");
							yourapartment[ac].price = price_a(yourapartment[ac].ppsm, yourapartment[ac].cons_area);
							printf("%lld\n\n\n", yourapartment[ac].price);
							flag++;
						}
						else if (flag == 0)
						{
							printf("There is no property with these qualities!Please change your filters and then try again.\n\n");
						}
					}
				}
				else
				{
					printf("WRONG CHOICE!\n");
					goto repeat;
				}
				goto repeat;
			}
			else
			{
				printf("WRONG CHOICE!\n");
				goto repeat;
			}
		}
	}
	if (x == 4)
	{
	printf("Now you're watching all the properties in the database!\n\n\n");
	printf("Please choose an option:\n");
	printf("1 for Villa / 2 for Apartment / 3 for Sale case\n");
	scanf("%d", &q);
	system("cls");
	if (q == 1)
	{
		printf("Now you're watching all Villas cases in the database!\n\n\n");
		if (counter_vc == 0 && vc == 0)
		{
			printf("There is No Data on the database!\n");
			printf("Please fisrt add a property to the database then visit this section!\n\n\n");
		}
		else
		{
			for (vc = 0; vc <= counter_vc; vc++)
			{
				printf("********************Case %d out of %d Cases********************\n\n\n", vc + 1, counter_vc + 1);
				printf("Constructable area of this property:\n");
				printf("%d\n", yourvilla[vc].cons_area);
				printf("Yard area of this property:\n");
				printf("%d\n", yourvilla[vc].yard_area);
				printf("Price per square meter of this property:\n");
				printf("%lld\n", yourvilla[vc].ppsm);
				printf("Number of floors this property has:\n");
				printf("%d\n", yourvilla[vc].floors_count);
				printf("The address of this property:\n");
				printf("The city:\n");
				printf("%s\n", yourvilla[vc].city);
				printf("The street:\n");
				printf("%s\n", yourvilla[vc].street);
				printf("The alley:\n");
				printf("%s\n", yourvilla[vc].alley);
				printf("The zipcode:\n");
				printf("%lld\n", yourvilla[vc].zipcode);
				printf("price of this property:\n");
				yourvilla[vc].price = price_v(yourvilla[vc].ppsm, yourvilla[vc].cons_area, yourvilla[vc].yard_area);
				printf("%lld\n\n\n", yourvilla[vc].price);
			}
		}
		goto repeat;
	}
	if (q == 2)
	{
		printf("Now you're watching all Apartments cases in the database!\n\n\n");
		if (counter_ac == 0 && ac == 0)
		{
			printf("There is No Data on the database!\n");
			printf("Please fisrt add a property to the database then visit this section!\n\n\n");
		}
		else
		{
			for (ac = 0; ac <= counter_ac; ac++)
			{
				printf("********************Case %d out of %d Cases********************\n\n\n", ac + 1, counter_ac + 1);
				printf("Constructable area of this property:\n");
				printf("%d\n", yourapartment[ac].cons_area);
				printf("Price per square meter of this property:\n");
				printf("%lld\n", yourapartment[ac].ppsm);
				printf("Floor number:\n");
				printf("%d\n", yourapartment[ac].floor_num);
				printf("lift existence:\n");
				printf("%s\n", yourapartment[ac].lift);
				printf("The address of this property:\n");
				printf("The city:\n");
				printf("%s\n", yourapartment[ac].city);
				printf("The street:\n");
				printf("%s\n", yourapartment[ac].street);
				printf("The alley:\n");
				printf("%s\n", yourapartment[ac].alley);
				printf("The zipcode:\n");
				printf("%lld\n", yourapartment[ac].zipcode);
				printf("price of this property:\n");
				yourapartment[ac].price = price_a(yourapartment[ac].ppsm, yourapartment[ac].cons_area);
				printf("%lld\n\n\n", yourapartment[ac].price);
			}
		}
		goto repeat;
	}
	if (q == 3)
	{
		printf("Now you're watching all Sale cases in the database!\n\n\n");
		if (counter_sc == 0 && sc == 0)
		{
			printf("There is No Data on the database!\n");
			printf("Please fisrt add a property to the database then visit this section!\n\n\n");
		}
		else
		{
			for (sc = 0; sc <= counter_sc; sc++)
			{
				if (yoursalecase[sc].info_a.cons_area == 0)
				{

					printf("We do not have Apartments cases!\n\n");
					printf("************************Villa Cases**************************\n");
					printf("Constructable area of this property:\n");
					printf("%d\n", yoursalecase[sc].info_v.cons_area);
					printf("Yard area of this property:\n");
					printf("%d\n", yoursalecase[sc].info_v.yard_area);
					printf("Price per square meter of this property:\n");
					printf("%lld\n", yoursalecase[sc].info_v.ppsm);
					printf("Number of floors this property has:\n");
					printf("%d\n", yoursalecase[sc].info_v.floors_count);
					printf("The address of this property:\n");
					printf("The city:\n");
					printf("%s\n", yoursalecase[sc].info_v.city);
					printf("The street:\n");
					printf("%s\n", yoursalecase[sc].info_v.street);
					printf("The alley:\n");
					printf("%s\n", yoursalecase[sc].info_v.alley);
					printf("The zipcode:\n");
					printf("%lld\n", yoursalecase[sc].info_v.zipcode);
					printf("price of this property:\n");
					printf("%lld\n", yoursalecase[sc].info_v.price);
					printf("Manager's commission:\n");
					printf("%lld\n", yoursalecase[sc].commission);
					printf("Method of payment:\n");
					printf("%s\n\n\n", yoursalecase[sc].payment);
				}
				else if (yoursalecase[sc].info_v.cons_area == 0)
				{

					printf("We do not have Villas cases!\n\n");
					printf("**********************Apartment Cases************************\n");
					printf("Constructable area of this property:\n");
					printf("%d\n", yoursalecase[sc].info_a.cons_area);
					printf("Price per square meter of this property:\n");
					printf("%lld\n", yoursalecase[sc].info_a.ppsm);
					printf("Floor number:\n");
					printf("%d\n", yoursalecase[sc].info_a.floor_num);
					printf("lift existence:\n");
					printf("%s\n", yoursalecase[sc].info_a.lift);
					printf("The address of this property:\n");
					printf("The city:\n");
					printf("%s\n", yoursalecase[sc].info_a.city);
					printf("The street:\n");
					printf("%s\n", yoursalecase[sc].info_a.street);
					printf("The alley:\n");
					printf("%s\n", yoursalecase[sc].info_a.alley);
					printf("The zipcode:\n");
					printf("%lld\n", yoursalecase[sc].info_a.zipcode);
					printf("price of this property:\n");
					printf("%lld\n", yoursalecase[sc].info_a.price);
					printf("Manager's commission:\n");
					printf("%lld\n", yoursalecase[sc].commission);
					printf("Method of payment:\n");
					printf("%s\n\n\n", yoursalecase[sc].payment);
				}
				else
				{

					printf("************************Villa Cases**************************\n");
					printf("Constructable area of this property:\n");
					printf("%d\n", yoursalecase[sc].info_v.cons_area);
					printf("Yard area of this property:\n");
					printf("%d\n", yoursalecase[sc].info_v.yard_area);
					printf("Price per square meter of this property:\n");
					printf("%lld\n", yoursalecase[sc].info_v.ppsm);
					printf("Number of floors this property has:\n");
					printf("%d\n", yoursalecase[sc].info_v.floors_count);
					printf("The address of this property:\n");
					printf("The city:\n");
					printf("%s\n", yoursalecase[sc].info_v.city);
					printf("The street:\n");
					printf("%s\n", yoursalecase[sc].info_v.street);
					printf("The alley:\n");
					printf("%s\n", yoursalecase[sc].info_v.alley);
					printf("The zipcode:\n");
					printf("%lld\n", yoursalecase[sc].info_v.zipcode);
					printf("price of this property:\n");
					printf("%lld\n", yoursalecase[sc].info_v.price);
					printf("Manager's commission:\n");
					printf("%lld\n", yoursalecase[sc].commission);
					printf("Method of payment:\n");
					printf("%s\n\n\n", yoursalecase[sc].payment);
					printf("**********************Apartment Cases************************\n");
					printf("Constructable area of this property:\n");
					printf("%d\n", yoursalecase[sc].info_a.cons_area);
					printf("Price per square meter of this property:\n");
					printf("%lld\n", yoursalecase[sc].info_a.ppsm);
					printf("Floor number:\n");
					printf("%d\n", yoursalecase[sc].info_a.floor_num);
					printf("lift existence:\n");
					printf("%s\n", yoursalecase[sc].info_a.lift);
					printf("The address of this property:\n");
					printf("The city:\n");
					printf("%s\n", yoursalecase[sc].info_a.city);
					printf("The street:\n");
					printf("%s\n", yoursalecase[sc].info_a.street);
					printf("The alley:\n");
					printf("%s\n", yoursalecase[sc].info_a.alley);
					printf("The zipcode:\n");
					printf("%lld\n", yoursalecase[sc].info_a.zipcode);
					printf("price of this property:\n");
					printf("%lld\n", yoursalecase[sc].info_a.price);
					printf("Manager's commission:\n");
					printf("%lld\n", yoursalecase[sc].commission);
					printf("Method of payment:\n");
					printf("%s\n\n\n", yoursalecase[sc].payment);
				}
			}
		}
		goto repeat;
	}
	else
	{
		printf("WRONG CHOICE!\n");
		goto repeat;
	}	
	}
	if (x == 5)
	{
		return 0;
	}
	else
	{
		printf("WRONG CHOICE!\n");
		goto repeat;
	}
	return 0;
}