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
    void reorderList(ListNode *head)
    {
        stack<ListNode *> st;
        ListNode *ptr = head;
        int n = 0;
        while (ptr)
        {
            st.push(ptr);
            ptr = ptr->next;
            n++;
        }
        ptr = head;
        // ListNode *lastt = NULL;
        for (int i = 1; i <= n / 2; i++)
        {
            ListNode *last = st.top();
            st.pop();
            last->next = ptr->next;
            ptr->next = last;
            ptr = ptr->next->next;
        }
        ptr->next = NULL;
        // return head;
    }
};