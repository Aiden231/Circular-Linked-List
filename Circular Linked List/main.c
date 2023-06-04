#include <stdio.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
	}
	
	return head;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;
		head->link = node;
		head = node;
	}

	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;

	if (head == NULL)
	{
		printf("현재 리스트는 공백 상태입니다.\n");
	}
	// 리스트에 하나만 있는 경우
	else
	{
		removed = head->link;
		head->link = removed->link;
		free(removed);
	}
	return head;
}

ListNode* delete_last(ListNode* head)
{
	ListNode* removed;
	ListNode* p;

	if (head == NULL)
	{
		printf("현재 리스트는 공백 상태입니다.\n");
	}
	else
	{
		removed = head;

		p = head->link;
		while (p->link != head)
		{
			p = p->link;
		}
		p->link = head->link;
		head = p;
		free(removed);
	}
	return head;
}

// 리스트 출력
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL)
	{
		printf("현재 리스트는 공백 상태입니다.\n\n");
		return;
	}
	else
	{
		p = head->link;
		do {
			printf("%d->", p->data);
			p = p->link;
		} while (p != head->link);
		printf("\n\n");
	}
}

int main()
{
	int enter = 0;
	element enter_data;

	ListNode* head = NULL;

	do {
		printf("-----메뉴-----\n");
		printf("1. Insert First\n");
		printf("2. Insert Last\n");
		printf("3. Delete First\n");
		printf("4. Delete Last\n");
		printf("5. Print List\n");
		printf("6. Exit\n");
		printf("메뉴를 선택하십시오 : ");
		scanf_s("%d", &enter);

		// 첫번째에 넣기
		if (enter == 1)
		{
			printf("넣을 숫자를 입력해주세요 : ");
			scanf_s("%d", &enter_data);
			printf("\n");

			head = insert_first(head, enter_data);
		}
		// 마지막에 넣기
		else if (enter == 2)
		{
			printf("넣을 숫자를 입력해주세요 : ");
			scanf_s("%d", &enter_data);
			printf("\n");

			head = insert_last(head, enter_data);
		}
		// 첫번째 삭제
		else if (enter == 3)
		{
			if (head == NULL)
			{
				printf("현재 리스트는 공백상태입니다.\n\n");
			}
			else
			{
				printf("첫번째 노드를 삭제합니다.\n\n");
				head = delete_first(head);
			}
		}
		// 마지막 삭제
		else if (enter == 4)
		{
			if (head == NULL)
			{
				printf("현재 리스트는 공백상태입니다.\n\n");
			}
			else
			{
				printf("마지막 노드를 삭제합니다.\n\n");
				head = delete_last(head);
			}
		}
		// 리스트 출력
		else if (enter == 5)
		{
			print_list(head);
		}
		// 프로그램 종료
		else if (enter == 6)
		{
			break;
		}
		// 메뉴 오입력 시
		else
		{
			printf("올바른 메뉴를 선택해주세요.(ex. 1 ~ 6)\n");
		}

		getchar();
	} while (1);

	return 0;
}