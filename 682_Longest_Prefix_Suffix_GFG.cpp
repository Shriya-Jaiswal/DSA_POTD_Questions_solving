#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Accolite | Amazon | Microsoft | MakeMyTrip

int lps(string str) {
    int i=1,j=0,n=str.length();
    vector<int> storeLength(n,0);
    while(i<n){
        if(str[i]==str[j])storeLength[i++]=++j;
        else{
            if(j>0)j=storeLength[j-1];
            else i++;
        }
    }
    return storeLength[n-1];
}


// ⏲️ Expected Time Complexity: O(|str|)
// 🛢️ Expected Auxiliary Space: O(|str|)

int main()
{
    string str = "abab";
    int ans = lps(str);
    cout << "ans is : " << ans << endl;
    return 0;
}
