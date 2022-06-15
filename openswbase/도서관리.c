#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define S_SIZE 20
#define _CRT_SECURE_NO_WARNINGS

struct NODE {
	char title[S_SIZE];
	int year;
	int isRental;
	struct NODE* next;
};

int main(void)
{
	struct NODE* head = NULL;

	char buffer[S_SIZE];
	char bookNameBuffer[S_SIZE];
	char bookCreateYear[S_SIZE];

	printf("������ ���� ���α׷�\n\n");

	int isPlay = 1;

	while (isPlay)
	{
		printf("=====================\n");
		printf("0. �ű� ���\n");
		printf("1. ���� ����\n");
		printf("2. ���� �ݳ�\n");
		printf("3. ��� ���\n");
		printf("4. ����\n");
		printf("=====================\n");

		gets_s(buffer, S_SIZE);

		switch (buffer[0])
		{
		case '0': // �ű� ���
			printf("����� å�� ������ �Է��Ͻÿ� : ");
			gets_s(bookNameBuffer, S_SIZE);
			printf("å�� ���� ������ �Է��Ͻÿ� : ");
			gets_s(bookCreateYear, S_SIZE);

			struct NODE* newNode = (struct NODE*)malloc(sizeof(struct NODE));
			strcpy(newNode->title, bookNameBuffer);
			newNode->year = atoi(bookCreateYear);
			newNode->isRental = 0;
			newNode->next = NULL;

			if (head == NULL)
			{
				head = newNode;
			}
			else
			{
				struct NODE* nextNode = head;
				while (nextNode->next != NULL)
					nextNode = nextNode->next;

				nextNode->next = newNode;
			}

			printf("%s�� ���������� ����Ͽ����ϴ�.\n", bookNameBuffer);
			break;
		case '1': // ���� ����
			printf("�뿩�� å�� ������ �Է��Ͻÿ� : ");
			gets_s(bookNameBuffer, S_SIZE);

			if (head == NULL)
			{
				printf("Error list is null");
				break;
			}
			else
			{
				struct NODE* nextNode = head;
				while (1)
				{
					if (strcmp(nextNode->title, bookNameBuffer) != 0)
						nextNode = nextNode->next;
					else
					{
						nextNode->isRental++;
						break;
					}
				}
			}

			printf("%s �� ���⿡ �����Ͽ����ϴ�.\n", bookNameBuffer);
			break;
		case '2': // ���� �ݳ�
			printf("�ݳ��� å�� ������ �Է��Ͻÿ� : ");
			gets_s(bookNameBuffer, S_SIZE);

			if (head == NULL)
			{
				printf("Error list is null");
				break;
			}
			else
			{
				struct NODE* nextNode = head;
				while (1)
				{
					if (strcmp(nextNode->title, bookNameBuffer) != 0)
						nextNode = nextNode->next;
					else
					{
						nextNode->isRental--;
						break;
					}
				}
			}

			printf("%s �� �ݳ��� �����Ͽ����ϴ�.\n", bookNameBuffer);
			break;
		case '3': // ��� ���
		{
			struct NODE* nextNode = head;
			int bookCount = 0;
			while (1)
			{
				if (nextNode != NULL)
				{
					printf("���� %d, ���ǿ��� %d, ���⿩�� %d, ���� %s\n", bookCount++, nextNode->year, nextNode->isRental, nextNode->title);

					nextNode = nextNode->next;
				}
				else
					break;
			}
		}
		break;
		case '4': // ����
			isPlay = 0;
			break;
		}
	}

	return 0;
}
