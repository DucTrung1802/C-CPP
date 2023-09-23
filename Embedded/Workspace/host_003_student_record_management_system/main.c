#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "main.h"

void reChoose(bool const valid);
void printStudentInfo(STUDENT_LIST_t const student_list);
bool addStudentRecord();
int8_t checkExistingId(STUDENT_LIST_t const student_list, uint32_t const id);
void deleteStudentRecord(STUDENT_LIST_t *student_list, uint32_t const delete_id);

STUDENT_LIST_t student_list;

int main()
{
	uint8_t choice = 0;
	bool valid_choice;
	student_list.total = 0;
	uint32_t delete_id;
	do
	{
		printf("\n===============================\n");
		printf("Student Record Managment System\n");
		printf("Choose your option\n");
		printf("1. Display all records\n");
		printf("2. Add a new record\n");
		printf("3. Delete a record\n");
		printf("4. Exit system\n");
		printf("\nChoose: ");
		valid_choice = (bool) scanf("%u", &choice);
		if (!valid_choice)
		{
			reChoose(0);
			continue;
		}
		switch (choice)
		{
		case 1:
			if (!student_list.total)
			{
				printf("There is no record in the list!\n");
				reChoose(1);
				continue;
			}

			printStudentInfo(student_list);

			printf("\n");
			break;
		case 2:
			if (student_list.total == 10)
			{
				printf("Record is full!\n");
				printf(
						"To add new record, please delete an existing record!\n");
				reChoose(1);
				continue;
			}

			bool valid;
			STUDENT_INFO_t student;
			valid = addStudentRecord(&student);

			if (valid)
			{
				printf("Add student successfully!\n");
				student_list.student[student_list.total] = student;
				student_list.total++;
				printf("\nCurrent record in the list: %u\n\n",
						student_list.total);
				reChoose(1);
				continue;
			}
			else
			{
				printf("\nAdd student unsuccessfully!\n\n");
				reChoose(1);
				continue;
			}
			break;
		case 3:
			printf("Enter the ID of record you want to delete: ");
			if (!scanf("%u", &delete_id))
			{
				reChoose(0);
				continue;
			}

			deleteStudentRecord(&student_list, delete_id);

			break;
		case 4:
			printf("4\n");
			break;
		default:
			reChoose(0);
			break;
		}

	} while (choice != 4);
	return 0;
}

void reChoose(bool valid)
{
	if (!valid)
	{
		printf("Invalid choice!\n");
	}

	printf("Press any key to rechoose...\n");
	fflush(stdin);
	getchar();
	system("cls");
	fflush(stdin);
}

void printStudentInfo(STUDENT_LIST_t student_list)
{
	for (int i = 0; i < student_list.total; i++)
	{
		printf("\n");
		printf("ORDER: #%u\n", (i + 1));
		printf("ID: %u\n", student_list.student[i].id);
		printf("Full name: %s\n", student_list.student[i].full_name);
		printf("DOB: %u/%u%/%u\n", student_list.student[i].dob.day,
				student_list.student[i].dob.month,
				student_list.student[i].dob.year);
		printf("Semester: %u\n", student_list.student[i].semester);
		printf("CPA: %.2f\n", student_list.student[i].cpa);
	}
}

bool addStudentRecord(STUDENT_INFO_t *student)
{
	printf("\n");

	printf("Enter ID of student: ");
	fflush(stdin);
	if (!scanf("%u", &(student->id)))
	{
		return false;
	}

	if (checkExistingId(student_list, student->id) >= 0)
	{
		printf("\nAlready existing this ID!\n");
		return false;
	}

	printf("Enter full name of student (limit 80 character): ");
	fflush(stdin);
	if (!scanf("%[^\n]s", student->full_name))
	{
		return false;
	}

	printf("Enter DOB of student (dd/mm/yyyy)\n");
	printf("Day: ");
	fflush(stdin);
	if (!scanf("%u", &(student->dob.day)) || student->dob.day > 31)
	{
		return false;
	}
	printf("Month: ");
	fflush(stdin);
	if (!scanf("%u", &(student->dob.month)) || student->dob.month > 12)
	{
		return false;
	}
	printf("Year: ");
	fflush(stdin);
	if (!scanf("%u", &(student->dob.year)) || student->dob.year < 1900
			|| student->dob.year > 2023)
	{
		return false;
	}

	printf("Enter current semester: ");
	fflush(stdin);
	if (!scanf("%u", &(student->semester)) || student->semester > 15)
	{
		return false;
	}

	printf("Enter current CPA: ");
	fflush(stdin);
	if (!scanf("%f", (&student->cpa)) || student->cpa < 0 || student->cpa > 4.0)
	{
		return false;
	}

	return true;
}

int8_t checkExistingId(STUDENT_LIST_t const student_list, uint32_t const id)
{
	for (int i = 0; i < student_list.total; i++)
	{
		if (student_list.student[i].id == id)
		{
			return i;
		}
	}
	return -1;
}

void deleteStudentRecord(STUDENT_LIST_t *student_list, uint32_t const delete_id)
{
	int8_t position = checkExistingId(*student_list, delete_id);
	if (position == -1)
	{
		printf("There is no ID '%u' in the list!\n", delete_id);
		return;
	}

	if (student_list->total > 1)
	{
		for (int i = position + 1; i < student_list->total; i++)
		{
			student_list->student[i - 1] = student_list->student[i];
		}
	}

	student_list->total--;

	printf("Delete record with ID %u successfully!\n", delete_id);
	printf("Current record in the list: %u\n", student_list->total);
}
