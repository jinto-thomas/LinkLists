#include "linked_list.h"
#include <assert.h>


void DeleteList(struct node **headRef)
{
		struct node *temp = *headRef;
		struct node *nextn;
		while (temp != 0) {
		           nextn = temp->next;
			       free(temp);
			       temp = nextn;
			       }
		*headRef = NULL;
		
}



void InsertNth(struct node **headRef,int index, int datas)
{
		if (index == 0)
				Push(headRef,datas);

		else {
				struct node *current = *headRef;
				int i;
				for (i = 0; i <= index-1; i++) {
						assert(current != NULL);
						current = current->next;
				}
				assert(current != NULL);
				Push(&(current->next),datas);
		}
	
}

void InsertNthTest(void)
{
		struct node *head = BuildOneTwoThree();

		InsertNth(&head, 0, 13);
		InsertNth(&head, 1, 42);
		InsertNth(&head, 1, 5);

		DeleteList(&head);

}


main()
{
		InsertNthTest();
		return 0;
}
