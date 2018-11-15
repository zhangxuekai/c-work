// example3_26_student.h:ѧ����Ķ���

#define _CRT_SECURE_NO_WARNINGS


#ifndef _STUDENT                //��������
#define _STUDENT
#include<iostream>
#include<string>
using namespace std;
#define SIZE 80
class Student
{
	char *name;                     //����
	char ID[19];                     //���֤
	char number[10];                 //ѧ��
	char speciality[20];                //רҵ
	int age;                         //����
public:
	Student();                         //�޲ι��캯��
	Student(char *na, char *id, char *num, char * spec, int ag);  //���ι��캯��
	Student(const Student &per);          //�������캯��
	~Student();                        //��������
	char* GetName();                   //��ȡ����
	char* GetID();                      //��ȡ���֤
	char* GetNumber();                 //��ȡѧ��
	char* GetSpec();                    //��ȡרҵ
	int GetAge();                       //��ȡ����
	void Display();                      //��ʾѧ����Ϣ
	void Input();                        //����ѧ����Ϣ

};
#endif


//example3_26_student.cpp��ѧ�����ʵ��
Student::Student()
{
	name = NULL;
	age = 0;
}
//���캯��
Student::Student(char *na, char *id, char *num, char * spec, int ag)
{
	if (na)
	{
		name = new char[strlen(na) + 1];       //����ǳ����
		strcpy(name, na);
	}
	strcpy(ID, id);
	strcpy(number, num);
	strcpy(speciality, spec);
	age = ag;
}

Student::Student(const Student &per)           //�������캯�����ڴ�������ʱû���õ�
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

Student::~Student()                         //��������
{
	if (name)
		delete[]name;
}

char* Student::GetName()                   //��ȡ����
{
	return name;
}
char* Student::GetID()                      //��ȡ���֤
{
	return ID;
}
int Student::GetAge()                       //��ȡ����
{
	return age;
}
char* Student::GetSpec()                    //��ȡרҵ
{
	return speciality;
}
char* Student::GetNumber()                 //��ȡѧ��
{
	return number;
}
void Student::Display()                    //���������Ϣ
{
	cout << "��  ����" << name << endl;
	cout << "���֤��" << ID << endl;
	cout << "ѧ  �ţ�" << number << endl;
	cout << "ר  ҵ��" << speciality << endl;
	cout << "��  �䣺" << age << endl << endl;
}
void Student::Input()                      //��������
{
	char na[10];
	cout << "������  ����";
	cin >> na;
	if (name)
		delete[]name;
	name = new char[strlen(na) + 1];
	strcpy(name, na);
	cout << "�������֤��";
	cin >> ID;
	cout << "������  �䣺";
	cin >> age;
	cout << "����ר  ҵ��";
	cin >> speciality;
	cout << "����ѧ  �ţ�";
	cin >> number;
}





//example3_26.cpp�ļ�������������������һЩ��ͨ����

const int N = 10;


int shuliang = 0;

void menu()
{
	cout << "**********1.¼����Ϣ**********" << endl;
	cout << "**********2.��ѯ��Ϣ**********" << endl;
	cout << "**********3.�����Ϣ**********" << endl;
	cout << "**********0.��    ��**********" << endl;
}

void OutputStu(Student *array)               //�����������Ԫ��
{
	cout << "ѧ��������=" << shuliang << endl;
	for (int i = 0; i < shuliang; i++)
		array[i].Display();
}

int SearchStu(Student *array, char *na)         //��������ѯ
{
	int i, j = N;
	for (i = 0; i < shuliang; i++)
		if (strcmp(array[i].GetName(), na) == 0)
			j = i;
	return j;
}

void InputStu(Student *array)                //�����������Ԫ��
{
	char ch;
	do
	{
		array[shuliang].Input();
		shuliang++;
		cout << "����������(Y or N )" << endl;
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
					cout << "���޴��ˣ�\n";
				else
					array[i].Display();
				break;
			case 3:OutputStu(array); break;
			default:break;
			}
	} while (choice);
	return 0;
}
