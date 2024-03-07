#include<iostream>
#include<vector>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
	int front = 0, tail = 0, sum = 0, len = nums.size()+1;
	for ( tail = 0; tail < nums.size(); tail++)
	{
		sum += nums[tail];
		while (sum >= target) 
		{
			if (len> tail - front)
			{
				len = tail - front;
			}
			sum -= nums[front++];
		}
	}
	if (len == nums.size() + 1)
	{
		return 0;
	}
	else
	{
		return len + 1;
	}
}
int main() {
	vector<int>nums = { 2,3,1,2,4,3};
	int target = 7;
	cout << minSubArrayLen(target, nums);
	return 0;
}