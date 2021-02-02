// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> NearestSmallerToRight(vector<int>& nums){
	vector<int> res;
	stack<int> st;
	int n = nums.size();

	for (int i = n - 1; i >= 0; i--){
		if (st.size() == 0){
			res.push_back(-1);
		}
		else if (st.size() > 0 && st.top() < nums[i]){
			res.push_back(st.top());
		}
		else if (st.size() > 0 && st.top() >= nums[i]){
			while (st.size() > 0 && st.top() >= nums[i]){
				st.pop();
			}
			if (st.size() == 0){
				res.push_back(-1);
			}
			else{
				res.push_back(st.top());
			}
		}
		st.push(nums[i]);
	}

	reverse(res.begin(), res.end());

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
	vector<int> myVector = { 11, 13, 21, 3 };
	cout << endl;
	vector<int> myConversionVector = NearestSmallerToRight(myVector);

	printVector(myConversionVector); //3 3 3 -1
	int t;
	cin >> t;
	return 0;

}

