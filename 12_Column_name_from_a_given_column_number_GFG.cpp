#include<iostream>
#include<algorithm>
using namespace std;

string colName (long long int n){
    string ans = "";
    while(n>0){
        ans += ('A' + (n-1)%26);
        n = (n-1)/26;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main()
{
    // long long int N = 13;
    long long int N = 28;
    string ans = colName(N);
    cout << "ans is : " << ans << endl;
    return 0;
}


