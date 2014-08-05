#include "linked_list.h"

void MoveNode(struct node **destRef, struct node **sourceRef)
{
		struct node *a = *destRef;
		struct node *b = *sourceRef;
		*sourceRef = b->next;
		b->next = *destRef;
		*destRef = b;
}

void Reverse(struct node **headRef)
{
		struct node *temp = *headRef;
		struct node *new = NULL;
		while (temp != 0) {
				MoveNode(&new, &temp);
			//	temp = temp->next;
		}
		*headRef = new;

