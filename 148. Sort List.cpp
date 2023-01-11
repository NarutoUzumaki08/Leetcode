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
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (!left)
            return right;
        if (!right)
            return left;
        ListNode *ans = new ListNode(-1);
        ListNode *ansCopy = ans;
        while (left && right)
        {
            if (left->val < right->val)
            {
                ansCopy->next = left;
                ansCopy = left;
                left = left->next;
            }
            else
            {
                ansCopy->next = right;
                ansCopy = right;
                right = right->next;
            }
        }
        while (left)
        {
            ansCopy->next = left;
            ansCopy = left;
            left = left->next;
        }
        while (right)
        {
            ansCopy->next = right;
            ansCopy = right;
            right = right->next;
        }
        return ans->next;
    }
    ListNode *mergeSort(ListNode *head)
    {
        if (!head || !(head->next))
            return head;
        ListNode *mid = findMid(head);
        ListNode *left = head, *right = mid->next;
        mid->next = NULL;
        left = mergeSort(left), right = mergeSort(right);
        ListNode *res = merge(left, right);
        return res;
    }
    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
    }
};