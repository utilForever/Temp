#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE
{
	int      data;
	struct  _NODE  *next;
} NODE;

NODE *head = 0;

void init_list()
{
	head = (NODE*)malloc(sizeof(NODE));
	head->next = 0;
	head->data = 0;
}

void insert_front(int data)
{
	NODE *node = (NODE*)malloc(sizeof(NODE));
	node->data = data;

	node->next = head->next;
	head->next = node;
}

void display()
{
	NODE *node = 0;
	system("cls");
	printf("[HEAD] ");

	for (node = head->next; node != 0; node = node->next)
		printf("-> %d ", node->data);

	getchar();
}



int main()
{
	int i = 0;
	init_list();
	display();

	for (i = 0; i < 7; i++)
	{	
		insert_front(i);
		display();
	}
}
