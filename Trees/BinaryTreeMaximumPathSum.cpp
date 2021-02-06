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

int res = INT_MIN;
int sumHelper(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftSum = sumHelper(root->left);
	int rightSum = sumHelper(root->right);

	int temp = max(leftSum, rightSum) + root->val;
	temp = max(temp, root->val);

	int ans = max(temp, leftSum + rightSum + root->val);
	res = max(res, ans);

	return temp;
}
int maxPathSum(TreeNode* root) {

	sumHelper(root);
	return res;
}