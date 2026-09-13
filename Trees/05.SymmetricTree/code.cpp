#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool isEqual(TreeNode *leftSub, TreeNode *rightSub)
    {
        if (leftSub == nullptr || rightSub == nullptr)
            return leftSub == rightSub;
        return leftSub->val == rightSub->val && isEqual(leftSub->left, rightSub->right) && isEqual(leftSub->right, rightSub->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return isEqual(root->left, root->right);
    }
};