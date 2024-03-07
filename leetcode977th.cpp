#include<iostream>
#include<vector>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) 
{
	vector<int> result(nums.size(),0);
	int left = 0, right = nums.size() - 1;
	int k=right;
	while (left<=right)
	{
		if (pow(nums[left],2)> pow(nums[right], 2))
		{
			result[k--] = pow(nums[left], 2);
			left++;
		}
		else
		{
			result[k--] = pow(nums[right], 2);
			right--;
		}
	}
	return result;

}
int main() {
	vector<int> nums = { -4,-1,0,3,10 };
	for (int i = 0; i < nums.size(); i++)
	{
		cout << sortedSquares(nums)[i]<<endl;
	}return 0;
}