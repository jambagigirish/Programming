#include "../stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm> 
#include <functional>
#include <queue>
#include <unordered_map>
using namespace std;

int ConnectRopesMinCost(vector<int>& nums){
	int res=0;
	int n = nums.size();
	priority_queue<int, vector<int>,greater<int>> pq;

	for (auto v : nums){
		pq.push(v);
	}
	int first = 0;
	int second = 0;
	while (pq.size() > 1){
		first = pq.top();
		pq.pop();

		second = pq.top();
		pq.pop();

		res = res + first + second;
		pq.push(first + second);

	}

	return res;
}

int main()
{
	vector<int> myVector = { 4,3,2,6};
	cout << endl;
	int ret = ConnectRopesMinCost(myVector);
	cout << "ret: " << ret<< endl;

	int t;
	cin >> t;
	return 0;
}