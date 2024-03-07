#ifndef __EDITTODOLIST_H__
#define __EDITTODOLIST_H__

#include "EditTodoList.h"

void ShowModifyMenu();
void EditTitle();
void MakeNewDate(int selectIdx);
void ModifyDate(int selectIdx);
void EditDate();
void ChooseImportanceMenu(int selectIdx);
void EditImportance();
void EditTodoList(int LastListIdx);

#endif