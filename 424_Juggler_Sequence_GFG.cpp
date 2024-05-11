#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// ▶️ Ask by:

vector<long long> jugglerSequence(long long n) {
    vector<long long> ans;
    while(n!=1){
        ans.push_back(n);
        if(n%2){
            n=pow(sqrt(n),3);
        }
        else{
            n=sqrt(n);
        }
    }
    ans.push_back(1);
    return ans;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    long long  n = 9;
    vector<long long> ans = jugglerSequence(n);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
