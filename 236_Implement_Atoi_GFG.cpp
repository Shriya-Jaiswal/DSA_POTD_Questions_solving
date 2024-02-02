#include<iostream>
using namespace std;

// ▶️ Ask by : Morgan Stanley | Amazon | Microsoft | Payu | Adobe | Code Brew

int atoi(string s) {
    int ans=0;
    int sign=1;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='-' && i==0){
            sign=-1;
        }
        else if(s[i]>='0' && s[i]<='9'){
            ans=ans*10+(s[i]-'0');
        }
        else return -1;
    }
    ans=ans*sign;
    return ans;
}

// ⏲️ Expected Time Complexity: O( |s| ), 
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    string s = "-123";
    int ans = atoi(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
