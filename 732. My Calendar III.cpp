#include <bits/stdc++.h>
using namespace std;
class MyCalendarThree
{
public:
    vector<pair<int, int>> events;
    MyCalendarThree()
    {
    }

    int book(int start, int end)
    {
        events.push_back({start, end});
        int n = events.size(), cnt = 0;
        for (int i = 0; i < n; i++)
        {
            
        }
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */