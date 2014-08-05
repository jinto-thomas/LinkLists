#include "linked_list.h"


void append (struct node **aRef, struct node **bRef)
{
		struct node *aLast = *aRef;
		if (*aRef == NULL) {
				*aRef = *bRef;
		}
		else {
		while (aLast->next != 0)
				aLast = aLast->next;
		aLast->next = *bRef;
		}
		*bRef = NULL;
}


main()
{
		struct node *a = NULL;//BuildOneTwoThree();

		struct node *b = BuildOneTwoThree();

		append(&a,&b);
		struct node *c = a;
		while (c != 0) {
				printf("%d ",c->data);
				c = c->next;
		}
		printf("\n");
		struct node *d = b;
		while (d != 0) {
				printf("%d ",d->data);
				d = d->next;
		}
		return 0;
}
