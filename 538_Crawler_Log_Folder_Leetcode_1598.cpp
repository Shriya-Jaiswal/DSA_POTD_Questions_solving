#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Mercari ✯  GOOGLE

// ▶️ Approach-1 (Using simple simulation)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int minOperations(vector<string>& logs) {
    int depth = 0;

    for(string &s : logs) {
        if(s == "../") {
            depth = max(0, depth-1);
        } else if(s == "./") {
             continue;
        } else {
            depth++;
        }
    }

    return depth;
}

int main()
{
    vector<string> logs = {"d1/","d2/","../","d21/","./"};
    int ans = minOperations(logs);
    cout << "ans is : " << ans << endl;
    return 0;
}
