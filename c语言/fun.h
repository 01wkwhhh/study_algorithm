#pragma once
#ifndef _FUN_H
#define _FUN_H
struct LL
{
	int cname;
	int x;
	char department[20];
	int age;
	char name[20];
	char position[20];
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int absent;
	int sum;
	char photo[20];
	struct LL* next;
};
void shuru(struct LL** head,int cname, int x, char department[20], int age, char name[20], char position[20], int year, int month, int day, int hour, int minute,int absent,int sum,char photo[20]);
void back(struct LL** head, struct LL* temp);
void delete1(struct LL** head, int x);
int add1(struct LL** head, int s);
void print(struct LL** head);
void release(struct LL* temp);
void pii(struct LL** head);
int search(char epartment[20]);
int login();
void sign_up();
int search0(struct LL* head);
void punch_in(struct LL** head);
int information1(struct LL** head,int res0);
int information(struct LL** head);
int tinormation(struct LL* head);
int tinormation1(struct LL** head, char* a, int res0);
void statistics(struct LL* temp);
void input(struct LL* temp);
void outup(struct LL* temp);
void block(struct LL* temp, int x);
void end(struct LL* temp);
void blessing();
char* blessing0();
#endif