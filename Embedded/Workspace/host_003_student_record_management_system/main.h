#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

#define MAX_AMOUNT_STUDENT 10

typedef struct
{
	uint8_t day;
	uint8_t month;
	uint16_t year;
} DATE_e;

typedef struct
{
	uint32_t id;
	char full_name[80];
	DATE_e dob;
	uint8_t semester;
	float cpa;
} STUDENT_INFO_t;

typedef struct
{
	STUDENT_INFO_t student[MAX_AMOUNT_STUDENT];
	uint8_t total;
} STUDENT_LIST_t;

#endif /* MAIN_H_ */
