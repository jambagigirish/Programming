#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>   
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int solve(TreeNode* root, int&res)
{
	if (root == NULL){
		return 0;
	}
	int lr = solve(root->left, res);
	int rr = solve(root->right, res);

	int temp = max(lr, rr) + 1;
	int ans = max(temp, lr + rr + 1);

	res = max(res, ans);

	return temp;
}
int diameterOfBinaryTree(TreeNode* root) {
	if (root == NULL){
		return 0;
	}
	int res = INT_MIN;
	solve(root, res);

	return res - 1;
}