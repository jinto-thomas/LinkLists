#include "linked_list.h"

void MoveNode(struct node **destRef, struct node **sourceRef)
{
		struct node *a = *destRef;
		struct node *b = *sourceRef;
		*sourceRef = b->next;
		b->next = *destRef;
		*destRef = b;
}

main()
{
		struct node *p = BuildOneTwoThree();
		struct node *s = BuildOneTwoThree();
		MoveNode (&p,&s);
		struct node *testp = p;
		while (testp != 0) {
				printf("%d ",testp->data);
				testp = testp->next;
		}
		struct node *stest = s;
		printf("\n");
		while (stest != 0) {
				printf("%d ",stest->data);
				stest = stest->next;
		}
		return 0;
}

