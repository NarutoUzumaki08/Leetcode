#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
    priority_queue<int> firstQ;                             // max heap
    priority_queue<int, vector<int>, greater<int>> secondQ; // min heap
    MedianFinder()
    {
    }
    void addNum(int num)
    {
        if (firstQ.empty() || firstQ.top() > num)
            firstQ.push(num);
        else
            secondQ.push(num);
        if (firstQ.size() > secondQ.size() + 1)
        {
            secondQ.push(firstQ.top());
            firstQ.pop();
        }
        else if (secondQ.size() > firstQ.size() + 1)
        {
            firstQ.push(secondQ.top());
            secondQ.pop();
        }
    }
    double findMedian()
    {
        if (firstQ.size() == secondQ.size())
            return (firstQ.top() + secondQ.top()) / 2.0;
        else if (firstQ.size() > secondQ.size())
            return firstQ.top();
        else
            return secondQ.top();
    }
};