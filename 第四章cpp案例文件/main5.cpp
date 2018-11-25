/*************************************************
** 功能 : 常对象  
** 作者 : 201711010503@stu.sdnu.edu.cn
** 版本 : 2018-11-25 / 17:55
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
class person 
{
//成员变量
private:
	int age;
	char *name;

//成员函数
public:
	
	person(int n = 1,char *na="zhuli");
	~person ();
	void print();
	void print() const;
	void modifyage();
};

person::person(int n, char *na)
{
	age = n;
	name = new char[strlen(na) + 1];
	strcpy(name,na);
}

person::~person()
{
	delete[]name;
}

void person::print()
{
	cout << "age:" << age << " name :" << name << < endl;
	cout << "this is general print()." << endl;
}

void person::print() const 
{
	cout << "age:" << age << " name :" << name << < endl;
	cout << "this is const print()." << endl;
}


void person::modifyage()
{
	age++;
}

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	const person p1(17, "wu");
	cout << "output const object p1" << endl;
	p1.print();

	person p2(18, "zahng");
	cout << "output general object p2" << endl;
	p2.modifyage;
	p2.print();
	
	system("pause");
	
	return 0;
}