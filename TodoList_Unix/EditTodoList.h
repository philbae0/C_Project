#ifndef __EDITTODOLIST_H__
#define __EDITTODOLIST_H__

#include "EditTodoList.h"

void ShowModifyMenu();
void EditTitle(int LastListIdx);
void MakeNewDate(int selectIdx);
void ModifyDate(int selectIdx);
void EditDate(int LastListIdx);
void ChooseImportanceMenu(int selectIdx);
void EditImportance(int LastListIdx);
void EditTodoList(int LastListIdx);

#endif