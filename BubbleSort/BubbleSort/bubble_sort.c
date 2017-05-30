/*
* Filename: bubble_sort.c
* This program takes a sequence of numbers (Max 50) and performs a bubble sort in either
* ascending or descending order depending on user preference and prints the sorted numbers.
*/
#include <stdio.h>

/*
* Gets user input for the sorting order and the sequence of numbers to be sorted
* Parameter: none
*/
void set_sequence();

/* Sorts the sequence of numbers according to the user's preference, either ascending
* or descending order.
* Parameter: sequence - The array of numbers to be sorted
* Parameter: size - The size of the array
* Parameter: *so - pointer to sort_order[]
*/
void bubble_sort(int sequence[], int size, char *so);

/*
* Swaps the integers passed from the bubble_sort method
* Parameter: *j - pointer to *j1 - 1 in sequence
* Paramater: *j1 - pointer to *j + 1 in sequence
*/
void swap(int *j, int *j1);

int sequence[50];
int size = sizeof(sequence) / sizeof(sequence[0]);
char sort_order[10];

/* Begins the program calls set_sequence() and bubble_sort
 * and prints the sorted numbers.
 * Parameter: none
 */
int main()
{
	set_sequence();
	bubble_sort(sequence, size, sort_order);

	/* Print the sorted sequence of numbers */
	for (int i = 0; i < size; i++)
	{
		if (sequence[i] >= 1)
			printf("%d ", sequence[i]);
	}

	printf("\n");
	getch();
}

void set_sequence()
{
	int num;
	
	/* Get the sorting order from user */
	printf("Please enter the sort order(ascending/descending): ");
	scanf("%s", &sort_order);

	/* Get the sequence of numbers to be sorted from the user */
	printf("Please enter the numbers to be sorted: ");
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &num);
		sequence[i] = num;
		if (num == 0)
			break;
	}
}

void bubble_sort(int sequence[], int size, char *so)
{
	/* Ascneding order */
	if (sort_order[0] == 'a' || sort_order[0] == 'A')
	{
		int i, j;
		for (i = 0; i < size - 1; i++)
			for (j = 0; j < size - i - 1; j++)
				if (sequence[j] > sequence[j + 1])
					swap(&sequence[j], &sequence[j + 1]);
	}

	/* Descending order */
	if (sort_order[0] == 'd' || sort_order[0] == 'D')
	{
		int i, j;
		for (i = 0; i < size - 1; i++)
			for (j = 0; j < size - 1; j++)
				if (sequence[j + 1] > sequence[j])
					swap(&sequence[j], &sequence[j + 1]);
	}
}

void swap(int *j, int *j1)
{
	int temp = *j;
	*j = *j1;
	*j1 = temp;
}
