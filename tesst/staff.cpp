#include "function.h"
date SttoDate(string st) 
{
	date val;
	val.d = stoi(st.substr(0, st.find('/')));
	st.erase(0, st.find('/') + 1);
	val.m = stoi(st.substr(0, st.find('/')));
	st.erase(0, st.find('/') + 1);
	val.y = stoi(st.substr(0, st.find('/')));
	st.erase(0, st.find('/') + 1);
	return val;
}
string DatetoSt(date dt) 
{
	string st = "";
	if (dt.d < 10) st += "0";
	st += to_string(dt.d) + "/";
	if (dt.m < 10) st += "0";
	st += to_string(dt.m) + "/";
	st += to_string(dt.y);
	return st;
}
nodeUser* createNodeUser(User val)
{
	nodeUser* tmp = new nodeUser;
	tmp->data = val;
	tmp->next = tmp->prev = nullptr;
	return tmp;
}
nodeClass* createNodeClass(Class val) {
	nodeClass* tmp = new nodeClass;
	tmp->data = val;
	tmp->next = tmp->prev = NULL;
	return tmp;
}

nodeCourse* createNodeCourse(Course val) {
	nodeCourse* tmp = new nodeCourse;
	tmp->data = val;
	tmp->next = tmp->prev = NULL;
	return tmp;
}

nodeStuCourse* createNodeStuCourse(StuCourse val) {
	nodeStuCourse* tmp = new nodeStuCourse;
	tmp->data = val;
	tmp->next = tmp->prev = NULL;
	return tmp;
}

void initList(listUser& l) 
{
	l.head = l.tail = NULL;
}

void initList(listStudent& l) 
{
	l.head = l.tail = NULL;
}

void initList(listClass& l) 
{
	l.head = l.tail = NULL;
}

void initList(listCourse& l) 
{
	l.head = l.tail = NULL;
}

void initList(listStuCourse& l) 
{
	l.head = l.tail = NULL;
}
// List hàm thực hiện danh sách thêm node vào một list và thêm vào cuối 
void addUser(listUser& l, nodeUser* p)
{
	if (p == NULL)
		return;
	if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else
	{
		l.tail->next = p;
		p->prev = l.tail;
		l.tail = p;

	}
}
void addStudent(listStudent& l, nodeStudent* Stu) {
	if (Stu == nullptr)
		return;
	else
	{
		if (l.head == nullptr)
		{
			l.head = l.tail = nullptr;
		}
		else
		{
			l.tail->next = Stu;
			Stu->prev = l.tail;
			l.tail = Stu;
		}
	}
}
void addClass(listClass& l, nodeClass* cla) 
{
	if (cla == NULL) return;
	if (l.head == NULL) 
	{
		l.head = l.tail = cla;
	}
	else {
		l.tail->next = cla;
		cla->prev = l.tail;
		l.tail = cla;
	}
}
void addCourse(listCourse& l, nodeCourse* Cour)
{
	if (Cour == NULL) return;
	if (l.head == NULL) {
		l.head = l.tail = Cour;
	}
	else {
		l.tail->next = Cour;
		Cour->prev = l.tail;
		l.tail = Cour;
	}
}
void addStuCourse(listStuCourse& l, nodeStuCourse* val) 
{
	if (val == NULL) return;
	if (l.head == NULL) {
		l.head = l.tail = val;
	}
	else {
		l.tail->next = val;
		val->prev = l.tail;
		l.tail = val;
	}
}
nodeUser* input(fstream& f)
{
	User val;
	getline(f, val.id, ',');
	if (val.id == "") return NULL;
	getline(f, val.pass, ',');
	getline(f, val.firstname, ',');
	getline(f, val.lastname, ',');
	getline(f, val.gender, ',');
	string tmp;
	getline(f, tmp, ',');
	val.birthday = SttoDate(tmp);
	getline(f, val.SocialID, ',');
	getline(f, tmp, ',');
	val.academic = stoi(tmp);
	getline(f, val.className, ',');
	getline(f, tmp, '\n');
	if (tmp == "TRUE") val.isStaff = true;
	else val.isStaff = false;
	return createNodeUser(val);
}
nodeStudent* inputStudent(fstream& f, int aca, string cla_name)
{
	Student value; 
	// cái hàng đầu chứa thông tin -> bỏ thông tin của hàng đầu
	string tmp; 
	getline(f, tmp, ',');
	// Khong doc duoc thi dung lai 
	if (tmp == "")
		return NULL;
	getline(f, value.id, ',');
	getline(f, value.firstname, ',');
	getline(f, value.lastname, ',');
	getline(f, value.gender, ',');
	getline(f, tmp, ',');
	value.birthday = SttoDate(tmp);
	// Kết thức quá trình đọc 
	getline(f, value.SocialID, '\n');
	// Gán tên môn học và tên lớp 
	value.academic = aca; // tín chỉ 
	value.className = cla_name;  // tên lớp 
	nodeStudent* p = new nodeStudent;
	p->data = value;
	p->prev = p->next = nullptr;
	return p;
}
nodeClass* inputClass(fstream& f) 
{
	Class val;
	getline(f, val.ClassName, ',');
	if (val.ClassName == "") return NULL;
	getline(f, val.ClassPath, ',');
	string tmp;
	getline(f, tmp, '\n');
	val.academic = stoi(tmp);
	if (val.academic < CurSchoolyear.Sta_year - 3) return NULL;
	getListStudent(val.List_st, val.ClassPath, val.academic, val.ClassName);
	return createNodeClass(val);
}
nodeStuCourse* inputStuCourse(fstream& f) 
{
	StuCourse val;
	string tmp;
	getline(f, tmp, ',');
	if (tmp == "") return NULL;
	getline(f, val.id, ',');
	getline(f, tmp, ',');
	if (tmp == "") tmp = '0';
	val.Mark.TotalMark = stof(tmp);
	getline(f, tmp, ',');
	if (tmp == "") tmp = '0';
	val.Mark.FinalMark = stof(tmp);
	getline(f, tmp, ',');
	if (tmp == "") tmp = '0';
	val.Mark.MidtermMark = stof(tmp);
	getline(f, tmp, '\n');
	if (tmp == "") tmp = '0';
	val.Mark.OtherMark = stof(tmp);
	return createNodeStuCourse(val);
}

