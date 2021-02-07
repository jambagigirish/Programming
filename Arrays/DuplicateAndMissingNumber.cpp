#include "../stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>   
using namespace std;

void DuplicateAndMissingNumber(vector<int>& nums){
	vector<int> missing;
	vector<int> duplicate;
	int n = nums.size();
	int i = 0;
	while (i < n){
		if (nums[i] == i + 1){
			//cout << nums[i];
			i++;
		}
		else{
			//cout << nums[i];
			if (nums[nums[i] - 1] == nums[i]){
				i++;
			}
			else{
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
	}

	for (int j = 0; j < n; j++){
		//cout << nums[j];
		if (nums[j] == j + 1){
			//don't do 
		}
		else{
			missing.push_back(j + 1);
			duplicate.push_back(nums[j]);
		}
	}

	cout << "Missing: " << endl;
	for (int j = 0; j < missing.size(); j++){
		cout << missing[j] << endl;
	}
	cout << "duplicate: " << endl;
	for (int j = 0; j < duplicate.size(); j++){
		cout << duplicate[j] << endl;
	}
}

int main()
{
	vector<int> myVector = { 2, 1, 5, 6, 2, 3 };
	vector<int> myVector1 = { 3, 1, 1, 5, 3 };
	//						  1, 2, 3, 4, 5	
	cout << endl;
	DuplicateAndMissingNumber(myVector);
	DuplicateAndMissingNumber(myVector1);

	int t;
	cin >> t;
	return 0;
}