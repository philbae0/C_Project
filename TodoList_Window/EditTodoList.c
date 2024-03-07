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
    printf("1. ���� ����\n");
    printf("2. ��¥ ����\n");
    printf("3. �߿䵵 ����\n");
    printf("0. �����޴� ����\n");
    printf("\n");

    return;
}

void EditTitle()
{
    int selectIdx;
    selectIdx = myList->TemporaryIdx;

    char *input_title = (char *)malloc(SIZE * sizeof(char));

    printf("\n");
    printf("�����ϰ� ���� ������ �Է��ϼ���\n");
    printf("�Է� : ");
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
        printf("\n-------���� ����Ǿ� �ִ� �׸��Դϴ�--------\n");
    }

    // (8 29 �߰�) showmyList �Լ� ����(2�� �߿� 1������ ����)
    while (1)
    {
        if (ListNum == 0)
        {
            printf("����Ǿ� �ִ� �� ���� �����ϴ�\n");
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

            printf("���� : ");
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
                printf("������ �Ϸ��Ͻðڽ��ϱ�?\n");
                printf("Ȯ�� : 1, ��� : 0\n");
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
                printf("�߸� �����ϼ̽��ϴ�\n");
                printf("�ٽ� �����Ͻʽÿ�\n");
            }
        }

        printf("\n-------���� ó���� �� �� ���� �Դϴ�-------\n");
        ShowTodoList(myList->TemporaryIdx);
        CheckConfimed();
    }
}