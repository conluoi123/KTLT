#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <regex>
#include <iomanip>
// su dung format 
using namespace std;
// Khai bao cac struct can thiet 
struct date {
	int d, m, y;
};

struct Schoolyear
{
	int Sta_year, End_year;
};

struct Semester {
	int InforSemester;
	date Star, End;
	Schoolyear Sch_year;
};

struct User {
	bool isStaff;
	int  academic;
	string id;
	string pass; //123456
	string firstname;
	string lastname;
	string gender;
	string SocialID;
	string className;
	date birthday;
};

struct nodeUser {
	User data;
	nodeUser* prev;
	nodeUser* next;
};

struct listUser {
	nodeUser* head;
	nodeUser* tail;
};

struct CourseMark {
	float TotalMark;
	float FinalMark;
	float MidtermMark;
	float OtherMark;
};

struct StuCourse 
{
	string id;
	CourseMark Mark;
};

struct nodeStuCourse 
{
	StuCourse data;
	nodeStuCourse* next;
	nodeStuCourse* prev;
};

struct listStuCourse 
{
	nodeStuCourse* head;
	nodeStuCourse* tail;
};

struct Course {
	int Credits;
	int maxStudents = 50;
	string id;
	string CourseName;
	string ClassName;
	string TeacherName;
	string wDay;
	string Session;
	listStuCourse List_st;
	//int numberRegistered = 0;
	//int academicYear;
};

struct nodeCourse {
	Course data;
	nodeCourse* next;
	nodeCourse* prev;
};

struct listCourse {
	nodeCourse* head;
	nodeCourse* tail;
};

struct Student {
	int  academic;
	string id;
	string firstname;
	string lastname;
	string gender;
	string SocialID;
	string className;
	date birthday;
	listCourse LStu_Courses;

};

struct nodeStudent {
	Student data;
	nodeStudent* next;
	nodeStudent* prev;
};

struct listStudent {
	nodeStudent* head;
	nodeStudent* tail;
};

struct Class {
	string ClassName;
	string ClassPath;
	listStudent List_st;
	int  academic;
};

struct nodeClass {
	Class data;
	nodeClass* next;
	nodeClass* prev;
};

struct listClass {
	nodeClass* head;
	nodeClass* tail;
};
// Biến toàn cục 
extern nodeUser* userLogin;
extern listUser l_User;
extern Schoolyear CurSchoolyear;
extern Semester CurSemester;
extern listClass l_Class;
extern listCourse l_Course;
extern listStudent l_AllStudent;
extern string PathSchoolyear;
extern string PathSemester;
//log 
nodeUser* find(string id, string pass);
void solveLogin();
nodeUser* find(string id, string pass);
// system 

void getListUsers(listUser& l);
date SttoDate(string st);
string DatetoSt(date dt);
nodeUser* createNodeUser(User val);
nodeUser* input(fstream& f);
// chuyển thông tin thành node để phục vụ cho hàm get 
nodeStudent* inputStudent(fstream& f, int aca, string cla_name);
nodeClass* inputClass(fstream& f);
nodeClass* createNodeClass(Class val);
nodeCourse* createNodeCourse(Course val);
nodeStuCourse* createNodeStuCourse(StuCourse val);

nodeStuCourse* inputStuCourse(fstream& f);
nodeCourse* inputCourse(fstream& f, string Path);
void initList(listUser& l);
void initList(listStudent& l);
void initList(listClass& l);
void initList(listCourse& l);
void initList(listStuCourse& l);
void addUser(listUser& l, nodeUser* p);
void addStudent(listStudent& l, nodeStudent* Stu);
void addClass(listClass& l, nodeClass* cla);
void addCourse(listCourse& l, nodeCourse* Cour);
void addStuCourse(listStuCourse& l, nodeStuCourse* val);
void getListStudent(listStudent& l, string Path, int aca, string cla_name);
void getListClass(listClass& l, string PathSchoolyear);
void getListStuCourse(listStuCourse& l, string Path);
void getListCourse(listCourse& l, string Path);
void getListAllStudent(listStudent& l, listClass& lClass);
void AddListUsers(listUser& l_Us, listStudent l_St);
void MergeList(listStudent& x, listStudent& y);

// menu 
void staffMenu();
void LoadStaff();
void log();
void ProfileStaff();
void ChangePassword();
void CreateSchoolYear();
void CreateSemester();
void LoadCourseMenu();
void ViewMenu();

