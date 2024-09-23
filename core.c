/*******************************************************
 * Pouya Shakiba
 * Pooya.shakiba5@gmail.com
 * https://github.com/pouyashakiba
 * 2024/09/23
 *******************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "core.h"
#include "clinic.h"
//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
	printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}
void  displayFormattedPhone(const char* number)
{
	int valid = 1, i, counter = 0;
	if (number == NULL) {
		valid = 0;
	}
	else {
		for (i = 0; number[i] != '\0' && valid; i++)
		{
			valid = 0;
			switch (number[i])
			{
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
				valid = 1;
				counter++;
				break;
			}
		}
	}


	if (counter == 10 && valid)
	{
		printf("(%c%c%c)%c%c%c-%c%c%c%c", number[0], number[1], number[2],
			number[3], number[4], number[5], number[6],
			number[7], number[8], number[9]);
	}
	else {
		printf("(___)___-____");
	}
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//
int inputInt(void)
{
	int value;
	char newLine = 'x';

	while (newLine != '\n') {
		scanf("%d%c", &value, &newLine);
		if (newLine != '\n') {
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}
	}
	return value;
}
int inputIntPositive()
{
	int value, valid = 0;

	while (!valid) {

		value = inputInt();
		if (value < 1)
		{
			printf("ERROR! Value must be > 0: ");
		}
		else
		{
			valid = 1;
		}
	}
	return value;
}
int inputIntRange(int min, int max)
{
	int value, valid = 0;

	while (!valid) {
		value = inputInt();
		if (value < min || value > max)
		{
			printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
		}
		else
		{
			valid = 1;
		}
	}
	return value;
}
char inputCharOption(const char car[])

{
	char input[10] = "";
	int i, valid = 0;
	while (!valid)
	{

		scanf("%s", input);
		if (strlen(input)==1)
		{
			for (i = 0; car[i] != '\0' && !valid; i++)
			{
				if (car[i] == input[0])
				{
					valid = 1;
				}
			}
		}
		if (!valid)
		{
			printf("ERROR: Character must be one of [");
			printf("%s", car);
			printf("]: ");
		}
	}
	return input[0];
}
void inputCString(char* string, int min, int max)
{
	int counter, valid = 0, i = 0;
	char temp[100];

	while (!valid)
	{

		scanf("%[^\n]", temp);
		counter = 0;
		for (i = 0; temp[i] != '\0'; i++)
		{
			counter++;
		}
		if (min != max)
		{
			if (counter > min - 1 && counter < max + 1)
			{
				valid = 1;
			}
			else if (counter < min)
			{
				printf("ERROR: String length must be between %d and %d chars: ", min, max);
			}
			else if (counter > max)
			{
				printf("ERROR: String length must be no more than %d chars: ", max);
			}

		}
		else if (counter > min - 1 && counter < max + 1)
		{
			if (counter == min)
			{
				valid = 1;
			}
		}
		else
		{
			printf("Invalid 10-digit number! Number: ");
		}

		clearInputBuffer();
	}
	
	for (i = 0; string[i] != '\0'; i++) {
		string[i] = ' ';
	}
	for (i = 0; temp[i] != '\0'; i++)
	{
		string[i] = temp[i];
	}
	string[i]='\0';
}




