#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<vector<int>> result;
vector<int>path;
void backtrack(vector<int> &nums,int startindex)
{
	if (path.size()>1)
	{
		result.push_back(path);
	}
	int used[201] = { 0 };
	for (int i = startindex; i < nums.size(); i++)
	{
		if ((!path.empty()&&nums[i]<path.back())||used[nums[i] + 100]==1)
		{
			continue;
		}
		path.push_back(nums[i]);
		used[nums[i]+100] = 1;
		backtrack(nums, i + 1);
		path.pop_back();
	}
}
vector<vector<int>> findSubsequences(vector<int>& nums) {
	backtrack(nums, 0);
	return result;
}
int main() {
	vector<int> nums = { 4,4,3,2,1 };
	findSubsequences(nums);
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