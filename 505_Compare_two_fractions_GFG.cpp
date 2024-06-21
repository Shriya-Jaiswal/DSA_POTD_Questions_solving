#include<iostream>
using namespace std;

string compareFrac(string s) {
    int i=0, n=s.length();
    double a=0, b=0, c=0, d=0;
    while(s[i]!='/'){
        a=a*10+(s[i]-'0');
        i++;
    }
    i++;
        
    while(s[i]!=','){
        b=b*10+(s[i]-'0');
        i++;
    }
    i+=2;
        
    while(s[i]!='/'){
        c=c*10+(s[i]-'0');
        i++;
    }
    i++;
        
    while(i<n){
        d=d*10+(s[i]-'0');
        i++;
    }
        
        
    string fraction1=to_string(int(a))+'/'+to_string(int(b));
    string fraction2=to_string(int(c))+'/'+to_string(int(d));
        
    if(a/b==c/d) return "equal";
    else if(a/b > c/d) return fraction1;
    else return fraction2;
}

// ⏲️ Expected Time Complexity: O(len|str|)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    string str = "5/6, 11/45";
    string ans = compareFrac(str);
    cout << "ans is : " << ans << endl;
    return 0;
}
