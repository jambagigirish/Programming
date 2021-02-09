/*Given an unsorted array and two numbers x and k, find k closest values to x.*/
#include "../stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm> 
#include <queue>
using namespace std;

vector<int> KClosestNumbers(vector<int>& nums, int x, int k){
	vector<int> res;
	int n = nums.size();
	priority_queue<pair<int,int>> pq;

	for (int i = 0; i < n; i++){
		pq.push(make_pair(abs(nums[i]-x),nums[i]));
		if (pq.size() > k){
			pq.pop();
		}
	}
	while (pq.size() > 0){
		res.push_back(pq.top().second);
		pq.pop();
	}
	return res;
}

int main()
{
	vector<int> myVector = { 10, 2, 14, 4, 7, 6 };
	cout << endl;
	vector<int> ret = KClosestNumbers(myVector, 5, 4);
	
	cout << "K closest numbers: ";
	for (int i = 0; i < ret.size(); i++){
		cout << ret[i] << endl;
	}

	int t;
	cin >> t;
	return 0;
}