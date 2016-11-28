#include <stdio.h>
#include <stdlib.h>

// NODE에 data를 넣지말고.. data에 Node를 넣자!
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

// list 관련 함수가 node만 조작하게 변경하자...
// Node의 메모리 할당은 외부에서 하자.
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
		// node는 People::link 주소일 뿐이다.
		// link가 People 안에서 얼마나 떨어져 있는지 알아야 한다.
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
