#include "linked_list.h"
#include <assert.h>

int Pop(struct node **headRef)
{
		struct node *temp = *headRef;
		int i;
		
		assert(temp != NULL);
		i = temp->data;
		
		*headRef = temp->next;
		free(temp);
		
		return i;
}


void PopTest(void)
{
		struct node *head = BuildOneTwoThree();
		int a = Pop(&head);
		int b = Pop(&head);
		int c = Pop(&head);
		int d = Pop(&head);
		int len = Length(head);
		printf("%d\n",len);
}

main()
{
		PopTest();
		return 0;
}
