#include "linked_list.h"
#include <assert.h>
int GetNth(struct node *root,int num)
{
		int pos = 0;
		struct node *temp = root;

		while (temp != 0) {
				if (pos == num)
						return temp->data;
				pos++;
				temp = temp->next;
		}
		assert(0);

}


void GetNthTest(void)
{
		struct node *head = BuildOneTwoThree();
		int LastNode = GetNth(head,3);
		printf("%d\n",LastNode);
}

main()
{
		GetNthTest();
		return 0;
}

