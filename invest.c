//Author: Nathan Peereboom
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int years;
	float return_rate;
	float added_contr;
	float current_balance;
	bool accept_init = false;
	bool accept_years = false;
	bool accept_rate = false;
	bool accept_contr = false;

	//Ask for user input
	do
	{
		printf("Enter initial investment amount: ");
		scanf("%f", &current_balance);
		if (current_balance >= 0) accept_init = true;
		else printf("Inital investment cannot be negative.\n");
	} while (!accept_init);
	do
	{
		printf("Enter total years: ");
		scanf("%d", &years);
		if (years > 0) accept_years = true;
		else printf("Years must be greater than zero.\n");
	} while (!accept_years);
	do
	{
		printf("Enter return rate: ");
		scanf("%f", &return_rate);
		if (return_rate >= 0) accept_rate = true;
		else printf("Rate cannot be negative.\n");
	} while (!accept_rate);
	return_rate = return_rate / 100;
	do
	{
		printf("Enter additional contribution per year: ");
		scanf("%f", &added_contr);
		if (added_contr >= 0) accept_contr = true;
		else printf("Contribution cannot be negative.\n");
	} while (!accept_contr);

	//Print table
	printf("\nYear      Start Balance       Interest            End Balance");
	printf("\n***********************************************************************");
	for (int i = 1; i <= years; i++)
	{
		if (i > 1) current_balance += added_contr;
		float start_balance = current_balance;
		float interest = (start_balance * return_rate);
		float end_balance = start_balance + interest;
		printf("\n%-10d%-20.2f%-20.2f%-20.2f", i, start_balance, interest, end_balance);
		current_balance = end_balance;
	}

	printf("\n");
    return 0;
}
