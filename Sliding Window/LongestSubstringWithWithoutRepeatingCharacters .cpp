#include "../stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm> 
#include <functional>
#include <queue>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;

pair<int, int> LongestSubstringWithoutDuplicateChars(string str){
	pair<int, int> ret;
	int res = INT_MIN;
	int n = str.size();
	int start = 0;
	int end = 0;
	unordered_map<char, int> mp;
	int count = 0;
	while (end<n){
		mp[str[end]]+=1;

		if (mp[str[end]] == 1){
			count += 1;
		}

		if (end - start + 1 == count){
			int len = end - start + 1;
			if (len > res){
				res = len;
				ret.first = start;
				ret.second = end;
			}
			end++;
		}
		else if (end - start + 1 > count){
			while (end - start + 1 > count){
				mp[str[start]] -= 1;
				if (mp[str[start]] == 0){
					mp.erase(str[start]);
					count -= 1;
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
	//string mystring = "pwwkew";
	string mystring = "geeksforgeeks";
	cout << endl;
	pair<int, int> res = LongestSubstringWithoutDuplicateChars(mystring);
	string subString = mystring.substr(res.first, (res.second - res.first)+1);
	cout << "Longest Sub string with without repeating characters start pos: " << res.first << " end pos: " << res.second << endl;
	cout << "size: " << (res.second - res.first) + 1 << endl;
	cout << "substring: " << subString << endl;

	int t;
	cin >> t;
	return 0;
}