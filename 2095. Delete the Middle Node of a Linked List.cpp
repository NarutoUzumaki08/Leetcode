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
    ListNode *deleteMiddle(ListNode *head)
    {
        int count = 0;
        ListNode *fast = head;
        while (fast != NULL)
        {
            count++;
            fast = fast->next;
        }
        if (count == 1)
            return NULL;
        if (count == 2)
        {
            head->next = NULL;
            return head;
        }
        int mid = (count) / 2;
        ListNode *slow = head;
        for (int i = 1; i <= mid; i++)
            slow = slow->next;
        ListNode *temp = slow->next->next;
        slow->val = slow->next->val;
        slow->next = temp;
        return head;
    }
};


// 1 2 3 4 5 6 7