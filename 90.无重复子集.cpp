#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<vector<int>> result;
vector<int>path;
void backtrack(vector<int> &nums,vector<bool> &used,int startindex)
{
	result.push_back(path);
	if (startindex==nums.size())
	{
		return;
	}
	for (int i = startindex; i < nums.size(); i++)
	{
		if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == 0)
		{
			continue;
		}
		path.push_back(nums[i]);
		used[i] = 1;
		backtrack(nums, used,i + 1);
		used[i] = 0;
		path.pop_back();
	}
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	sort(nums.begin(),nums.end());
	vector<bool>used(nums.size(),0);
	backtrack(nums,used, 0);
	return result;
}
int main() {
	vector<int> nums = { 1,2,3,3,2 };
	subsetsWithDup(nums);
	for (vector<int> var : result)
	{
		cout << '{';
		for (int x : var)
		{
			cout << x << ',';
		}
		cout << '}';
	}
    return 0;
}