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

vector<int> MaxElementSubArraySizeK(vector<int>& nums, int k){
	vector<int> res;
	list<int> lst;
	int n = nums.size();
	int start = 0;
	int end = 0;
	while (end<n){
		while (lst.size()>0 && nums[end] >=lst.back()){
			lst.pop_back();
		}
		lst.push_back(nums[end]);

		if (end - start + 1 < k){
			end++;
		}
		else if (end - start + 1 == k){
			if (lst.size() > 0){
				int temp = lst.front();
				res.push_back(temp);
				if (temp == nums[start]){
					lst.pop_front();
				}
			}
			start++;
			end++;
		}
	}
	return res;
}

int main()
{
	//vector<int> myVector = { 12, -1, -7, 8, -15, 30, 16, 28 };
	//vector<int> myVector = { -8, 2, 3, -6, 10 };
	vector<int> myVector = { 1, 3, -1, -3, 5, 3, 6, 7 };
	cout << endl;
	vector<int> res = MaxElementSubArraySizeK(myVector, 3);

	cout << "MaxElementSubArraySizeK: "<<endl;

	for (int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}

	int t;
	cin >> t;
	return 0;
}