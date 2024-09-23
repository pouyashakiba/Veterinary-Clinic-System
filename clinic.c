/*******************************************************
 * Pouya Shakiba
 * Pooya.shakiba5@gmail.com
 * https://github.com/pouyashakiba
 * 2024/09/23
 *******************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
	printf("Pat.# Name            Phone#\n"
		"----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
	if (fmt == FMT_FORM)
	{
		printf("Name  : %s\n"
			"Number: %05d\n"
			"Phone : ", patient->name, patient->patientNumber);
		displayFormattedPhone(patient->phone.number);
		printf(" (%s)\n", patient->phone.description);
	}
	else
	{
		printf("%05d %-15s ", patient->patientNumber,
			patient->name);
		displayFormattedPhone(patient->phone.number);
		printf(" (%s)\n", patient->phone.description);
	}
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
	printf("Clinic Appointments for the Date: ");

	if (isAllRecords)
	{
		printf("<ALL>\n\n");
		printf("Date       Time  Pat.# Name            Phone#\n"
			"---------- ----- ----- --------------- --------------------\n");
	}
	else
	{
		printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
		printf("Time  Pat.# Name            Phone#\n"
			"----- ----- --------------- --------------------\n");
	}
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
	const struct Appointment* appoint,
	int includeDateField)
{
	if (includeDateField)
	{
		printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
			appoint->date.day);
	}
	printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
		patient->patientNumber, patient->name);

	displayFormattedPhone(patient->phone.number);

	printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
	int selection;

	do {
		printf("Veterinary Clinic System\n"
			"=========================\n"
			"1) PATIENT     Management\n"
			"2) APPOINTMENT Management\n"
			"-------------------------\n"
			"0) Exit System\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 2);
		putchar('\n');
		switch (selection)
		{
		case 0:
			printf("Are you sure you want to exit? (y|n): ");
			selection = !(inputCharOption("yn") == 'y');
			putchar('\n');
			if (!selection)
			{
				printf("Exiting system... Goodbye.\n\n");
			}
			break;
		case 1:
			menuPatient(data->patients, data->maxPatient);
			break;
		case 2:
			menuAppointment(data);
			break;
		}
	} while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
	int selection;

	do {
		printf("Patient Management\n"
			"=========================\n"
			"1) VIEW   Patient Data\n"
			"2) SEARCH Patients\n"
			"3) ADD    Patient\n"
			"4) EDIT   Patient\n"
			"5) REMOVE Patient\n"
			"-------------------------\n"
			"0) Previous menu\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 5);
		putchar('\n');
		switch (selection)
		{
		case 1:
			displayAllPatients(patient, max, FMT_TABLE);
			suspend();
			break;
		case 2:
			searchPatientData(patient, max);
			break;
		case 3:
			addPatient(patient, max);
			suspend();
			break;
		case 4:
			editPatient(patient, max);
			break;
		case 5:
			removePatient(patient, max);
			suspend();
			break;
		}
	} while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
	int selection;

	do {
		printf("Edit Patient (%05d)\n"
			"=========================\n"
			"1) NAME : %s\n"
			"2) PHONE: ", patient->patientNumber, patient->name);

		displayFormattedPhone(patient->phone.number);

		printf("\n"
			"-------------------------\n"
			"0) Previous menu\n"
			"-------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 2);
		putchar('\n');

		if (selection == 1)
		{
			printf("Name  : ");
			inputCString(patient->name, 1, NAME_LEN);
			putchar('\n');
			printf("Patient record updated!\n\n");
		}
		else if (selection == 2)
		{
			inputPhoneData(&patient->phone);
			printf("Patient record updated!\n\n");
		}

	} while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
	int selection;

	do {
		printf("Appointment Management\n"
			"==============================\n"
			"1) VIEW   ALL Appointments\n"
			"2) VIEW   Appointments by DATE\n"
			"3) ADD    Appointment\n"
			"4) REMOVE Appointment\n"
			"------------------------------\n"
			"0) Previous menu\n"
			"------------------------------\n"
			"Selection: ");
		selection = inputIntRange(0, 4);
		putchar('\n');
		switch (selection)
		{
		case 1:
			viewAllAppointments(data);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 2:
			viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 3:
			addAppointment(data->appointments, data->maxAppointments,
				data->patients, data->maxPatient);  // ToDo: You will need to create this function!
			suspend();
			break;
		case 4:
			removeAppointment(data->appointments, data->maxAppointments,
				data->patients, data->maxPatient);  // ToDo: You will need to create this function!
			suspend();
			break;
		}
	} while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
	int i = 0, patCounter = 0;
	displayPatientTableHeader();
	for (i = 0; i < max; i++)
	{
		if (patient[i].patientNumber != 0)
		{
			displayPatientData(&patient[i], fmt);
			patCounter++;
		}
	}

	if (patCounter == 0)
	{
		printf("*** No records found ***\n");
	}
	else
	{
		putchar('\n');
	}
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max)
{
	int i = 0, selection = 0;
	do {
		printf("Search Options\n"
			"==========================\n"
			"1) By patient number\n"
			"2) By phone number\n"
			"..........................\n"
			"0) Previous menu\n"
			"..........................\n"
			"Selection: ");
		selection = inputIntRange(0, 2);
		switch (selection) {
		case 1:
			searchPatientByPatientNumber(&patient[i], max);
			suspend();
			break;
		case 2:
			searchPatientByPhoneNumber(&patient[i], max);
			putchar('\n');
			suspend();
			break;
		case 0:
			putchar('\n');
			break;
		}


	} while (selection);




}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
	int i = 0, finish = 0, index = 0;
	for (i = 0; i < max + 1 && finish == 0; i++)
	{
		if (patient[i].patientNumber == 0)
		{
			finish++;
		}
		index = i;
	}

	if (i == max + 1)
	{
		printf("ERROR: Patient listing is FULL!\n\n");
	}
	else {
		patient[index].patientNumber = nextPatientNumber(patient, max) + 1;
		inputPatient(&patient[index]);
		printf("*** New patient record added ***\n\n");
		finish++;
	}

}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max)
{
	int userInput = 0, index = 0;
	printf("Enter the patient number: ");
	userInput = inputInt();

	index = findPatientIndexByPatientNum(userInput, patient, max);
	if (index != -1)
	{
		putchar('\n');
		menuPatientEdit(&patient[index]);
	}
	else
	{
		printf("ERROR: Patient record not found!\n");
	}

}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max)
{
	int userInput = 0, i = 0;
	printf("Enter the patient number: ");
	userInput = inputInt();
	putchar('\n');
	if (findPatientIndexByPatientNum(userInput, patient, max) != -1)
	{
		i = findPatientIndexByPatientNum(userInput, patient, max);
		displayPatientData(&patient[i], FMT_FORM);
		putchar('\n');
		printf("Are you sure you want to remove this patient record? (y/n): ");
		switch (inputCharOption("yn"))
		{
		case 'y':
			patient[i].patientNumber = 0;
			strcpy(patient[i].name, "");
			strcpy(patient[i].phone.description, "");
			strcpy(patient[i].phone.number, "");
			printf("Patient record has been removed!\n\n");
			break;
		case 'n':
			printf("Operation aborted.\n\n");
			break;
		}
		clearInputBuffer();
	}
	else
	{
		printf("ERROR: Patient record not found!\n\n");
	}
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
	int i = 0, j = 0;
	
	struct ClinicData sorted = {0};
	sorted = *data;
	
	displayScheduleTableHeader(&data->appointments->date, FMT_FORM);
	
	sort(&sorted);
	
	for (i=0;sorted.appointments[i].patientNumber!=0;i++)
	{ 
		for (j=0; sorted.patients[j].patientNumber != 0;j++) {
			if (sorted.appointments[i].patientNumber == sorted.patients[j].patientNumber) {
				displayScheduleData(&sorted.patients[j], &sorted.appointments[i], FMT_FORM);
			}
			
		}
		
	}
	putchar('\n');
}
// View appointment schedule for the user input date
// Todo:
int viewAppointmentSchedule(struct ClinicData* data)
{
	
	int i,j;
	struct Date tempDate = { 0 };
	struct ClinicData sorted = { 0 };
	sorted = *data;
	inputDate(&tempDate);
	

	sort(&sorted);
	putchar('\n');
	displayScheduleTableHeader(&tempDate,0);
	for (i = 0; sorted.appointments[i].patientNumber != 0; i++)
	{
		if (sorted.appointments[i].date.year== tempDate.year && sorted.appointments[i].date.month== tempDate.month && sorted.appointments[i].date.day == tempDate.day)
		{
			for (j = 0; sorted.appointments[j].patientNumber != 0; j++) {
				if (sorted.appointments[i].patientNumber == sorted.patients[j].patientNumber) {
					displayScheduleData(&sorted.patients[j], &sorted.appointments[i], 0);
				}

			}
		}
	}
	putchar('\n');
	return 0;
}

// Add an appointment record to the appointment array
// Todo:
int addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient)
{
	struct Appointment temp = { 0 };
	int valid = 0, i = 0;
	printf("Patient Number: ");
	temp.patientNumber=inputIntPositive();
	do {
		inputDate(&temp.date);
		//validating time
		valid = inputTime(&temp,appointments);
		
		if (!valid)
		{
			printf("\nERROR: Appointment timeslot is not available!\n\n");
		}
	} while (!valid);
	for (i = 0; appointments[i].patientNumber != 0; i++) 
	{
		;
	}
	appointments[i] = temp;
	printf("\n*** Appointment scheduled! ***\n\n");
	return 0;
}

// Remove an appointment record from the appointment array
// Todo:
int removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient)
{
	struct Appointment temp = { 0 };
	int valid = 0, i = 0,j=0;
	printf("Patient Number: ");
	temp.patientNumber = inputIntPositive();
	for (i = 0; patients[i].patientNumber != 0 && !valid; i++)
	{
		if (patients[i].patientNumber == temp.patientNumber)
		{
			valid = 1;
		}
	}
	if (!valid)
	{
		printf("ERROR: Patient record not found!\n\n");
	}
	else
	{
		do {
			inputDate(&temp.date);
			putchar('\n');
			//validating time
			valid = 0;
			for (i = 0; appointments[i].patientNumber != 0 && !valid; i++)
			{
				if (temp.date.year == appointments[i].date.year && temp.date.month == appointments[i].date.month &&
					temp.date.day == appointments[i].date.day && temp.patientNumber == appointments[i].patientNumber)
				{
					valid = 1;
					
				}
			}
			if (valid)
			{
				displayPatientData(&patients[findPatientIndexByPatientNum(temp.patientNumber, patients, maxAppointments)], FMT_FORM);
				printf("Are you sure you want to remove this appointment (y,n): ");
				if (getchar()=='y')
				{
					for (j = i-1; appointments[j].patientNumber != 0; j++)
					{
						appointments[j] = appointments[j + 1];
					}
					printf("\nAppointment record has been removed!\n\n");
					clearInputBuffer();
				}
				
			}
			else
			{
				printf("\nERROR: Appointment timeslot is not available!\n\n");
			}
		} while (!valid);
	}
	return 0;
}

void sort(struct ClinicData* sorted)
{

	int i=0,j=0;
	struct Appointment temp = {0};
	for (i = 0;sorted->appointments[i].patientNumber != 0; i++) 
	{
		
		for (j = 0; sorted->appointments[j+1].patientNumber != 0; j++)
		{
			
			//bubble sorting by time
			if (sorted->appointments[j].date.year > sorted->appointments[j + 1].date.year ||
				(sorted->appointments[j].date.year == sorted->appointments[j+1].date.year && sorted->appointments[j].date.month > sorted->appointments[j+1].date.month) ||
				(sorted->appointments[j].date.year == sorted->appointments[j+1].date.year && sorted->appointments[j].date.month == sorted->appointments[j + 1].date.month 
					&& sorted->appointments[j].date.day > sorted->appointments[j+1].date.day)|| (sorted->appointments[j].date.year == sorted->appointments[j + 1].date.year && sorted->appointments[j].date.month == sorted->appointments[j + 1].date.month
						&& sorted->appointments[j].date.day == sorted->appointments[j + 1].date.day && sorted->appointments[j].time.hour > sorted->appointments[j+1].time.hour) || (sorted->appointments[j].date.year == sorted->appointments[j + 1].date.year && sorted->appointments[j].date.month == sorted->appointments[j + 1].date.month
							&& sorted->appointments[j].date.day == sorted->appointments[j + 1].date.day && sorted->appointments[j].time.hour == sorted->appointments[j + 1].time.hour && sorted->appointments[j].time.min > sorted->appointments[j + 1].time.min))
			{	
				temp = sorted->appointments[j];
				sorted->appointments[j] = sorted->appointments[j + 1];
				sorted->appointments[j + 1] = temp;
			}
			if (sorted->appointments[j-1].patientNumber == 0) {
				j = MAX_APPOINTMENTS;
			}
		}
		
	}
	

}
int inputTime(struct Appointment* temp,const struct Appointment* appointments)
{
	int valid = 0,i=0;
	do {
		printf("Hour (0-23)  : ");
		temp->time.hour = inputIntRange(0, 23);
		printf("Minute (0-59): ");
		temp->time.min = inputIntRange(0, 59);
		if ((temp->time.min != 0 && temp->time.min != 30) || temp->time.hour < START_TIME || temp->time.hour>END_TIME || (temp->time.hour == END_TIME && temp->time.min > 0))
		{
			printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");
		}
		else
		{
			valid = 1;
		}
	} while (!valid);
	for (i = 0; appointments[i].patientNumber != 0; i++)
	{
		if (temp->date.year == appointments[i].date.year && temp->date.month == appointments[i].date.month &&
			temp->date.day == appointments[i].date.day && temp->time.hour == appointments[i].time.hour && temp->time.min == appointments[i].time.min)
		{
			valid = 0;
		}
	}
	return valid;
}


void inputDate(struct Date* date)
{
	int tempYear = 0, tempMonth = 0, tempDay = 0, monthsDay = 0;
	printf("Year        : ");
	tempYear = inputIntPositive();
	printf("Month (1-12): ");
	tempMonth = inputIntRange(1, 12);
	if (tempMonth == 4 || tempMonth == 6 || tempMonth == 9 || tempMonth == 11)
	{
		monthsDay = 30;
	}
	else if (tempMonth == 1 || tempMonth == 3 || tempMonth == 5 || tempMonth == 7 ||
		tempMonth == 8 || tempMonth == 10 || tempMonth == 12)
	{
		monthsDay = 31;
	}
	else if (tempYear % 4 == 0 && tempMonth == 2)
	{
		monthsDay = 29;
	}
	else
	{
		monthsDay = 28;
	}
	printf("Day (1-%d)  : ", monthsDay);
	tempDay = inputIntRange(1, monthsDay);
	date->day = tempDay;
	date->month = tempMonth;
	date->year = tempYear;
}
//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
	int userInput = 0, index = 0;
	printf("\nSearch by patient number: ");
	userInput = inputInt();
	index = findPatientIndexByPatientNum(userInput, patient, max);
	putchar('\n');
	if (index != -1)
	{
		displayPatientData(&patient[index], FMT_FORM);
	}
	else
	{
		printf("*** No records found ***\n");
	}
	putchar('\n');
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
	int  i = 0, findCounter = 0;
	char userInput[100] = { 0 };
	printf("\nSearch by phone number: ");
	inputCString(userInput, PHONE_LEN, PHONE_LEN);
	putchar('\n');
	displayPatientTableHeader();
	for (i = 0; i < max; i++)
	{
		if (!strcmp(userInput, patient[i].phone.number))
		{
			displayPatientData(&patient[i], FMT_TABLE);
			findCounter++;
		}
	}
	if (findCounter == 0)
	{
		printf("\n*** No records found ***\n");
	}

}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
	int i, maxNum = 0;
	for (i = 0; i < max; i++)
	{
		if (maxNum < patient[i].patientNumber)
		{
			maxNum = patient[i].patientNumber;
		}
	}
	return maxNum;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
	int index = -1, i;
	for (i = 0; i < max && index == -1; i++)
	{
		if (patient[i].patientNumber == patientNumber)
		{
			index = i;
		}
	}
	return index;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
	printf("Patient Data Input\n"
		"------------------\n");
	printf("Number: %-.5d\n", patient->patientNumber);

	printf("Name  : ");
	inputCString(patient->name, 1, NAME_LEN);
	putchar('\n');
	inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone)
{
	int selection = 0;
	printf("Phone Information\n"
		"-----------------\n");
	printf("How will the patient like to be contacted?\n"
		"1. Cell\n"
		"2. Home\n"
		"3. Work\n"
		"4. TBD\n"
		"Selection: ");
	selection = inputIntRange(1, 4);
	putchar('\n');
	switch (selection)
	{
	case 1:
		strcpy(phone->description, "CELL");
		printf("Contact: %s\n", phone->description);
		printf("Number : ");
		inputCString(phone->number, PHONE_LEN, PHONE_LEN);
		putchar('\n');
		break;
	case 2:
		strcpy(phone->description, "HOME");
		printf("Contact: %s\n", phone->description);
		printf("Number : ");
		inputCString(phone->number, PHONE_LEN, PHONE_LEN);
		putchar('\n');
		break;
	case 3:
		strcpy(phone->description, "WORK");
		printf("Contact: %s\n", phone->description);
		printf("Number : ");
		inputCString(phone->number, PHONE_LEN, PHONE_LEN);
		putchar('\n');
		break;

	case 4:
		strcpy(phone->description, "TBD");
		strcpy(phone->number, "");
		break;

	}
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
	int i = 0;
	FILE* fp = NULL;
	fp = fopen(datafile, "r");
	if (fp != NULL)
	{
		i = 0;
		while (i < max && fscanf(fp, "%d|%15[^|]|%4[^|]|%10[^\n]\n", &patients[i].patientNumber, patients[i].name,
			patients[i].phone.description, patients[i].phone.number) != EOF)
		{
			i++;
		}
		fclose(fp);
	}
	return i;
}



// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
	int i = 0,counter=0;
	FILE* fp = NULL;
	fp = fopen(datafile, "r");
	if (fp != NULL)
	{
		i = 0;
		while (i < max && fscanf(fp, "%d,%d,%d,%d,%d,%d\n", &appoints[i].patientNumber, &appoints[i].date.year,
			&appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) == 6)
		{
			i++;
		}
		counter = i;
		while (i < max) {
			appoints[i].patientNumber = 0;
			i++;
		}
		fclose(fp);
		
	}
	return counter;
}
