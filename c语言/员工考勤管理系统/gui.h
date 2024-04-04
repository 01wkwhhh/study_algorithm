#pragma once
#ifndef _GUI_H
#define _GUI_H
int home();
int ECI();
void pop_up(const char a[80]);
char* sis();
int HOI(char a[100]);
int box(const char a[20]);
char* box0(const char a[20]);
void table(struct LL* head);
int add_gui(struct LL* temp);
void table1(struct LL* head);
void information_gui(struct LL* head,int res0);
void tinormation1_gui(struct LL* head, int res0, char* a);
void search_gui(struct LL* temp);
#endif