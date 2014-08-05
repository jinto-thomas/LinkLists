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

void MergeSort (struct node **headRef)
{
		struct node *temp = *headRef;
		struct node *a = NULL;
		struct node *b = NULL;
		
		if (Length(*headRef) < 2)
				return;

		FrontBackSplit (temp, &a, &b);
		MergeSort(&a);
		MergeSort(&b);

		*headRef = SortedMerge(a,b);
}

main()
{
		struct node *p = BuildOneTwoThree();
		MergeSort(&p);
		struct node *s = p;

		while (p != 0) {
				printf("%d ",p->data);
				p = p->next;
		}
		return 0;
}



