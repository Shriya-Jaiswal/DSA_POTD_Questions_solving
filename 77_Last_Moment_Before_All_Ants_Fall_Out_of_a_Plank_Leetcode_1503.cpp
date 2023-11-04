#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by Google ---> Aptitude type question
// ▶️ Leetcode medium 1503

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int result = 0;
    // 👉 left side
    for(int &x : left){
        result = max(result,x);
    }
    // 👉 right side
    for(int &x : right){
        result = max(result,n-x);
    }

    return result;
}

int main()
{
    int n = 4;
    vector<int> left {4,3};
    vector<int> right {0,1};

    int ans = getLastMoment(n,left,right);
    cout << "ans is : " << ans << endl;
    return 0;
}
