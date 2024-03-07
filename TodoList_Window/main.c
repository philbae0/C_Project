#include <stdio.h>
#include <stdlib.h>
#include "BasicInfo.h"
#include "InputTodoList.h"
#include "CompleteCheck.h"
#include "EditTodoList.h"
#include "DeleteTodoList.h"
#pragma warning(disable: 4996)

enum
{
    INPUT = 1,
    COMPLETEDCHECK,
    MODIFY,
    DELETE,
    SHOWLIST,
    SHOWCOMPLIST,
    TERMINATE = 0
};

int ListNum = 0, CompNum = 0; // 완료처리한 항목들을 저장하는 배열의 인덱스

int main()
{
    int choice;
    int comchecker, deletechecker;

    DataInit();

    while (1)
    {
        system("cls");
        if (ListNum != 0)
        {
            ShowMyList(ListNum);
        }

        ShowMenu();
        printf("선택 : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case (INPUT):
            INPUT_Function(ListNum);
            ++ListNum;
            break;

        case (COMPLETEDCHECK):
            comchecker = CompleteCheck(ListNum, CompNum);
            if (comchecker == 1)
            {
                continue;
            }
            else
            {
                --ListNum;
                ++CompNum;
            }
            break;

        case (MODIFY):
            EditTodoList(ListNum);
            break;

        case (DELETE):
            deletechecker = DeleteTodoList(ListNum);
            if (deletechecker == 1)
            {
                continue;
            }
            else
            {
                --ListNum;
            }
            break;

        case (SHOWLIST):
            ShowMyList(ListNum);
            CheckConfimed();
            break;

        case (SHOWCOMPLIST):
            ShowMyCompList(CompNum);
            CheckConfimed();
            break;

        case (TERMINATE):
            return 0;

        default:
            printf("잘못 선택하셨습니다.\n");
            printf("다시 선택하십시오\n");
            CheckConfimed();
        }
    }
}