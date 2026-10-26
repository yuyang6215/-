#pragma once
#include<vector>
#include"Book.h"

extern std::vector<Book> books;

void ShowBooks();
void AddBook();
int ManagerTitle();
void Manager();
void FindBooks();
void DeleteBooks();
void ModifyBooks();
int InputInt();
float InputFloat();
bool IsBlank(const std::string& str);