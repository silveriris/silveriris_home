#include<iostream>
#include<vector>
using namespace std;
/*
vector<int> numsLeft(nums.begin(), nums.begin() + ((nums.size() - 1) / 2 - 1));
	for (int i = 0; i < numsLeft.size(); i++)
	{
		cout << *(numsLeft.begin() + i);
	}
*/
int searchInsert(vector<int>& nums, int target) {
	if (nums.size()==1)
	{
		return -9999999;
	}
	if (nums[(nums.size() - 1) / 2] > target)
	{
		vector<int> numsLeft(nums.begin(), nums.begin() + ((nums.size() - 1) / 2 - 1));
		return searchInsert(numsLeft, target);
	}
	if (nums[(nums.size() - 1) / 2] == target)
	{
		return ((nums.size() - 1) / 2);
	}
	if (nums[(nums.size() - 1) / 2] < target)
	{
		vector<int> numsRight(nums.begin() + (nums.size() - 1) / 2 + 1, nums.end());
		return searchInsert(numsRight, target);
	}
}
int main()
{
	vector<int>nums = { 1,3,5,6 };
	int target=5;
	cout << searchInsert(nums,target);
	return 0;
}