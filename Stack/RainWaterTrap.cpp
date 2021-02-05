#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>   
using namespace std;

int trap(vector<int>& height) {

	int n = height.size();

	if (n == 0){
		return 0;
	}
	vector<int> leftMx(n, 0);
	vector<int> rightMx(n, 0);
	leftMx[0] = height[0];

	for (int i = 1; i<n; i++){
		leftMx[i] = max(height[i], leftMx[i - 1]);
	}

	rightMx[n - 1] = height[n - 1];

	for (int i = n - 2; i >= 0; i--){
		rightMx[i] = max(height[i], rightMx[i + 1]);
	}

	int res = 0;

	for (int i = 0; i<n; i++){
		int temp = min(leftMx[i], rightMx[i]) - height[i];
		res += temp;
	}

	return res;
}

int main()
{
	vector<int> myVector = { 3, 0, 0, 2, 0, 4 };
	cout << endl;
	int retVal = trap(myVector);

	cout << "Max water " << retVal<<endl;
	int t;
	cin >> t;
	return 0;
}