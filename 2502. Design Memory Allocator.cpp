#include <bits/stdc++.h>
using namespace std;
class Allocator
{
public:
    vector<int> space;
    Allocator(int n)
    {
        space = vector<int>(n);
    }

    int allocate(int size, int mID)
    {
        for (int i = 0; i < space.size();i++)
        {
            int cnt = 0;
            while (space[i] == 0 && i<space.size())
            {
                cnt++;
                i++;
                if (cnt == size)
                {
                    int k = i - size;
                    for (int j = 0; j < size; j++)
                        space[k + j] = mID;
                    return k;
                }
            }
            cnt = 0;
        }
        return -1;
    }

    int free(int mID)
    {
        int cnt = 0;
        for (int i = 0; i < space.size(); i++)
        {
            if (space[i] == mID)
            {
                space[i] = 0;
                cnt++;
            }
        }
        return cnt;
    }
};
