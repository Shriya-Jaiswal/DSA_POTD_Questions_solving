#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Zoho | Snapdeal

bool kPangram(string str, int k) {
    vector<int>arr(26,0);
    int n=str.size();
    int ch=0;
    for(int i=0;i<n;i++){
        if(str[i]!=' '){
            arr[str[i]-'a']=1;
            ch++;
        }
    }
    int c=0;
    for(int i=0;i<26;i++){
        if(arr[i]==0){
            c++;
        }
    }
    if(ch<26 || c>k) return false;
    return true;
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)  

int main()
{
    string str = "the quick brown fox jumps over the lazy dog";
    int k = 0;
    bool ans = kPangram(str,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
