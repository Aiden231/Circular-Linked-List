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
		printf("���� ����Ʈ�� ���� �����Դϴ�.\n");
	}
	// ����Ʈ�� �ϳ��� �ִ� ���
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
		printf("���� ����Ʈ�� ���� �����Դϴ�.\n");
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

// ����Ʈ ���
void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL)
	{
		printf("���� ����Ʈ�� ���� �����Դϴ�.\n\n");
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
		printf("-----�޴�-----\n");
		printf("1. Insert First\n");
		printf("2. Insert Last\n");
		printf("3. Delete First\n");
		printf("4. Delete Last\n");
		printf("5. Print List\n");
		printf("6. Exit\n");
		printf("�޴��� �����Ͻʽÿ� : ");
		scanf_s("%d", &enter);

		// ù��°�� �ֱ�
		if (enter == 1)
		{
			printf("���� ���ڸ� �Է����ּ��� : ");
			scanf_s("%d", &enter_data);
			printf("\n");

			head = insert_first(head, enter_data);
		}
		// �������� �ֱ�
		else if (enter == 2)
		{
			printf("���� ���ڸ� �Է����ּ��� : ");
			scanf_s("%d", &enter_data);
			printf("\n");

			head = insert_last(head, enter_data);
		}
		// ù��° ����
		else if (enter == 3)
		{
			if (head == NULL)
			{
				printf("���� ����Ʈ�� ��������Դϴ�.\n\n");
			}
			else
			{
				printf("ù��° ��带 �����մϴ�.\n\n");
				head = delete_first(head);
			}
		}
		// ������ ����
		else if (enter == 4)
		{
			if (head == NULL)
			{
				printf("���� ����Ʈ�� ��������Դϴ�.\n\n");
			}
			else
			{
				printf("������ ��带 �����մϴ�.\n\n");
				head = delete_last(head);
			}
		}
		// ����Ʈ ���
		else if (enter == 5)
		{
			print_list(head);
		}
		// ���α׷� ����
		else if (enter == 6)
		{
			break;
		}
		// �޴� ���Է� ��
		else
		{
			printf("�ùٸ� �޴��� �������ּ���.(ex. 1 ~ 6)\n");
		}

		getchar();
	} while (1);

	return 0;
}