#include "linked_list.h"

void DeleteList(struct node **headRef)
{
		struct node *temp = *headRef;
		struct node *nextn;
		while (temp != 0) {
				nextn = temp->next;
				free(temp);
				temp = nextn;
		}
		*headRef = NULL;
}




void DeleteListTest(void)
{
		struct node *mylist = BuildOneTwoThree();

		DeleteList(&mylist);
}

main()
{
	DeleteListTest();
	return 0;
}
