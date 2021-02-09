/*Given an unsorted array and two numbers x and k, find k closest values to x.*/
#include "../stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm> 
#include <functional>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> TopKFrequentNumbers(vector<int>& nums, int k){
	vector<int> res;
	int n = nums.size();

	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++){
		mp[nums[i]]++;
	}
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	for (auto iter: mp){
		pq.push(make_pair(iter.second, iter.first));
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
	vector<int> myVector = { 10, 2, 14, 10, 2, 6,10,3 ,14,5,7,8};
	cout << endl;
	vector<int> ret = TopKFrequentNumbers(myVector, 3);

	cout << "Top K frequent numbers: ";
	for (int i = 0; i < ret.size(); i++){
		cout << ret[i] << endl;
	}

	int t;
	cin >> t;
	return 0;
}