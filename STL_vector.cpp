// 知识点：vector的基本操作

// (1)头文件#include<vector>.
// (2)创建vector对象，vector<int> vec;
// (3)尾部插入数字：vec.push_back(a);
// (4)使用下标访问元素，cout<<vec[0]<<endl;记住下标是从0开始的。
// (5)使用迭代器访问元素.
// vector<int>::iterator it;
// for(it=vec.begin();it!=vec.end();it++)
//    cout<<*it<<endl;  // 迭代器返回的东西有点像指针
// (6)插入元素：    vec.insert(vec.begin()+i,a);在第i个元素后面插入a;
// (7)删除元素：    vec.erase(vec.begin()+2);删除第3个元素
// 　　　　　　　 vec.erase(vec.begin()+i,vec.end()+j);删除区间[i,j-1];区间从0开始
// (8)向量大小:vec.size(); 可以用于判断是否为空，或者用 v.empty();  返回空的vector可以用return NULL;但是不能vector==NULL?. 
// (9)清空:vec.clear()　　　//清空之后，vec.size()为０
//
// --------------------- 
// 作者：L未若 
// 来源：CSDN 
// 原文：https://blog.csdn.net/msdnwolaile/article/details/52708144 
// 版权声明：本文为博主原创文章，转载请附上博文链接！


#include <vector>
#include <iostream>
 
using namespace std;
 
struct Point
{
	double x;
	double y;
	Point()
	{
		x = 0;
		y = 0;
	}
};
 
 
int main()
{
	vector<Point> m_testPoint;
	m_testPoint.clear();
	m_testPoint.shrink_to_fit();
 
	for (int i = 0; i<10; ++i)
	{
		Point temp;
		temp.x = i*i;
		temp.y = i*i;
		m_testPoint.push_back(temp);
	}
 
	//第一种遍历方式，下标
	cout << "第一种遍历方式，下标访问" << endl;
	for (int i = 0; i<m_testPoint.size(); ++i)
	{
 
		cout << m_testPoint[i].x << "	" << m_testPoint[i].y << endl;
	}
 
	//第二种遍历方式，迭代器 vector<Point>::iterator
	cout << "第二种遍历方式，迭代器访问" << endl;
	for (vector<Point>::iterator iter = m_testPoint.begin(); iter != m_testPoint.end(); iter++)
	{
		cout << (*iter).x << "	" << (*iter).y << endl;
	}
 
	//第三种遍历方式，auto关键字
	cout << "C++11,第三种遍历方式，auto关键字" << endl;
	for (auto iter = m_testPoint.begin(); iter != m_testPoint.end(); iter++)
	{
		cout << (*iter).x << "	" << (*iter).y << endl;
	}
 
	//第四种遍历方式，auto关键字的另一种方式
	cout << "C++11,第四种遍历方式，auto关键字" << endl;
	for (auto i : m_testPoint)
	{
		cout << i.x << "	" << i.y << endl;
	}
 
	return 0;
}
// --------------------- 
// 作者：HW140701 
// 来源：CSDN 
// 原文：https://blog.csdn.net/HW140701/article/details/78833486 
// 版权声明：本文为博主原创文章，转载请附上博文链接！