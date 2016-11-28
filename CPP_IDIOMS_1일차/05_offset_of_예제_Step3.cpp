#include <stdio.h>
#include <stdlib.h>

// NODE�� data�� ��������.. data�� Node�� ����!
typedef struct _NODE
{
	struct  _NODE  *next;
} NODE;

NODE *head = 0;

void init_list()
{
	head = (NODE*)malloc(sizeof(NODE));
	head->next = 0;
}

// list ���� �Լ��� node�� �����ϰ� ��������...
// Node�� �޸� �Ҵ��� �ܺο��� ����.
void insert_front(NODE* node)
{
	node->next = head->next;
	head->next = node;
}

struct People
{
	char name[16];
	int age;
	NODE link;
};

#define offset_of(TYPE, MEMBER) (size_t)&(((TYPE*)0)->MEMBER)

void display()
{
	NODE *node = 0;
	system("cls");
	printf("[HEAD] ");

	for (node = head->next; node != 0; node = node->next)
	{
		// node�� People::link �ּ��� ���̴�.
		// link�� People �ȿ��� �󸶳� ������ �ִ��� �˾ƾ� �Ѵ�.
		People* p = (People*)((char*)node - offset_of(People, link));
		printf("-> %d ", p->age);
		// printf("-> %d ", node->data);
	}

	getchar();
}



int main()
{
	int i = 0;
	init_list();
	display();

	for (i = 0; i < 7; i++)
	{
		People* temp = (People*)malloc(sizeof(People));
		temp->age = i;

		insert_front(&temp->link);
		display();
	}
}
