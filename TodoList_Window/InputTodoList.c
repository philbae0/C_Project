#include "BasicInfo.h"
#include "InputTodoList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

void Input_Title(int LastListIdx)
{
	char Title[100] = {'\0'};
	printf("제목을 입력해주세요.\n");
	getchar();
	scanf("%[^\n]", Title); // 공백포함, 문장 전체

	strcpy(myList[LastListIdx].Title, Title);
}

void Input_Date(int LastListIdx)
{
	char dateset;
	int check;
	int month, day;
	while (1)
	{

		printf("\n");
		printf("날짜를 지정하시겠습니까? [y / n]\n");
		getchar();
		scanf("%c", &dateset);

		if (dateset == 'y')
		{
			while (1)
			{
				printf("\n");
				printf("날짜를 입력해주세요. [ex) 3 29]\n");

				getchar();

				scanf("%d %d", &month, &day);

				if (!month || !day)
				{
					printf("\n");
					printf("잘못된 형식입니다.\n");
					printf("다시입력해주세요.\n");
					while (getchar() != '\n')
						;
				}
				else
				{
					break;
				}
			}

			myList[LastListIdx].Date.date.month = month;
			myList[LastListIdx].Date.date.day = day;

			myList[LastListIdx].Date.DateChecker = 1;
			break;
		}
		else if (dateset == 'n')
		{
			myList[LastListIdx].Date.DateChecker = 0;
			break;
		}
		else
		{
			printf("\n");
			printf("잘못 입력하셨습니다.\n");
			printf("다시 선택해주세요.\n");
			while (getchar() != '\n')
				;
			printf("아무키나 입력 후 엔터를 눌러주세요.\n");
			getchar();
		}
	}
}

void Set_Importance(int LastListIdx)
{
	char importanceset;
	int importance;
	while (1)
	{
		printf("\n");
		printf("중요도를 설정하시겠습니까? [y / n]\n");

		getchar();

		scanf("%c", &importanceset);
		if (importanceset == 'y')
		{
			while (1)
			{
				printf("\n");
				printf("중요도는 얼마입니까? [1 / 2 / 3]\n");
				getchar();

				scanf("%d", &importance);

				if (!importance)
				{
					printf("\n");
					printf("잘못된 형식입니다.\n");
					printf("다시입력해주세요.\n");
					while (getchar() != '\n')
						;
				}
				else
				{
					if (importance == 1 || importance == 2 || importance == 3)
					{
						myList[LastListIdx].Importance.importance = importance;
						myList[LastListIdx].Importance.ImportanceChecker = 1;
						break;
					}
					else
					{
						printf("\n");
						printf("유효하지 않은 형식입니다.\n");
						printf("다시 선택해주세요.\n");
					}
				}
			}
			return;
		}
		else if (importanceset == 'n')
		{
			myList[LastListIdx].Importance.ImportanceChecker = 0;
			return;
		}
		else
		{
			printf("\n");
			printf("유효하지 않은 형식입니다.\n");
			printf("다시 선택해주세요.\n");
			while (getchar() != '\n')
				;
			printf("아무키나 입력 후 엔터를 눌러주세요.\n");
			getchar();
		}
	}
}

void INPUT_Function(int ListNum)
{
	system("cls");
	Input_Title(ListNum);
	Input_Date(ListNum);
	Set_Importance(ListNum);
}