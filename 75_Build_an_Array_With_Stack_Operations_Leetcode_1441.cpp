#include<iostream>
#include<vector>
using namespace std;

// ➡️ Medium Leetcode ---> 1441
// ▶️ Ask by ---> Google

vector<string> buildArray(vector<int>& target, int n) {
    int stream = 1;
    vector<string> result;

    int i=0;
    while(i<target.size() && stream <= n){
        result.push_back("Push");
        if(target[i] == stream){
            i++;
        }
        else{
            result.push_back("Pop");
        }
        stream++;
    }        
    return result;
}

// ⏲️ Time complexity : O(n) --> n is a target 

int main()
{
    vector<int> target {1,3};
    int n = 3;
    vector<string> ans = buildArray(target,n);
    for (int i = 0; i < ans.size(); i++){
        cout<< ans[i] << " ";
    }
    cout<< endl;
    
    return 0;
}
