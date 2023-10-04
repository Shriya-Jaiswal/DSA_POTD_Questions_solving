#include<iostream>
#include<vector>
#include<list>
using namespace std;

// 🌟 very important question asked by multiple company

class MyHashMap {
public:
    vector<int>m;
    int size ;

    MyHashMap() {
        size = 1e6 + 1; // +1 because index 0 to 10^6 tk bn jayenge  and +1 nahi lgayenge to 10^6 -1 tk indexes range bn jayenge    
        m.resize(size);
        fill(m.begin(),m.end(),-1);
    }
    
    void put(int key, int value) {
        m[key] = value;
    }
    
    int get(int key) {
        return m[key];
    }
    
    void remove(int key) {
        m[key] = -1;
    }
};


// ➡️ Approach 2 ---> increase range ---> we will use hashing --> and here we are handling the collision
// ◀️ Linked List bna rahe hai 
// 👉 hashing function is a constant function 
class MyHashMap_Approach_2 {
public:
    vector<list<pair<int,int>>>m;
    int size ;

    MyHashMap_Approach_2() {
        // size = 1e6 + 1; // +1 because index 0 to 10^6 tk bn jayenge  and +1 nahi lgayenge to 10^6 -1 tk indexes range bn jayenge    
        size = 10000;
        m.resize(size);
    }

    // 👉 create hashing function
    int hash(int key){
        return key % size;
    }
    
    // 👉 create search function
    list<pair<int,int>> :: iterator search(int key){
        // 👉 we have to return the position ---> iterator return krana hai
        // 👇 find index
        int i = hash(key);
        // 👉 create iterator
        list<pair<int,int>> :: iterator it = m[i].begin();
        while(it != m[i].end()){
            if(it -> first == key){
                return it;
            }
            it++;
        }
        return it;
    }
    void put(int key, int value) {
        //👉 find out index
        int i = hash(key);
        remove(key); 
        m[i].push_back({key,value});
    }
    
    int get(int key) {
        int i = hash(key); // 👉 we get our index
        list<pair<int,int>> :: iterator it = search(key);
        if(it == m[i].end()){
            return -1;
        }
        else{
            return it -> second;
        }
    }
    
    void remove(int key) {
        int i = hash(key);
        list<pair<int,int>> :: iterator it = search(key);
        if(it != m[i].end()) m[i].erase(it);
    }
};

int main()
{
    
    return 0;
}
