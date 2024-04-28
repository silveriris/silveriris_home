#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> add(const vector<char>& str1, const vector<char>& str2)
{
	vector<int>res(max(str1.size() , str2.size()),0);
	
		int offset = str1.size() - str2.size();
		int i = str1.size()-1;
		for ( ; i >=offset ; i--)
		{
			res[i] += str1[i]-'0' + str2[i - offset]-'0';
			
			if (res[i]>=10)
			{
				res[i - 1] += 1;
				res[i] -= 10;
			}
			
		}
		while (i < offset && i >= 0)
		{
			res[i] += str1[i] - '0';
			i--;
		}
	
	return res;
}
int main() 
{
	vector<char> str1;
	vector<char> str2;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		str1.push_back(s[i]);
	}
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		str2.push_back(s[i]);
	}
	vector<int>res = str1.size() > str2.size() ? add(str1, str2) : add(str2, str1);
	for (int var : res)
		cout << var ;
	return 0;
}