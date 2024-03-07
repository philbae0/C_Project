#include <stdio.h>
#include <stdlib.h>
#include "BasicInfo.h"
#include "DeleteTodoList.h"

#pragma warning(disable : 4996)

int DeleteTodoList(int ListNum) //int형으로 변경
{
    int result;

    system("cls");

    if (ListNum == 0)
    {
        printf("\n삭제할 일정이 없습니다. \n");
        printf("\n");
        CheckConfimed();
        return 1; // 추가
    }

    result = ShowChooseMenu(ListNum);

    if (result == 1)
    {
        return;
    }

    system("cls");

    ShowMyList(ListNum);

    int num;

    while (1)
    {
        printf("삭제할 일정의 번호를 입력하세요 : ");
        scanf("%d", &num);

        if (num < 1 || num > ListNum)
        {
            printf("일정을 찾지 못하였습니다. \n");
            printf("다시 선택하세요. \n");
        }
        else
        {
            break;
        }
    }

    num -= 1;

    // 삭제 처리 재확인 질문

    printf("\n해당 일정을 삭제했습니다.\n");
    ShowTodoList(num);

    for (int i = num; i < ListNum - num; ++i)
    {
        myList[i] = myList[i + 1];
    }
    return 0; //추가
}