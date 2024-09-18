#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) 
{
	int n = height.size();
	int res = 0;
	int left = 0, leftmax = 0;
	int right = n-1, rightmax = 0;
	while (left<right)
	{
		leftmax = max(height[left], leftmax);
		rightmax = max(height[right], rightmax);
		if (leftmax<rightmax)
		{
			res += leftmax - height[left];
			left++;
		}
		else
		{
			res += rightmax - height[right];
			right--;
		}
	}
	return res;
}
int main()
{
	vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	auto res = trap(height);
	cout << res;
	return 0;
}


