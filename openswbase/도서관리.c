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

	printf("도서관 관리 프로그램\n\n");

	int isPlay = 1;

	while (isPlay)
	{
		printf("=====================\n");
		printf("0. 신규 등록\n");
		printf("1. 도서 대출\n");
		printf("2. 도서 반납\n");
		printf("3. 목록 출력\n");
		printf("4. 종료\n");
		printf("=====================\n");

		gets_s(buffer, S_SIZE);

		switch (buffer[0])
		{
		case '0': // 신규 등록
			printf("등록할 책의 제목을 입력하시오 : ");
			gets_s(bookNameBuffer, S_SIZE);
			printf("책의 출판 연도를 입력하시오 : ");
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

			printf("%s를 성공적으로 등록하였습니다.\n", bookNameBuffer);
			break;
		case '1': // 도서 대출
			printf("대여할 책의 제목을 입력하시오 : ");
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

			printf("%s 를 대출에 성공하였습니다.\n", bookNameBuffer);
			break;
		case '2': // 도서 반납
			printf("반납할 책의 제목을 입력하시오 : ");
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

			printf("%s 를 반납에 성공하였습니다.\n", bookNameBuffer);
			break;
		case '3': // 목록 출력
		{
			struct NODE* nextNode = head;
			int bookCount = 0;
			while (1)
			{
				if (nextNode != NULL)
				{
					printf("순서 %d, 출판연도 %d, 대출여부 %d, 제목 %s\n", bookCount++, nextNode->year, nextNode->isRental, nextNode->title);

					nextNode = nextNode->next;
				}
				else
					break;
			}
		}
		break;
		case '4': // 종료
			isPlay = 0;
			break;
		}
	}

	return 0;
}
