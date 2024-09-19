#include<iostream>
#include<algorithm>
using namespace std;

// ▶️ Ask by : Paytm | Accolite | Amazon | Microsoft | Samsung |MakeMyTrip | Goldman Sachs | Adobe | SAP Labs | Cisco

string reverseWords(string str) {
    int j=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='.'){
            reverse(str.begin()+j,str.begin()+i);
            j=i+1;
        }
        else if(i==str.length()-1)reverse(str.begin()+j,str.end());
    }
    reverse(str.begin(),str.end());
    return str;
}

// ⏲️ Expected Time Complexity: O(|str|)
// 🛢️ Expected Auxiliary Space: O(|str|)


int main()
{
    string  str = "i.like.this.program.very.much";
    string ans = reverseWords(str);
    cout << "ans is : " << ans << endl;
    return 0;
}