nodeCourse* inputCourse(fstream& f, string Path)
{
	Course val;
	getline(f, val.id, ',');
	if (val.id == "") return NULL;
	getline(f, val.CourseName, ',');
	getline(f, val.ClassName, ',');
	getline(f, val.TeacherName, ',');
	string tmp;
	getline(f, tmp, ',');
	val.Credits = stoi(tmp);
	getline(f, tmp, ',');
	val.maxStudents = stoi(tmp);
	getline(f, val.wDay, ',');
	getline(f, val.Session, '\n');
	getListStuCourse(val.List_st, Path + "\\" + val.id + ".csv");
	return createNodeCourse(val);
}

void getListUsers(listUser& l)
{
	fstream fin; 
	fin.open("DATA/users.csv", ios::in);
	l.head = l.tail = NULL;
	if (!fin.is_open())
	{
		cout << "Khong the mo file \n";
		return;
	}
	string s;
	getline(fin, s);
	while (!fin.eof())
	{
		addUser(l, input(fin));
	}
	fin.close();
}
void getListStudent(listStudent& l, string Path, int aca, string cla_name)
{
	fstream f; 
	// mở tập tin ở chế độ đọc
	f.open(Path, ios::in); 
	l.head = l.tail = nullptr;
	if (!f.is_open())
	{
		cout << "Khong the mo file \n";
		return;
	}
	string s = "";
	// Bỏ đi hàng đầu tiên chứa các thông tin 
	getline(f, s);
	while (!f.eof())
	{
		    // Lấy thông tin và thêm 
			addStudent(l, inputStudent(f,aca,cla_name));
	}
	f.close();

}

void getListClass(listClass& l, string PathSchoolyear) 
{
	fstream fin;
	fin.open(PathSchoolyear + "/INFOR.txt", ios::in);
	initList(l);
	if (!fin.is_open())
	{
		cout << "Khong the mo file \n";
		return;
	}
	while (!fin.eof())
		addClass(l, inputClass(fin));
	fin.close();
}

void getListStuCourse(listStuCourse& l, string Path)
{
	fstream fin;
	fin.open(Path, ios::in);
	initList(l);
	if (!fin.is_open()) return;
	string s = "";
	getline(fin, s);
	while (!fin.eof())
		addStuCourse(l, inputStuCourse(fin));
	fin.close();
}

void getListCourse(listCourse& l, string Path) {
	fstream fin;
	fin.open(Path + "\\Course.csv", ios::in);
	initList(l);
	if (!fin.is_open()) return;
	string s = "";
	getline(fin, s);
	while (!fin.eof())
		addCourse(l, inputCourse(fin, Path));
	fin.close();
}

void getListAllStudent(listStudent& l, listClass& lClass) {
	initList(l);
	nodeClass* tmp = lClass.head;
	while (tmp != NULL) 
	{
		MergeList(l, tmp->data.List_st);
		tmp = tmp->next;
	}
}

void AddListUsers(listUser& l_Us, listStudent l_St) {
	nodeStudent* t_st = l_St.head;
	while (t_st != NULL) {
		User t_us;
		t_us.id = t_st->data.id;
		t_us.pass = "123456";
		t_us.firstname = t_st->data.firstname;
		t_us.lastname = t_st->data.lastname;
		t_us.gender = t_st->data.gender;
		t_us.SocialID = t_st->data.SocialID;
		t_us.className = t_st->data.className;
		t_us.birthday = t_st->data.birthday;
		t_us.academic = t_st->data.academic;
		t_us.isStaff = false;
		addUser(l_Us, createNodeUser(t_us));
		t_st = t_st->next;
	}
}
void MergeList(listStudent& x, listStudent& y) 
{
	if (x.head == NULL) 
	{
		x = y;
		return;
	}
	if (y.head == NULL)
		return;
	x.tail->next = y.head;
	y.head->prev = x.tail;
	x.tail = y.tail;
}
