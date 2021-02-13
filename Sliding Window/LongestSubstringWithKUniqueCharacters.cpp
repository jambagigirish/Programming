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

pair<int, int> LongestSubstring(string str, int k){
	pair<int, int> ret;
	int res = INT_MIN;
	int n = str.size();
	int start = 0;
	int end = 0;
	unordered_map<char, int> mp;

	while (end<n){
		mp[str[end]]++;
		if (mp.size() < k){
			end++;
		}
		else if (mp.size() == k){
			int len = end - start + 1;
			if (len > res){
				res = len;
				ret.first = start;
				ret.second = end;
			}
			end++;
		}
		else if (mp.size() > k){
			while (mp.size() > k){
				mp[str[start]] -= 1;
				if (mp[str[start]] == 0){
					mp.erase(str[start]);
				}
				start++;
			}
			end++;
		}
	}
	return ret;
}

int main()
{
	string mystring = "aabacbebebe";
	//string mystring = "aaaa";
	cout << endl;
	pair<int, int> res = LongestSubstring(mystring, 3);
	cout << "LargestSubArray start pos: " << res.first << " end pos: " << res.second << endl;
	cout << "LargestSubArrayOfSumK: " << (res.second - res.first) + 1 << endl;

	int t;
	cin >> t;
	return 0;
}