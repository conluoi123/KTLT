#include "function.h"
void staffMenu()
{
	cout << "1. View profile info \n";
	cout << "2. Change the password \n";
	cout << "3. Create a school yead \n"; 
	cout << "4. Create a semester \n";
	cout << "5. Course \n";
	cout << "6. View \n";
	cout << "7.Log out \n";
	cout << "0. EXIT \n";

}
void LoadStaff()
{
	fstream fout; 
	// mở tập tin ở chế độ đọc 
	fout.open("DATA/INFOR.txt", ios::in);
	// Đọc năm bắt đầu và năm kết thúc 
	fout >> CurSchoolyear.Sta_year >> CurSchoolyear.End_year; 
	
	// Đặt tên file csv 
	PathSchoolyear = "DATA\\" + to_string(CurSchoolyear.Sta_year) + '-' + to_string(CurSchoolyear.End_year);
	fout.close();
	// vẫn là đang đọc folder 
	fout.open(PathSchoolyear, ios::in);
	if (!fout.is_open())
	{
		cout << "Khong the mo file \n";
	}
	else
	{
		// dô đây lấy thông tin folder kì học 
		string tmp;
		getline(fout, tmp, ',');
		CurSemester.InforSemester = stoi(tmp);
		getline(fout, tmp, ',');
		CurSemester.Star = SttoDate(tmp);
		getline(fout, tmp, ',');
		CurSemester.End = SttoDate(tmp);
		//  tới phần năm học đã được đọc ở trên rồi 
		CurSemester.Sch_year = CurSchoolyear;
		PathSemester = PathSchoolyear + "\\Semester" + to_string(CurSemester.InforSemester);
	}
	do
	{
		staffMenu();
		int lc; 
		cout << "Nhap lua chon: "; cin >> lc;
		switch (lc)
		{
		case 1: // Xem profile 
		{
			ProfileStaff();
			break;
		}
		case 2: // Đổi mật khẩu
		{
			ChangePassword();
			break;
		}
		case 3: // Tạo năm học 
		{
			CreateSchoolYear();
			break;
		}
		case 4: // tạo kì học
		{
			CreateSemester();
			break;
		}
		case 5: // Khóa học
		{
			LoadCourseMenu();
			break;
		}
		case 6: 
		{
			ViewMenu();
			break;
		}
		case 7: 
		{
			log();
			break;
		}
		case 0: // thoat ctrinh 
		{
			exit(0);
			break;
		}
		}

	} while (true);
}
void log()
{
	userLogin = NULL;
	solveLogin();
}
