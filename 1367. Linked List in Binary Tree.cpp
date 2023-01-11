#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    bool ans = false;
    bool check(TreeNode *root, ListNode *head)
    {
        if (!head)
            return true;
        if (!root)
            return false;
        if (head->val != root->val)
            return false;
        bool check1 = check(root->left, head->next), check2 = check(root->right, head->next);
        return check1 || check2;
    }
    void helper(TreeNode *root, ListNode *head)
    {
        if (!root)
            return;
        if (root->val == head->val)
            ans = ans || check(root, head);
        helper(root->left, head);
        helper(root->right, head);
    }
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (!root)
            return false;
        helper(root, head);
        return ans;
    }
};