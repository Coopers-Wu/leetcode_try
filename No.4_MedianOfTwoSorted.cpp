#include<iostream>
#include<vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main()
{
	//vector<int> a = { 1,2 };
	vector<int> a;
	vector<int> b = { 1 };
	double result = findMedianSortedArrays(a, b);
	std::cout << result << endl;
	while (1);
	return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
	int sum = nums1.size() + nums2.size();
	vector<int>::iterator i1 = nums1.begin();
	vector<int>::iterator i2 = nums2.begin();
	int find = 0;

	if (sum % 2)
	{
		int des = (sum / 2) + 1;
		int src = 0;
		while (i1 != nums1.end() && i2 != nums2.end())
		{
			if (*i1<*i2)
			{
				src = *i1;
				i1++;
			}
			else
			{
				src = *i2;
				i2++;
			}
			find++;
			if (find == des)
			{
				return src;
			}
		}
		while (i1 != nums1.end())
		{
			src = *i1;
			i1++;
			find++;
			if (find == des)
			{
				return src;
			}

		}
		while (i2 != nums2.end())
		{
			src = *i2;
			i2++;
			find++;
			if (find == des)
			{
				return src;
			}
		}
	}
	else
	{
		int src;
		double max[2] = { 0,0 };
		int a = (sum / 2);
		int b = (sum / 2) + 1;
		while (i1 != nums1.end() && i2 != nums2.end())
		{
			if (*i1<*i2)
			{
				src = *i1;
				i1++;
			}
			else
			{
				src = *i2;
				i2++;
			}
			find++;
			if (find == a)
			{
				max[0] = src;
			}
			if (find == b)
			{
				max[1] = src;
				break;
			}
		}
		while (i1 != nums1.end() && max[1] == 0)
		{
			src = *i1;
			find++;
			i1++;
			if (find == a)
			{
				max[0] = src;
			}
			if (find == b)
			{
				max[1] = src;
				break;
			}
		}
		while (i2 != nums2.end() && max[1] == 0)
		{
			src = *i2;
			find++;
			i2++;
			if (find == a)
			{
				max[0] = src;
			}
			if (find == b)
			{
				max[1] = src;
				break;
			}
		}
		return (max[0] + max[1]) / 2;
	}
}
