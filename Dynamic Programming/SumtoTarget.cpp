#include "../stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm> 
#include <functional>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;

int SumToTarget(vector<int> arr, int k){
	int r = arr.size();
	int c = k;
	int res = 0;
	vector<vector<int>> dp(r+1,vector<int>(c+1,0));

	for (int i = 0; i < r+1; i++){
		dp[i][0] = 1;
	}

	for (int i = 1; i < r + 1; i++){
		for (int j = 1; j < c + 1; j++){
			if (arr[i-1] <= j){
				dp[i][j] = dp[i - 1][j] + dp[i-1][j - arr[i - 1]];
			}
			else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	res = dp[r][c];
	return res;
}

int main()
{
	/*string txt = "forxxorfxdofr";
	string pat = "for";*/
	vector<int> arr = { 1, 2, 3, 3 };
	int res = SumToTarget(arr, 6);

	cout << "Total numer of counts" << res <<endl;
	

	int t;
	cin >> t;
	return 0;
}