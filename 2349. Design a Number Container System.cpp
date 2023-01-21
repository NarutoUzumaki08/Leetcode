#include <bits/stdc++.h>
using namespace std;
class NumberContainers
{
public:
    map<int, set<int>> mp1;
    map<int, int> mp2;
    NumberContainers()
    {
    }
    void change(int index, int number)
    {
        int prev = mp2[index];
        if (mp1.find(prev) != mp1.end())
        {
            mp1[prev].erase(index);
            if (mp1[prev].size() == 0)
                mp1.erase(prev);
        }
        mp1[number].insert(index);
        mp2[index] = number;
    }
    int find(int number)
    {
        if (mp1.find(number) == mp1.end())
            return -1;
        return *mp1[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */