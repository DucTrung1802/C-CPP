#include <stdio.h>
#include <stdint.h>

void initializeArray(int32_t *const input_array, uint16_t const len);
void displayArray(int32_t const *const input_array, uint16_t const len);
void swapArray(int32_t *const array_1, uint16_t const len_array_1, int32_t *const array_2, uint16_t const len_array_2);
void waitForUser();

int main()
{
	uint32_t len_array_1;
	uint32_t len_array_2;

    printf("Give size of first array: ");
    if (!scanf("%u", &len_array_1) || len_array_1 <= 0)
	{
    	printf("Invalid input!\n");
    	printf("Exiting...\n");
    	waitForUser();
    	return 1;
	}

    printf("Give size of second array: ");
    if (!scanf("%u", &len_array_2) || len_array_2 <= 0)
	{
    	printf("Invalid input!\n");
    	printf("Exiting...\n");
    	waitForUser();
    	return 1;
	}

    int32_t array_1[len_array_1];
    int32_t array_2[len_array_2];

    initializeArray(array_1, len_array_1);
    initializeArray(array_2, len_array_2);

    printf("Before swapping\n");
    displayArray(array_1, len_array_1);
    displayArray(array_2, len_array_2);

    swapArray(array_1, len_array_1, array_2, len_array_2);

    printf("After swapping\n");
    displayArray(array_1, len_array_1);
    displayArray(array_2, len_array_2);

    waitForUser();

    return 0;
}

void initializeArray(int32_t *const input_array, uint16_t const len)
{
    for (int i = len; i > 0; i--)
    {
        input_array[len - i] = i;
    }
}

void displayArray(int32_t const *const input_array, uint16_t const len)
{
    printf("Array: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", input_array[i]);
    }
    printf("\n");
}

void swapArray(int32_t *const array_1, uint16_t const len_array_1, int32_t *const array_2, uint16_t const len_array_2)
{
    uint16_t swap_len = (len_array_1 < len_array_2) ? len_array_1 : len_array_2;
    int32_t temp;

    for (int i = 0; i < swap_len; i++)
    {
        temp = array_1[i];
        array_1[i] = array_2[i];
        array_2[i] = temp;
    }
}

void waitForUser()
{
	printf("\nPress any key to continue...");
	fflush(stdin);
	getchar();
}

