#include <bits/stdc++.h>
using namespace std;
class TimeMap
{
public:
    map<string, set<pair<int, string>>> mp;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].insert({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        auto it = mp[key].lower_bound({timestamp, ""});
        if (it->first == timestamp)
            return it->second;
        if (it == mp[key].begin())
            return "";
        return (--it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */