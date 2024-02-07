#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;

// // ➡️ Approach-1 (Using Simple vector of pair and sorting it -  O(nlogn)

// typedef pair<char, int> P;

// string frequencySort(string s) {
//     vector<P> vec(123);
        
//     for(char &ch : s) {
//         int freq = vec[ch].second;
//         vec[ch] = {ch, freq+1};
//     }
        
//     auto comp = [&](P &p1, P &p2) {
//         return p1.second > p2.second;
//     };
        
//     sort(begin(vec), end(vec), comp);
        
//     string result = "";
        
//     for(int i = 0; i <= 122; i++) {
//         result += string(vec[i].second, vec[i].first);
//     }
//     return result;
// }


// ▶️ Approach-2 (Using Priority Queue) - O(nlong)

typedef pair<char, int> P;
struct comp {
    bool operator()(P &p1, P &p2) {
        return p1.second<p2.second; //max-heap
    }
};
    
string frequencySort(string s) {
    priority_queue<P, vector<P>, comp> pq;
        
    unordered_map<char, int> mp;
    for(char &ch : s) {
            mp[ch]++;
    }
        
    for(auto &it : mp) {
        pq.push({it.first, it.second});
    }
        
    string result = "";
        
    while(!pq.empty()) {
        P temp = pq.top();
        pq.pop();
            
        result += string(temp.second, temp.first);
    }
    return result;
}

int main()
{
    string  s = "tree";
    string ans = frequencySort(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
