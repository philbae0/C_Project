#include "BasicInfo.h"
#include "EditImportance.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable : 4996)

void ChooseImportanceMenu(int selectIdx)
{
    char choice;
    int *importance;

    if (myList[selectIdx].Importance.ImportanceChecker == 0)
    {
        printf("\n");
        printf("현재 저장된 중요도가 없습니다.\n");
        printf("\n");
        printf("중요도를 새로 추가하시겠습니까? (y/n)\n");
        printf("선택 : ");

        getchar();

        scanf("%c", &choice);

        if (choice == 'y')
        {
            importance = (int *)malloc(sizeof(int));
            while (1)
            {
                printf("\n");
                printf("새로운 중요도를 부여하십시오. (1, 2, 3)\n");
                printf("선택 : ");

                getchar();

                scanf("%d", importance);
                if (*importance == 1 || *importance == 2 || *importance == 3)
                {
                    myList[selectIdx].Importance.importance = *importance;
                    myList[selectIdx].Importance.ImportanceChecker = 1;
                    break;
                }
                else
                {
                    printf("유효하지 않은 형식입니다\n");
                    printf("\n");
                }
            }

            free(importance);
            return;
        }
        else if (choice == 'n')
        {
            printf("중요도를 수정하지 않았습니다\n");
            printf("수정 선택 화면으로 돌아갑니다");
            return;
        }
    }
    else if (myList[selectIdx].Importance.ImportanceChecker == 1)
    {
        while (1)
        {
            printf("\n");
            printf("현재 저장된 중요도가 있습니다.\n");
            printf("현재 저장된 중요도는 %d입니다\n", myList[selectIdx].Importance.importance);
            printf("\n");
            printf("중요도를 수정하시겠습니까?\n");
            printf("선택 (y/n) : ");

            getchar();

            scanf("%c", &choice);

            if (choice == 'y')
            {
                int choice_menu;

                printf("\n");
                printf("------------Menu------------\n");
                printf("1. 현재 저장된 중요도를 수정\n");
                printf("2. 현재 저장된 중요도를 삭제\n");
                printf("선택 (1 or 2) : ");

                getchar();

                scanf("%d", &choice_menu);

                if (choice_menu == 1)
                {
                    importance = (int *)malloc(sizeof(int));

                    printf("\n");
                    printf("현재 저장된 중요도를 수정합니다\n");
                    while (1)
                    {
                        printf("새로 부여할 중요도를 입력하세요 : ");
                        scanf("%d", importance);
                        if (*importance == 1 || *importance == 2 || *importance == 3)
                        {
                            myList[selectIdx].Importance.importance = *importance;
                            break;
                        }
                        else
                        {
                            printf("\n");
                            printf("유효하지 않은 형식입니다\n");
                        }
                    }

                    free(importance);
                    return;
                }
                else if (choice_menu == 2)
                {
                    printf("\n");
                    printf("현재 저장된 중요도를 삭제합니다\n");
                    myList[selectIdx].Importance.ImportanceChecker = 0;
                    return;
                }
                else
                {
                    printf("\n");
                    printf("잘못된 선택입니다.\n");
                    printf("다시 선택하세요\n");
                }
            }
            else if (choice == 'n')
            {
                printf("\n");
                printf("중요도를 수정하지 않았습니다\n");
                return;
            }
        }
    }
}

void EditImportance()
{
    int selectIdx;
    selectIdx = myList->TemporaryIdx;

    ChooseImportanceMenu(selectIdx);
    return;
}