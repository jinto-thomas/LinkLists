#include "linked_list.h"

void SortedInsert(struct node **headRef,struct node *newNode)
{
		struct node *ptest = *headRef;
	
		while (ptest != 0) {
				printf("%d ",ptest->data);
				ptest = ptest->next;
		}


		if (*headRef == NULL || ((*headRef)->data >= newNode->data)){
				newNode->next = *headRef;
				*headRef = newNode;
		}
		else {
				struct node *temp = *headRef;
				while (temp->next != 0 && (temp->next->data < newNode->data))
						temp = temp->next;
				newNode->next = temp->next;
				temp->next = newNode;
		}
		printf("\n================after=================\n");
		struct node *stest = *headRef;
		while (stest != 0) {
				printf("%d ",stest->data);
				stest = stest->next;
		}
}


main()
{
		struct node *p = BuildOneTwoThree();
		struct node *s = NULL;
		Push(&s,5);
		SortedInsert(&p,s);
		return 0;
}

