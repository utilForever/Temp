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

// list ���� �Լ��� node�� �����ϰ� ��������...
// Node�� �޸� �Ҵ��� �ܺο��� ����.
void insert_front(NODE* node)
{
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
		NODE* temp = (NODE*)malloc(sizeof(NODE));
		temp->data = i;

		insert_front(temp);
		display();
	}
}
