#include <stdio.h>
#include <stdlib.h>


struct node {
		int data;
		struct node *next;
};

struct node *New_Build(void)
{
		struct node *temp;
	   	temp = (struct node *)malloc(sizeof(struct node));
		temp->data = 1;
		temp->next = (struct node *)malloc(sizeof(struct node));
		temp->next->data = 2;
		temp->next->next = (struct node *)malloc(sizeof(struct node));
		temp->next->next->data = 3;
		temp->next->next->next = NULL;
		return temp;
}

int Length(struct node *head)
{
		struct node *temp = head;
		int count = 0;
		while (temp != 0) {
				count++;
				temp = temp->next;
		}
		return count;
				
}
main()
{
		struct node *test = NULL;
		test = New_Build();

		printf("%d %d %d\n",test->data,test->next->data,test->next->next->data);
		printf("%d\n",Length(test));
		return 0;
};
