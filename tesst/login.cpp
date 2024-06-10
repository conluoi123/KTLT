#include "function.h"
nodeUser *userLogin = NULL;
listUser l_User; 
// hàm tìm list tài khoản 
nodeUser* find(string id, string pass)
{
	nodeUser* p = l_User.head;
	while (p != NULL)
	{
		if (id == p->data.id)
		{
			if (pass == p->data.pass)
			{
				return p;
			}
	
		}
		p = p->next;
	}
	return nullptr;
}


// hamf xử lí đăng nhập 
void solveLogin()
{
	// Xóa sạch màn hình 
	system("cls");
	getListUsers(l_User);
	while (true)
	{
		string tmp1, tmp2;
		userLogin = find(tmp1, tmp2);
		if (userLogin == nullptr)
		{
			cout << "Loi khong dang nhap duoc \n";
		}
		else
		{
			cout << "Dang nhap thanh cong \n"; 
			break;
		}
	}
	cout << userLogin->data.isStaff;
	if (userLogin->data.isStaff)
	{
		//Staff 
		LoadStaffMenu();
	}
	else 
	{
		//Student
		LoadStudentMenu();
	}
	system("cls");
}