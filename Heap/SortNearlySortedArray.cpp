#include "../stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm> 
#include <queue>
#include <functional>   // std::greater
using namespace std;

vector<int> KSortedArray(vector<int>& nums, int k){
	vector<int> res;
	int n = nums.size();
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < n; i++){
		pq.push(nums[i]);
		if (pq.size() > k){
			res.push_back(pq.top());
			pq.pop();
		}
	}
	while (pq.size() > 0){
		res.push_back(pq.top());
		pq.pop();
	}

	return res;
}

int main()
{
	vector<int> myVector = { 6, 5, 3, 2, 8, 10, 9 };
	cout << endl;
	vector<int> ret = KSortedArray(myVector, 3);

	cout << "sorted array: ";
	for (int i = 0; i < ret.size(); i++){
		cout << ret[i] << endl;
	}

	int t;
	cin >> t;
	return 0;
}