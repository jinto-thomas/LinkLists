#include "linked_list.h"

void SortedInsert(struct node **headRef,struct node *newNode)
{
	
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
}


void InsertSort (struct node **headRef)
{
		struct node *temp = *headRef;
		struct node *next;
		struct node *result = NULL;

		while (temp != 0) {
				next = temp->next;
				SortedInsert(&result,temp);
				temp = next;
		}

		*headRef = result;
		
		
		printf("in INSERt SORT\n");
		struct node *s = *headRef;
		while (s != 0) {
				printf("%d ",s->data);
				s = s->next;
		}
}

main()
{
		struct node *p = BuildOneTwoThree();
		InsertSort(&p);
}
