#include <bits/stdc++.h>
using namespace std;
class SmallestInfiniteSet
{
public:
    set<int> st;
    SmallestInfiniteSet()
    {
    }

    int popSmallest()
    {
        int ans = *st.begin();
        st.erase(st.begin());
        return ans;
    }

    void addBack(int num)
    {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */