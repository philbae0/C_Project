#include "BasicInfo.h"
#include <stdio.h>
#include <stdlib.h>

void DataInit()
{
    for (int i = 0; i < SIZE; ++i)
    {
        myList[i].Importance.importance = 0;
        myList[i].Importance.ImportanceChecker = 0;
        myList[i].Date.DateChecker = 0;
    }
}

void ShowMenu()
{
    // printf("\n");
    printf("----------------Menu----------------\n");
    printf("1. 할 일 입력하기\n");
    printf("2. 할 일 완료 체크하기\n");
    printf("3. 할 일 수정하기\n");
    printf("4. 할 일 삭제하기\n");
    printf("5. 현재 남은 할 일 출력\n");
    printf("6. 완료된 일정 출력\n");
    printf("0. 프로그램 종료\n");
    printf("\n");

    return;
}

void ShowTodoList(int idx)
{
    printf("\n");

    printf("항목 번호 : %d\n", idx + 1);
    printf("할 일 이름 : %s\n", myList[idx].Title);

    if (myList[idx].Date.DateChecker == 1)
        printf("날짜 : %d월 %d일\n", myList[idx].Date.date.month, myList[idx].Date.date.day);

    if (myList[idx].Importance.ImportanceChecker == 1)
        printf("중요도 : %d\n", myList[idx].Importance.importance);

    printf("\n");
}

int ShowMyList(int ListNum)
{
    system("clear");
    int check;

    if (ListNum == 0)
    {
        printf("현재 남은 할 일이 없습니다\n");
        printf("\n");

        return -1;
    }

    for (int i = 0; i < ListNum; ++i)
    {
        ShowTodoList(i);
    }

    return 0;
}

void Select_IDX_In_List(int LastListIdx)
{
    int selectNum;

    ShowMyList(LastListIdx);
    printf("수정 or 삭제 or 완료처리를 하고 싶은 항목의 번호를 입력하세요 : ");

    getchar();

    scanf("%d", &selectNum);

    if (selectNum - 1 <= LastListIdx)
    {
        myList->TemporaryIdx = selectNum - 1;
    }
    else
    {
        printf("해당 항목이 없습니다\n");
    }
}

void ShowRestWork(int ListNum)
{
    if (ListNum == 0)
    {
        return;
    }
    else
    {
        printf("남은 할 일입니다\n");
        printf("\n");
        ShowMyList(ListNum);
    }
}

void CheckConfimed()
{
    int check;
    while (1)
    {
        printf("확인하셨으면 1을 입력해주세요 : ");

        getchar();

        scanf("%d", &check);

        if (check == 1)
            return;
        else
        {
            printf("다시 선택해주세요\n");
            printf("\n");
            continue;
        }
    }
}