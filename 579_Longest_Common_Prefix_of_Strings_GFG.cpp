#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : VMWare | Microsoft | Google

string longestCommonPrefix(vector<string> arr) {
    int minlen=1000,count=0;
    int n=arr.size();
    string str;
    string ans;
    for(int i=0;i<n;i++){
        int len=arr[i].length();
        if(len<minlen){
            minlen=len;
            str=arr[i];
        }
    }
        
    for(int i=0;i<minlen;i++){
        for(int j=0;j<n;j++){
            if(arr[j][i]!=str[i]){
                str= str.substr(0,count);
            }
        }
        count++;
    }
        
    if(str.length()==0)
    return "-1";
        
    return str;
}

// ⏲️ Expected Time Complexity: O(n*min(|arri|))
// 🛢️ Expected Space Complexity: O(min(|arri|))

int main()
{
    vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};
    string ans = longestCommonPrefix(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
