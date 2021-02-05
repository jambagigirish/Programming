// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>   
using namespace std;

int MaxAreaHistogram(vector<int>& nums){
	int maxArea = INT_MIN;
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

int  MaxAreaRectangle(vector<vector<int>>& nums){
	int maxArea = INT_MIN;

	int r = nums.size();
	int c = nums[0].size();
	vector<int> temp(c,0);
	//fill in first row
	for (int j = 0; j < c; j++){
		temp[j] = nums[0][j];
		//cout << temp[j] << endl;
	}
	maxArea = MaxAreaHistogram(temp);
	//cout << " line 53 maxArea:" << maxArea << endl;
	int tempArea = 0;
	for (int i = 1; i < r; i++){
		for (int j = 0; j < c; j++){
			if (nums[i][j] == 1 && nums[i - 1][j] == nums[i][j]){
				temp[j] += nums[i][j];
			}
			else{
				temp[j] = nums[i][j];
			}
		}
		cout << endl;
		tempArea = MaxAreaHistogram(temp);
		maxArea = max(maxArea, tempArea);
		tempArea = 0;
	}

	return maxArea;
}


int main()
{
	vector<vector<int>> myVector = { { 0, 1, 1, 0 },
									 { 1, 1, 1, 1 },
									 { 1, 1, 1, 1 },
									 { 1, 1, 0, 0 } };
	cout << endl;
	int retVal = MaxAreaRectangle(myVector);

	cout << "Max Area " << retVal<<endl;
	int t;
	cin >> t;
	return 0;
}
