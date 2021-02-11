#include "../stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm> 
#include <functional>
#include <queue>
#include <unordered_map>
using namespace std;

int MaxSumSubArraySizeK(vector<int>& nums, int k){
	int res=INT_MIN;
	int n = nums.size();
	int start = 0;
	int end = 0;
	int sum = 0;
	while (end<n){
		sum = sum + nums[end];
		if (end - start + 1 < k){
			end++;
		}
		else if (end - start + 1 == k){
			res = max(res,sum);
			sum = sum - nums[start];
			start++;
			end++;	
		}	
	}
	return res;
}

int main()
{
	vector<int> myVector = { 100, 200, 300, 400 };
	cout << endl;
	int res = MaxSumSubArraySizeK(myVector, 2);

	cout << "MaxSumSubArraySizeK: " << res<< endl;

	int t;
	cin >> t;
	return 0;
}