// example3_26_student.h:学生类的定义

#define _CRT_SECURE_NO_WARNINGS


#ifndef _STUDENT                //条件编译
#define _STUDENT
#include<iostream>
#include<string>
using namespace std;
#define SIZE 80
class Student
{
	char *name;                     //姓名
	char ID[19];                     //身份证
	char number[10];                 //学号
	char speciality[20];                //专业
	int age;                         //年龄
public:
	Student();                         //无参构造函数
	Student(char *na, char *id, char *num, char * spec, int ag);  //带参构造函数
	Student(const Student &per);          //拷贝构造函数
	~Student();                        //析构函数
	char* GetName();                   //提取姓名
	char* GetID();                      //提取身份证
	char* GetNumber();                 //提取学号
	char* GetSpec();                    //提取专业
	int GetAge();                       //提取年龄
	void Display();                      //显示学生信息
	void Input();                        //输入学生信息

};
#endif


//example3_26_student.cpp：学生类的实现
Student::Student()
{
	name = NULL;
	age = 0;
}
//构造函数
Student::Student(char *na, char *id, char *num, char * spec, int ag)
{
	if (na)
	{
		name = new char[strlen(na) + 1];       //避免浅拷贝
		strcpy(name, na);
	}
	strcpy(ID, id);
	strcpy(number, num);
	strcpy(speciality, spec);
	age = ag;
}

Student::Student(const Student &per)           //拷贝构造函数，在此例中暂时没有用到
{
	if (per.name)
	{
		name = new char[strlen(per.name) + 1];
		strcpy(name, per.name);
	}
	strcpy(ID, per.ID);
	strcpy(number, per.number);
	strcpy(speciality, per.speciality);
	age = per.age;
}

Student::~Student()                         //析构函数
{
	if (name)
		delete[]name;
}

char* Student::GetName()                   //提取姓名
{
	return name;
}
char* Student::GetID()                      //提取身份证
{
	return ID;
}
int Student::GetAge()                       //提取年龄
{
	return age;
}
char* Student::GetSpec()                    //提取专业
{
	return speciality;
}
char* Student::GetNumber()                 //提取学号
{
	return number;
}
void Student::Display()                    //输出数据信息
{
	cout << "姓  名：" << name << endl;
	cout << "身份证：" << ID << endl;
	cout << "学  号：" << number << endl;
	cout << "专  业：" << speciality << endl;
	cout << "年  龄：" << age << endl << endl;
}
void Student::Input()                      //输入数据
{
	char na[10];
	cout << "输入姓  名：";
	cin >> na;
	if (name)
		delete[]name;
	name = new char[strlen(na) + 1];
	strcpy(name, na);
	cout << "输入身份证：";
	cin >> ID;
	cout << "输入年  龄：";
	cin >> age;
	cout << "输入专  业：";
	cin >> speciality;
	cout << "输入学  号：";
	cin >> number;
}





//example3_26.cpp文件：包含主函数及其他一些普通函数

const int N = 10;


int shuliang = 0;

void menu()
{
	cout << "**********1.录入信息**********" << endl;
	cout << "**********2.查询信息**********" << endl;
	cout << "**********3.浏览信息**********" << endl;
	cout << "**********0.退    出**********" << endl;
}

void OutputStu(Student *array)               //输出对象数组元素
{
	cout << "学生总人数=" << shuliang << endl;
	for (int i = 0; i < shuliang; i++)
		array[i].Display();
}

int SearchStu(Student *array, char *na)         //按姓名查询
{
	int i, j = N;
	for (i = 0; i < shuliang; i++)
		if (strcmp(array[i].GetName(), na) == 0)
			j = i;
	return j;
}

void InputStu(Student *array)                //输入对象数组元素
{
	char ch;
	do
	{
		array[shuliang].Input();
		shuliang++;
		cout << "继续输入吗？(Y or N )" << endl;
		cin >> ch;
	} while (ch == 'Y');
}


int main()
{
	Student array[N];
	int choice;

	do
	{
		menu();
		cout << "Please input your choice:";
		cin >> choice;
		if (choice >= 0 && choice <= 3)
			switch (choice)
			{
			case 1:InputStu(array); break;
			case 2:cout << "Input the name searched" << endl;
				char na[20];
				cin >> na;
				int i;
				i = SearchStu(array, na);
				if (i == N)
					cout << "查无此人！\n";
				else
					array[i].Display();
				break;
			case 3:OutputStu(array); break;
			default:break;
			}
	} while (choice);
	return 0;
}
