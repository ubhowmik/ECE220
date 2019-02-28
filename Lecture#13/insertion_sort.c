#include <stdio.h>
#define SIZE 5
int main()
{
	int array[] = {7,4,6,3,1};

	//sort array in ascending order
	int i, j, temp, empty = 0;
        for(i=1;i<SIZE;i++)
	{
		temp = array[i];
		for(j=i-1;j>=0;j--)
		{
			if(temp < array[j])
			{
				//shift element to the right
				array[j+1] = array[j];
				//update empty position
				empty = j;
			}
		}
		//insert at the proper location
		array[empty] = temp;
	}

	printf("sorted array: \n");
	for(i=0;i<SIZE;i++){
		printf("%d ", array[i]);
	}
	printf("\n");
 
	return 0;
}
