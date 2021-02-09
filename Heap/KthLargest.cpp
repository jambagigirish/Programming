#include "../stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm> 
#include <queue>
#include <functional>   // std::greater
using namespace std;

int KthLargestElement(vector<int>& nums, int k){
	int res;
	int n = nums.size();
	priority_queue<int,vector<int>,greater<int>> pq;

	for (int i = 0; i < n; i++){
		pq.push(nums[i]);
		if (pq.size() > k){
			pq.pop();
		}
	}

	res = pq.top();

	return res;
}

int main()
{
	vector<int> myVector = { 2, 1, 5, 6, 4, 3 };
	cout << endl;
	int ret = KthLargestElement(myVector, 2);

	cout << "Kth Largest Element: " << ret << endl;

	int t;
	cin >> t;
	return 0;
}