/*Print the elements of an array in the increasing frequency if 2 numbers have same frequency then print the one which came first.*/
#include "../stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm> 
#include <functional>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> FrequentNumbers(vector<int>& nums){
	vector<int> res;
	int n = nums.size();

	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++){
		mp[nums[i]]++;
	}
	priority_queue<pair<int, int>> pq;

	for (auto iter : mp){
		pq.push(make_pair(iter.second, iter.first));
	}
	while (pq.size() > 0){
		res.push_back(pq.top().second);
		pq.pop();
	}
	return res;
}

int main()
{
	vector<int> myVector = { 2, 5, 2, 8, 5, 6, 8, 8 };
	cout << endl;
	vector<int> ret = FrequentNumbers(myVector);

	cout << "Frequent numbers: ";
	for (int i = 0; i < ret.size(); i++){
		cout << ret[i] << endl;
	}

	int t;
	cin >> t;
	return 0;
}