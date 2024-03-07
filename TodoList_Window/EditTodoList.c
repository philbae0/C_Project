#include "BasicInfo.h"
#include "EditDate.h"
#include "EditImportance.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)

void ShowModifyMenu()
{
    // printf("\n");
    printf("-------------------Menu-------------------\n");
    printf("1. 제목 수정\n");
    printf("2. 날짜 수정\n");
    printf("3. 중요도 수정\n");
    printf("0. 수정메뉴 종료\n");
    printf("\n");

    return;
}

void EditTitle()
{
    int selectIdx;
    selectIdx = myList->TemporaryIdx;

    char *input_title = (char *)malloc(SIZE * sizeof(char));

    printf("\n");
    printf("수정하고 싶은 제목을 입력하세요\n");
    printf("입력 : ");
    getchar();
    scanf("%[^\n]", input_title);

    strcpy(myList[selectIdx].Title, input_title);

    free(input_title);
}

void EditTodoList(int ListNum)
{
    int choice;
    int answer;
    int result;
    int temp;

    enum
    {
        TITLE = 1,
        DATE,
        IMPORTANCE,
        COLOR,
        TERMINATE = 0
    };

    system("cls");

    if (ListNum != 0)
    {
        printf("\n-------현재 저장되어 있는 항목입니다--------\n");
    }

    // (8 29 추가) showmyList 함수 삭제(2번 중에 1번으로 줄임)
    while (1)
    {
        if (ListNum == 0)
        {
            printf("저장되어 있는 할 일이 없습니다\n");
            printf("\n");
            CheckConfimed();
            return;
        }

        result = ShowChooseMenu(ListNum);

        if (result == 1)
        {
            return;
        }

        Select_IDX_In_List(ListNum);

        system("cls");

        while (1)
        {
            system("cls");

            ShowTodoList(myList->TemporaryIdx);

            ShowModifyMenu();

            printf("선택 : ");
            getchar();
            scanf("%d", &choice);

            if (choice == TITLE)
            {
                EditTitle();
            }
            else if (choice == DATE)
            {
                EditDate();
            }
            else if (choice == IMPORTANCE)
            {
                EditImportance();
            }
            else if (choice == TERMINATE)
            {
                printf("\n");
                printf("수정을 완료하시겠습니까?\n");
                printf("확인 : 1, 취소 : 0\n");
                scanf("%d", &answer);

                if (answer == 1)
                {
                    break;
                }
                else
                    continue;
            }
            else
            {
                printf("잘못 선택하셨습니다\n");
                printf("다시 선택하십시오\n");
            }
        }

        printf("\n-------수정 처리된 할 일 내역 입니다-------\n");
        ShowTodoList(myList->TemporaryIdx);
        CheckConfimed();
    }
}