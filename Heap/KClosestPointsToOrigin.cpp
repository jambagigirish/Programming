/*Given a list of points on the 2-D plane and an integer K. The task is to find K closest points to the origin and print them.*/
#include "../stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm> 
#include <functional>
#include <queue>
#include <unordered_map>
using namespace std;

vector<vector<int>> KClosestPoints(vector<vector<int>>& nums,int k){
	vector<vector<int>> res;
	int n = nums.size();

	priority_queue<pair<int, pair<int,int>>> pq;

	for (auto v : nums){
		int temp = v[0] * v[0] + v[1] * v[1];
		pq.push(make_pair(temp, make_pair(v[0],v[1])));

		if (pq.size() > k){
			pq.pop();
		}
	}
	vector<int> tv;
	while (pq.size() > 0){
		auto t = pq.top();
		tv.push_back(t.second.first);
		tv.push_back(t.second.second);
		res.push_back(tv);
		pq.pop();
	}
	return res;
}

//int main()
//{
//	vector<vector<int>> myVector = { { 3, 3 }, { 5, -1 }, { -2, 4 }};
//	cout << endl;
//	vector<vector<int>> ret = KClosestPoints(myVector,2);
//	cout << "ret.size()" << ret.size() << endl;
//	cout << "Closest points: ";
//	for (int i = 0; i < ret.size(); i++){
//		for (int j = 0; j < ret[i].size(); j++){
//			cout << ret[i][j] << " ";
//		}
//		cout << endl;
//	}
//
//	int t;
//	cin >> t;
//	return 0;
//}