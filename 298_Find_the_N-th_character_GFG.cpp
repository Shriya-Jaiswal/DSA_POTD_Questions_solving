#include<iostream>
using namespace std;

char nthCharacter(string s, int r, int n) {
    if(r==0) return s[n];
    char c= nthCharacter(s, r-1, n/2);
    if(n%2==1){
        // odd case
        if(c=='0'){
            // 0 1
            return '1';
        }
        else{
            return '0';
        }
    }
    else{
        // even case
        if(c=='0'){
            // 0 1
            return '0';
        }
        else{
            return '1';
        }
    }
}

// ⏲️Expected Time Complexity: O(r*|s|)
// 🛢️ Expected Auxilary Space: O(|s|)

int main()
{
    string s = "1100";
    int r = 2;
    int n = 3;
    char ans = nthCharacter(s,r,n);
    cout << "ans is : " << ans << endl;
    return 0;
}
