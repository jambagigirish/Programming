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

vector<int> FindAnagrams(string str, string pat){
	vector<int> res;
	unordered_map<char, int> mp;
	int count = 0;

	for (char c : pat){
		mp[c]++;
	}
	count = mp.size();

	int start = 0;
	int end = 0;
	int len = str.length();
	int k = pat.length();
	while (end < len){

		if (mp.find(str[end]) != mp.end()){
			mp[str[end]]-=1;

			if (mp[str[end]] == 0){
				count -= 1;
			}
		}

		if (end - start + 1 < k)
		{
			end++;
		}
		else if (end - start + 1 == k){
			if (count == 0){
				res.push_back(start);
			}
			if (mp.find(str[start]) != mp.end()){
				mp[str[start]] += 1;

				if (mp[str[start]] == 1){
					count += 1;
				}
			}
			end++;
			start++;
		}
	}
	return res;
}

int main()
{
	/*string txt = "forxxorfxdofr";
	string pat = "for";*/

	string txt = "cbaebabacd";
	string pat = "abc";
	cout << endl;
	vector<int> res = FindAnagrams(txt, pat);

	cout << "Count of anagrams: " << res.size() <<endl;
	cout << "Anagrams positions: ";
	for (int i = 0; i < res.size(); i++){
		cout << res[i] << " ";
	}

	int t;
	cin >> t;
	return 0;
}