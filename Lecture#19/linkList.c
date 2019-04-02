#include <stdio.h>
#include <stdlib.h>

typedef struct studentStruct Record;
struct studentStruct
{
	char Name[100];
	int UIN;
	float GPA;
	Record *next;
};

Record *find_node(Record *head, int UIN)
{
	Record *current = head;

	//keep traversing the list while 1)not at the end of the list AND 
	//				 2)current record's UIN < UIN we are looking for

	
	
}


void add_node(Record **list, int new_UIN)
{
	Record *current = *list;
	Record *prev = *list;
	Record *temp = (Record *)malloc(sizeof(Record)); //allocate memory for the new node
	//initialize UIN for the new node

	//keep traversing the list until we reach the end
	while (       )
	{
		//the first instance when new_UIN is smaller than current record's UIN
		//we want to insert new node in front of the current node
				
			//if the current node is the head, update head pointer  
			  
			else //for everything else, update previous node's next pointer		  
			  
			return; //exit function
		}
		//we've reach the last note and its UIN is still smaller than new node's UIN
		//new node will have to be inserted at the tail
		
		{
			
		}
		prev = current;
		current = current ->next;
	}
}


void remove_node(Record **list, int old_UIN)
{
	Record *prev;
	Record *current = *list;

	while(current != NULL) //find the record with matching UIN
	{
		
		
		
	}

					//if record is not found, return out
		return;
	
					//if record is the first node, update head pointer
	{
		
	}
	else //record found is in the middle of the list
	{
	
	}

	free(current);
}




int main()
{
	Record *head = (Record *)malloc(sizeof(Record));

	head->UIN = 12345;

	int i;
	Record *current = head;
	
	for(i=1;i<5;i++)
	{
		current->next = (Record *)malloc(sizeof(Record));
		current->next->UIN = i*2+12345;
		current = current->next;
	}
	current->next = NULL;

	current = head;
	for(i=0;i<5;i++)
	{
		printf("Node %d: UIN: %d\n", i, current->UIN);
		current = current->next;
	}

	find_node(head, 12349);

	int new_UIN = 12350;
	add_node(&head, new_UIN);
 	printf("Insert record with UIN: %d.\n", new_UIN);
        current = head;
        for(i=0;i<6;i++)
        {
                printf("Node %d: UIN: %d\n", i, current->UIN);
                current = current->next;
        }

	int old_UIN = 12350;
	remove_node(&head, old_UIN);
	printf("Delete record with UIN: %d.\n", old_UIN);
	current = head;
	for(i=0;i<6 && (current != NULL);i++)
        {
                printf("Node %d: UIN: %d\n", i, current->UIN);
                current = current->next;
        }

	return 0;
}
