#include "../stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm> 
#include <functional>
#include <queue>
#include <unordered_map>
#include<list>
using namespace std;

pair<int,int> LargestSubArrayOfSumK(vector<int>& nums, int k){
	pair<int, int> ret;
	int res = INT_MIN;
	int n = nums.size();
	int start = 0;
	int end = 0;
	int sum = 0;
	
	while (end<n){
		sum = sum + nums[end];
		//cout << "end: " << end <<" sum: " << sum << endl;
		if (sum < k){
			end++;
		}
		else if (sum == k){
			int len = end - start + 1;
			if (len > res){
				res = len;
				ret.first = start;
				ret.second = end;
			}
			sum = sum - nums[start];
			start++;
			end++;
		}
		else if (sum > k){
			while (sum > k){
				sum = sum - nums[start];
				start++;
			}
			end++;
		}
	}
	return ret;
}

int main()
{
	vector<int> myVector = { 4 ,1 ,1, 1, 2, 3, 5 };
	cout << endl;
	//int res = LargestSubArrayOfSumK(myVector, 3);
	pair<int,int> res = LargestSubArrayOfSumK(myVector, 5);
	cout << "LargestSubArray start pos: " << res.first<<" end pos: "<<res.second << endl;
	cout << "LargestSubArrayOfSumK: " << (res.second-res.first)+1 << endl;

	int t;
	cin >> t;
	return 0;
}