#include <stdio.h>

#define LENGTH 8

void quicksort(int array[], int start, int end);
int partition(int array[], int low, int high);
void swap(int *x, int *y);
void printarray(int array[]);


int main()
{
	int array[LENGTH] = {8,4,13,2,7,6,3,10};

	printf("Unsorted Array: ");
	printarray(array);

	quicksort(array, 0, LENGTH-1);

	printf("Sorted Array: ");
	printarray(array);

	return 0;
}


void quicksort(int array[], int start, int end)
{
	if(start > end)
		return;
	
	int pivot_idx = partition(array,start,end);
	quicksort(array, start, pivot_idx-1);
	quicksort(array, pivot_idx+1, end);
}

int partition(int array[], int low, int high)
{
	int pivot = array[low]; //set first element as pivot

	int store_idx = low + 1; //set second element index as the starting store index

	printf("pivot = %d, start_idx = %d, end_idx = %d \n", pivot, low, high);

	int i;
	for(i=low+1;i<=high;i++)
	{
		if(array[i] < pivot)
		{
			swap(&array[i], &array[store_idx]);
                        store_idx++;
		}
	}

	swap(&array[low], &array[store_idx-1]);

        printf("Partitioned Array: ");
	printarray(array);

	return store_idx-1;
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void printarray(int array[])
{
	int i;
        for(i=0;i<LENGTH;i++)
        {
                printf("%d ", array[i]);
        }
        printf(" \n");

}
