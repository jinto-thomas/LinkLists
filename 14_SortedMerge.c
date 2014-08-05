#include "linked_list.h"

void MoveNode(struct node **destRef, struct node **sourceRef)
{
		struct node *a = *destRef;
		struct node *b = *sourceRef;
		*sourceRef = b->next;
		b->next = *destRef;
		*destRef = b;
}


struct node *SortedMerge (struct node *a, struct node *b)
{
		struct node *aa = a;
		struct node *bb = b;

		struct node *result = NULL;
		struct node **ref = &result;

		while (1) {
				if (aa == 0) {
						*ref = bb;
						break;
				}
				else if (bb == 0) {
						*ref = aa;
						break;
				}
				else if (aa->data <= bb->data) {
						MoveNode(ref,&aa);
				}
				else {
						MoveNode(ref,&bb);
				}
				ref = &((*ref)->next);
		}
		return result;
}

main()
{
		struct node *a = BuildOneTwoThree();
		struct node *b = BuildOneTwoThree1();

		struct node *c = NULL;
		c = SortedMerge(a , b);
		struct node *d = c;
		while (d != 0) {
				printf("%d ",d->data);
				d = d->next;
		}
}

