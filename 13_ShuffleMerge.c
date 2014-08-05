#include "linked_list.h"

void MoveNode(struct node **destRef, struct node **sourceRef)
{
		struct node *a = *destRef;
		struct node *b = *sourceRef;
		*sourceRef = b->next;
		b->next = *destRef;
		*destRef = b;
}





struct node *ShuffleMerge (struct node *a, struct node *b)
{
		struct node *temp = NULL;
		struct node **tpos = &temp;
		struct node *aa = a;
		struct node *bb = b;
		while (1) {
				if (aa == 0) {
						*tpos = bb;
						break;
				}
				else if (bb == 0) {
						*tpos = aa;
						break;
				}
				MoveNode(tpos, &aa);
				tpos = &((*tpos)->next);
				MoveNode(tpos, &bb);
				tpos = &((*tpos)->next);
		}
		return temp;




}

main()
{
		struct node *a = BuildOneTwoThree();
		struct node *b = BuildOneTwoThree1();
		struct node *c = ShuffleMerge(a,b);
		struct node *d = c;
		while (d != 0) {
				printf("%d ",d->data);
				d = d->next;
		}
		return 0;
}
						
