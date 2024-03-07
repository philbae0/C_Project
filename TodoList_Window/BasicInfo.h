#ifndef __BASICINFO_H__
#define __BASICINFO_H__

#define SIZE 100

typedef struct _detailDate
{
    int month; // 날짜의 월(Month)
    int day;   // 날짜의 일(Day)
} DetailDate;

typedef struct _date
{
    DetailDate date; // 시작 날짜 및 해야하는 날짜
    int DateChecker;
} Date;

typedef struct _importance
{
    int importance;
    int ImportanceChecker;
} Importance;

typedef struct _todolist
{
    Date Date; // 할 일의 날짜
    Importance Importance;
    // 중요도는 1, 2, 3으로 우선순위를 부여합니다
    int TemporaryIdx; // 구조체 변수 추가
    char Title[SIZE]; // 할 일의 제목
} List;

List myCompList[SIZE]; // 완료처리를 한 항목들을 저장한 배열
List myList[SIZE];     // 할 일들을 저장할 배열

void DataInit();
void ShowMenu();
void ShowTodoList(int idx);
int ShowMyList(int ListNum);
void Select_IDX_In_List(int LastListIdx);
void ShowRestWork(int ListNum);
void CheckConfimed();
int ShowChooseMenu(int ListNum);

#endif