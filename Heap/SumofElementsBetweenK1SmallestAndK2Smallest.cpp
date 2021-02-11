#include "../stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm> 
#include <functional>
#include <queue>
#include <unordered_map>
using namespace std;

int KthSmallest(vector<int>& nums, int k){
	int res;
	int n = nums.size();
	priority_queue<int> pq;

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
	//vector<int> myVector = { 2, 1, 5, 6, 4, 3 };
	vector<int> myVector = { 20, 8, 22, 4, 12, 10, 14 };
	cout << endl;
	int k1 = KthSmallest(myVector,3);
	int k2 = KthSmallest(myVector,6);
	int res = 0;
	for (int i = 0; i < myVector.size(); i++){
		if (k2<k1 && myVector[i]>k2 && myVector[i] < k1)
		{
			res += myVector[i];
		}
		else if (k1<k2 && myVector[i]>k1 && myVector[i] < k2)
		{
			res += myVector[i];
		}
	}

	cout << "Sum between K1th smallest Element and k2th smallest element " << res<< endl;

	int t;
	cin >> t;
	return 0;
}