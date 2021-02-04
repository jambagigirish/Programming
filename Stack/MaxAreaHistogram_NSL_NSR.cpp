// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>   
using namespace std;

vector<int> NearestSmallerToLeftIndex(vector<int>& nums){
	vector<int> res;
	stack<pair<int,int>> st;
	int n = nums.size();

	for (int i = 0; i < n; i++){
		if (st.size() == 0){
			res.push_back(-1);
		}
		else if (st.size() > 0 && st.top().first < nums[i]){
			res.push_back(st.top().second);
		}
		else if (st.size() > 0 && st.top().first >= nums[i]){
			while (st.size() > 0 && st.top().first >= nums[i]){
				st.pop();
			}
			if (st.size() == 0){
				res.push_back(-1);
			}
			else{
				res.push_back(st.top().second);
			}
		}
		st.push(make_pair(nums[i],i));
	}
	return res;
}

vector<int> NearestSmallerToRightIndex(vector<int>& nums){
	vector<int> res;
	stack<pair<int,int>> st;
	int n = nums.size();

	for (int i = n - 1; i >= 0; i--){
		if (st.size() == 0){
			res.push_back(n);
		}
		else if (st.size() > 0 && st.top().first < nums[i]){
			res.push_back(st.top().second);
		}
		else if (st.size() > 0 && st.top().first >= nums[i]){
			while (st.size() > 0 && st.top().first >= nums[i]){
				st.pop();
			}
			if (st.size() == 0){
				res.push_back(-1);
			}
			else{
				res.push_back(st.top().second);
			}
		}
		st.push(make_pair(nums[i],i));
	}

	reverse(res.begin(), res.end());

	return res;
}
int MaxAreaHistogramNSR_NSL(vector<int>& heights){
	int maxArea;
	vector<int> NSL;
	vector<int> NSR;
	vector<int> width(heights.size(),0);
	vector<int> area(heights.size(), 0);
	NSL = NearestSmallerToLeftIndex(heights);
	NSR = NearestSmallerToRightIndex(heights);

	for (int i = 0; i < heights.size(); i++){
		width[i]=(NSR[i] - NSL[i] - 1);
	}

	for (int i = 0; i < heights.size(); i++){
		int temp = heights[i] * width[i];
		area[i] = temp;
		maxArea = max(maxArea, temp);
	}
	return maxArea;
}

int main()
{
	vector<int> myVector = { 2, 1, 5, 6, 2, 3 };
	cout << endl;
	int retVal = MaxAreaHistogramNSR_NSL(myVector);

	cout << "Max Area: " << retVal<<endl;
	int t;
	cin >> t;
	return 0;
}
