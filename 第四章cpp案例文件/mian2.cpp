/*************************************************
** 功能 : 静态数据函数
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
	
	student() { total++; }
	~student() { total--; }
	student(int n, char *p = "wang");
	void getname();
	int getnum();
	static void print();

private:
    static int total;
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

void student::print()
{
	cout << "the number of all students:" << total << endl;
}


/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{
	student::print();
    student *p = new student(13);
	student::print();
	p->print();
	delete p;
	student::print();

	student s[2];

	s[0].print();
	s[1].print();

	   	  
	system("pause");

	return 0;
}