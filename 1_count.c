#include "linked_list.h"

int Count(struct node *top,int num)
{
		struct node *temp = top;
		int count = 0;
		while (temp != 0) {
				if (temp->data == num)
						count++;
				temp = temp->next;
		}
		return count;
}


void CountTest (void) {
		struct node *head;
		head = BuildOneTwoThree();
		int count = Count(head,2);
		printf("%d\n",count);
}

main()
{
		CountTest();
		return 0;
}

