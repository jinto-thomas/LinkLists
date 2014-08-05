#include "linked_list.h"

void RemoveDuplicates(struct node *head)
{
		struct node *temp = head;
		struct node *store;
		if (temp == NULL) return;

		while (temp->next != 0) {
				if (temp->data == temp->next->data) {
						store = temp->next->next;
						free(temp->next);
						temp->next = store;
				}
				else {
						temp = temp->next;
				}
		}
}

main()
{
		struct node *p = BuildOneTwoThree();
		RemoveDuplicates(p);
		struct node *s = p;
		while (s != 0) {
				printf("%d ",s->data);
				s = s->next;
		}
		return 0;
}
						
