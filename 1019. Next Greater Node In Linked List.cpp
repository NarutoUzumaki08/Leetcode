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
class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head;
        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
        return head;
    }
    vector<int> nextLargerNodes(ListNode *head)
    {
        head = reverse(head);
        vector<int> ans;
        stack<int> s;
        while (head)
        {
            while (!s.empty() && s.top() <= head->val)
                s.pop();
            if (s.empty())
                ans.push_back(0);
            else
                ans.push_back(s.top());
            s.push(head->val);
            head = head->next;
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};