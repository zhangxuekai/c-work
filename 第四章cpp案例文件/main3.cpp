/*************************************************
** 功能 : 常数据成员  
** 作者 : 201711010503@stu.sdnu.edu.cn
** 版本 : 2018-11-25 / 17:14
** 版权 : GNU General Public License(GNU GPL)
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>



using namespace std;

/*----------------------------------*
         Class Defination
*-----------------------------------*/

class circle
{
	//成员变量
private:
	double radius;
	const double PI;

	//成员函数
public:

	circle(double r = 0) :PI(3.1415926)
	{
		radius = r;
	}
	double area();
	double circumference();

};
double circle::area()
{
	return PI * radius*radius;

}
double circle::circumference()
{
	return 2 * PI*radius;
}
	


/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	circle c1(3.5), c2;
	cout << "area of c1=" << c1.area() << ",circumference of c1=" << c1.circumference() << endl;
	cout << "area of c2=" << c2.area() << ",circumference of c2=" << c2.circumference() << endl;


	system("pause");
	
	return 0;
}