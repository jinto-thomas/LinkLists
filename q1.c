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

void LinkTes(void)
{
		struct node *head = New_Build();
		struct node *new;
		new = malloc(sizeof(struct node));
		new->data = 1;

		new->next = head;
		head = new;
}

void WrongPush(struct node *head, int data)
{
		struct node *newnode = malloc(sizeof(struct node));
		printf("head in wrongpush%p\n",head);
		newnode->data = data;
		newnode->next = head;
		head = newnode;
		printf("%p %p\n",head,newnode);
}
void WrongPushTest(void)
{
		struct node *head = New_Build();
		printf("head %p\n",head);
		printf("head hex%p\n",&head);
		
		WrongPush(head,5);
		printf("head atlast %p\n",head);
}


void Push(struct node **headRef, int data)
{
		struct node *newnode = malloc(sizeof(struct node));

		newnode->data = data;
		newnode->next = *headRef;
		*headRef = newnode;
}

void PushTest(void)
{
		struct node *head = New_Build();

		push(&head, 1);
		push(&head, 13);
}



main()
{
		struct node *test = NULL;
		test = New_Build();

		printf("%d %d %d\n",test->data,test->next->data,test->next->next->data);
		printf("%d\n",Length(test));
		WrongPushTest();
		return 0;
};
