#include "linked_list.h"

struct node *SortedIntersect (struct node *a, struct node *b)
{
		struct node *aa = a;
		struct node *bb = b;
		struct node *result = NULL;

		struct node **temp = &result;

		while (aa != 0) {
				while (bb != 0) {
						if (aa->data == bb->data) {
								Push(temp,aa->data);
								temp = &((*temp)->next);
						}
						bb = bb->next;
				}
				bb = b;
				aa = aa->next;
		}
		return result;
}

main()
{
		struct node *s = BuildOneTwoThree();
		struct node *p = BuildOneTwoThree1();

		struct node *a = SortedIntersect(s,p);
		struct node *b = a;
		while (b != 0) {
				printf("%d ",b->data);
				b = b->next;
		}
		return 0;
}

