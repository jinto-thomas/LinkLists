#include "linked_list.h"

void FrontBackSplit (struct node *source, struct node **frontRef,struct node **backRef)
{
		struct node *findlen = source;
		int len = Length(source);
		int i;

		if (len < 2){
				*frontRef = source;
				*backRef = NULL;
		}
		else {
				int mid = (len-1)/2;
				for (i = 0; i < mid;i++) {
						findlen = findlen->next;
				}
				*frontRef = source;
				*backRef = findlen->next;
				findlen->next = NULL;
		}
}



main()
{
		struct node *t = BuildOneTwoThree();
		struct node *a = NULL;
		struct node *b = NULL;
		FrontBackSplit(t,&a,&b);
		struct node *x = a;
		struct node *y = b;
		while (x != 0) {
				printf("a :%d ",x->data);
				x = x->next;
		}
		while (y != 0) {
				printf("b :%d ",y->data);
				y = y->next;
		}
		return 0;
}
