#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) 
{
	unordered_set<char> set;
	int res = 1;
	int r = -1;
	for ( int i = 0; i <= s.length(); i++)
	{
		if (i!=0)
		{
			set.erase(s[i - 1]);
		}
		while (r+1< s.length() &&!set.count(s[r+1]))
		{
			set.insert(s[r + 1]);
			r++;
		}
		res = max(res, r - i + 1);
	}
	return res;
}

int main()
{
	string s = "abcabcbb";
	auto res = lengthOfLongestSubstring(s);
	cout << res;
	return 0;
}


