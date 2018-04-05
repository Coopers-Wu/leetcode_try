#include<iostream>
using namespace std;

void findnext(char* pattern, int* next)
{
	int  len = strlen(pattern);
	next[0] = 0;
	for (int i = 1; i < len; i++)
	{
		int j = next[i - 1];//i表示前后缀相同的个数。
		while (j > 0 && pattern[j] != pattern[i])j = next[j - 1];
		if (pattern[j] == pattern[i])next[i] = j + 1;
		else next[i] = 0;
	}
	cout << "match table: ";
	for (int i = 0; i < len; i++)cout << next[i] << " ";
	cout << endl;
}

int KMP(char* pattern,char* sourceString,int *next)
{
	int sourcelength = strlen(sourceString);
	int patternlength = strlen(pattern);
	int p = 0, s = 0;
	while (p < patternlength && s < sourcelength && patternlength <= sourcelength)
	{
		if (pattern[p] == sourceString[s])
		{
			s++;
			p++;
		}
		else
		{
			if (p == 0)s++;
			else p = next[p - 1];
		}

	}
	return p == patternlength ? s - patternlength : -1;
}


int main()
{
	int next[5] = { 0 };
	char pattern[] = "ababa";
	findnext(pattern, next);

	while (1);
	return 0;
}