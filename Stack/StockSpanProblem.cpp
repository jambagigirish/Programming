// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> StackSpanProblem(vector<int>& nums){
	vector<int> res;
	stack<pair<int,int>> st;
	int n = nums.size();

	for (int i = 0; i <n; i++){
		if (st.size() == 0){
			res.push_back(-1);
		}
		else if (st.size() > 0 && st.top().first > nums[i]){
			res.push_back(st.top().second);
		}
		else if (st.size() > 0 && st.top().first <= nums[i]){
			while (st.size() > 0 && st.top().first <= nums[i]){
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
	for (int i = 0; i < res.size(); i++){
		res[i] = i - res[i];
	}

	return res;
}

void printVector(vector<int>& nums){
	for (int i = 0; i < nums.size(); i++){
		cout << nums[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> myVector = { 10, 4, 5, 90, 120, 80 }; 
	cout << endl;
	vector<int> myConversionVector = StackSpanProblem(myVector);

	printVector(myConversionVector); // 
	int t;
	cin >> t;
	return 0;
}
