#include<iostream>
#include<vector>
using namespace std;

string oddEven(string s) {
    int x=0, y=0;
    vector<int>count(27,0);
    for(int i=0;i<s.length();i++){
        count[s[i]-'a'+1]++;
    }
        
    for(int i=1;i<=26;i++){
        if(count[i]!=0 && count[i]%2==0 && i%2==0){
            x++;
        }
        else if(count[i]%2==1 && i%2==1){
            y++;
        }
    }
    int sum = x+y;
    if(sum%2==1) return "ODD";
    else return "EVEN";
}

// ⏲️ Expected Time Complexity: O(|s|)
// 🛢️ Expected Auxiliary Space: O(1) 

int main()
{
    string s = "abbbcc";
    string ans = oddEven(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
