#include "linked_list.h"

void MoveNode(struct node **destRef, struct node **sourceRef)
{
		struct node *a = *destRef;
		struct node *b = *sourceRef;
		*sourceRef = b->next;
		b->next = *destRef;
		*destRef = b;
}




void AlternatingSplit (struct node *source, struct node **aRef, struct node **bRef)
{
		struct node *temp = source;
		struct node *a = NULL;
		struct node *b = NULL;

		while (temp != 0) {
				MoveNode(&a , &temp);
				if (temp != 0)
						MoveNode(&b, &temp);
		}
		*aRef = a;
		*bRef = b;
					
}

main()
{
		struct node *p = BuildOneTwoThree();
		struct node *a = NULL;
		struct node *b = NULL;

		AlternatingSplit(p, &a, &b);

		struct node *c = a;
		while (c != 0) {
				printf("%d ",c->data);
				c = c->next;
		}
		struct node *d = b;
		printf("\n");
		while (d != 0) {
				printf("%d ",d->data);
				d = d->next;
		}
		return 0;
}

