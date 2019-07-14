# 知识点：vector的基本操作

(1)头文件#include<vector>.
(2)创建vector对象，vector<int> vec;
(3)尾部插入数字：vec.push_back(a);
(4)使用下标访问元素，cout<<vec[0]<<endl;记住下标是从0开始的。
(5)使用迭代器访问元素.
vector<int>::iterator it;
for(it=vec.begin();it!=vec.end();it++)
   cout<<*it<<endl;  // 迭代器返回的东西有点像指针
(6)插入元素：    vec.insert(vec.begin()+i,a);在第i个元素后面插入a;
(7)删除元素：    vec.erase(vec.begin()+2);删除第3个元素
　　　　　　　 vec.erase(vec.begin()+i,vec.end()+j);删除区间[i,j-1];区间从0开始
(8)向量大小:vec.size(); 可以用于判断是否为空，或者用 v.empty();  返回空的vector可以用return NULL;但是不能vector==NULL?. 
(9)清空:vec.clear()　　　//清空之后，vec.size()为０

--------------------- 
作者：L未若 
来源：CSDN 
原文：https://blog.csdn.net/msdnwolaile/article/details/52708144 
版权声明：本文为博主原创文章，转载请附上博文链接！

# 知识点，迭代器
begin和end操作产生指向容器内第一个元素和最后一个元素的下一个位置的迭代器。这两个迭代器通常用于标记包含容器中所有元素的迭代范围。
c.begin() 返回一个迭代器，它指向容器c的第一个元素
c.end() 返回一个迭代器，它指向容器c的最后一个元素的下一个位置
c.rbegin() 返回一个逆序迭代器，它指向容器c的最后一个元素
c.rend() 返回一个逆序迭代器，它指向容器c的第一个元素前面的位置
        上述每个操作都有两个不同的版本：一个是const成员，另一个是非const成员。这些操作返回什么类型取决于容器是否为const。如果容器不是const，则这些操作返回iterator或reverse_iterator类型。如果容器是const，则其返回类型要加上const_前缀，也就是const_iterator和const_reverse_iterator类型。

![begin end iterator](http://hi.csdn.net/attachment/201111/4/0_1320396914KpO5.gif)
--------------------- 
作者：小白的进阶 
来源：CSDN 
原文：https://blog.csdn.net/laobai1015/article/details/51567564 
版权声明：本文为博主原创文章，转载请附上博文链接！

## const_iterator, iterator
1.iterator,const_iterator作用：遍历容器内的元素，并访问这些元素的值。iterator可以改元素值,但const_iterator不可改。跟C的指针有点像
(容器均可以++iter,而vector还可以iter-n, iter+n,n为一整型,iter1-iter2:结果是difference_type类型，表两元素的距离.)

2.const_iterator 对象可以用于const vector 或非 const vector,它自身的值可以改(可以指向其他元素),但不能改写其指向的元素值.

3.const iterator与const_iterator是不一样的：声明一个 const iterator时，必须初始化它。一旦被初始化后，就不能改变它的值,它一旦被初始化后,只能用它来

改它指的元素,不能使它指向其他元素。(因此const iterator几乎没什么用途)

```cpp
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
 
	//第二种遍历方式，迭代器 vector<Point>::iterator, 不要在循环中判断不等于end()
	// 迭代器的算术操作仅有将两个迭代器相减,算出两个迭代器之间的距离;迭代器没有相加运算
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
```
// --------------------- 
// 作者：HW140701 
// 来源：CSDN 
// 原文：https://blog.csdn.net/HW140701/article/details/78833486 
// 版权声明：本文为博主原创文章，转载请附上博文链接！