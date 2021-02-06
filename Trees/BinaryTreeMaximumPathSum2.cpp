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

int res2 = INT_MIN;
int sumHelper2(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftSum = sumHelper2(root->left);
	int rightSum = sumHelper2(root->right);

	int temp = max(leftSum, rightSum) + root->val;
	int ans = max(temp, leftSum + rightSum + root->val);
	res2 = max(res2, ans);

	return temp;
}
int maxPathSum2(TreeNode* root) {

	sumHelper2(root);
	return res2;
}