#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Drishti-Soft

int countNumberswith4(int n) {
    int ans=0;
    for(int i=1;i<=n;i++){
        string s=to_string(i);
        for(int x=0; x<s.length();x++){
            if(s[x]=='4'){
                ans++;
                break;
            }
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(nlogn)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    int  n = 9;
    int ans = countNumberswith4(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
