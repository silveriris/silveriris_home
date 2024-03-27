#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
vector<vector<int>> result;
vector<int>path;
void backtrack(vector<int>& nums, vector<bool>& used)
{
	if (path.size() == nums.size())
	{
		result.push_back(path);
		return;
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > 0 && used[i - 1] == 0 && nums[i - 1] == nums[i])
		{
			continue;
		}
		if (used[i]==0)
		{
			path.push_back(nums[i]);
			used[i] = 1;
			backtrack(nums, used);
			used[i] = 0;
			path.pop_back();
		}
		
	}
}
vector<vector<int>> permute(vector<int>& nums) {
	vector<bool> used (nums.size(),0);
	sort(nums.begin(), nums.end());
	backtrack(nums,used);
	return result;
}
int main() {
	vector<int> nums = {1,1,2 };
	permute(nums);
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