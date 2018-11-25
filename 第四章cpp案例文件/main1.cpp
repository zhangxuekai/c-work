/*************************************************
** 功能 : 静态数据成员  
** 作者 : 201711010503@stu.sdnu.edu.cn
** 版本 : 2018-11-25 / 16:22
** 版权 : GNU General Public License(GNU GPL)
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

/*----------------------------------*
         Class Defination
*-----------------------------------*/
	class student
	{
	public:
		static int total;
		student() { total++; }
		~student() { total--; }
		student(int n, char *p = "wang");
		void getname();
		int getnum();
	
	private:
		int num;
		char name[20];
	};

	int student::total = 0;
	student::student(int n, char *p)
	{
		num = n;
		strcpy(name, p);
		total++;
	}

	void student::getname()
	{
		cout << name << endl;
	}
	int student::getnum()
	{
		return num;
	}



/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	cout << "the number of all students:" << student::total << endl;

	student *p = new student(13);
	delete p;
	cout << "the number of all students:" << student::total << endl;
	cout << "the number of all students:" << p->total << endl;

	cout << "the number of all students:" << student::total << endl;

	student s[2];
	cout << "the number of all students:" << s[0].total << endl;
	cout << "the number of all students:" << s[1].total << endl;




	system("pause");
	
	return 0;
}