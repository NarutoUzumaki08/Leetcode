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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummy = new ListNode(0), *curr = dummy;
        dummy->next = head;
        map<int, ListNode *> mp;
        int sum = 0;
        while (curr)
        {
            sum += curr->val;
            if (mp.count(sum))
            {
                curr = mp[sum]->next;
                int currSum = sum + curr->val;
                while (currSum != sum)
                {
                    mp.erase(currSum);
                    curr = curr->next;
                    currSum += curr->val;
                }
                mp[sum]->next = curr->next;
            }
            else
                mp[sum] = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};