// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>   
using namespace std;

int MaxAreaHistogram(vector<int>& nums){
	int maxArea;
	stack<pair<int, int>> st;
	int n = nums.size();

	for (int i = 0; i <n; i++){
		while (!st.empty() && st.top().first > nums[i]){
			int tempHeight = st.top().first;
			st.pop();
			if (!st.empty()){
				maxArea = max(maxArea, tempHeight *  (i - st.top().second - 1));
			}
			else { 
				maxArea = max(maxArea, tempHeight * (i));
			}
		}
		st.push(make_pair(nums[i], i));
	}
	while (!st.empty()){
		int tempHeight = st.top().first;
		st.pop();
		if (!st.empty()){
			maxArea = max(maxArea, tempHeight *  (n - st.top().second - 1));
		}
		else { 
			maxArea = max(maxArea, tempHeight * (n));
		}
	}

	return maxArea;
}

int main()
{
	vector<int> myVector = { 2, 1, 5, 6, 2, 3 };
	cout << endl;
	int retVal = MaxAreaHistogram(myVector);

	cout << "Max Area" << retVal<<endl;
	int t;
	cin >> t;
	return 0;
}
