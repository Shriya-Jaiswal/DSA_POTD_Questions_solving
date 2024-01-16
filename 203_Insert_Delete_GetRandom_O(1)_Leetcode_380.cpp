#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// ▶️ Ask by :  Facebook ✯   Bloomberg ✯   Amazon ✯   LinkedIn ✯   Microsoft ✯   Affirm   Uber   Twitter   Google  

class RandomizedSet {
public:
    /* 👉 Initialize your data structure here. */
    vector<int> vec;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    /* 👉 Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) != mp.end())
            return false;
        
        vec.push_back(val);
        mp[val] = vec.size()-1;
        return true;
    }
    
    /* 👉 Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;
        
        int idx       = mp[val];
        int temp      = vec.back();
        vec.back()    = val;
        vec[idx]      = temp;
        mp[temp]      = idx;
        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    /* 👉 Get a random element from the set. */
    int getRandom() {
        int idx = rand()%vec.size();
        return vec[idx];
    }
};

int main()
{
    
    return 0;
}
