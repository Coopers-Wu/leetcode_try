#include<iostream>
//有些地方不是题目的要求
using namespace std;

int main()
{
	string ss="abcd";
	cout << ss.length() << endl;
	ss.append("e");
	cout << ss[4] << endl;
	string news;
	for (int i = ss.length() - 1; i >= 0; i--)
	{
		news.append(ss,i,1);
		//news += ss[i];
	}
	for (int i = 0; i < news.length(); i++)
	{
		cout << news[i];
	}

	while (true);
	return 0;
}
