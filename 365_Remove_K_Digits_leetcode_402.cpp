#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Microsoft ✯   Bloomberg ✯   Google ✯   Adobe ✯   Facebook   MakeMyTrip  

// ▶️ Using simple Monotonic Nature of Numbers
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1) - I am ignoring the space taken for result variable


string removeKdigits(string num, int k) {
    string res = ""; // 👉 it will act like a stack
    int n = num.length();
    for(int i = 0; i < n; i++) {   
        while(res.length() > 0 && res.back() > num[i] && k > 0) {
            res.pop_back();
            k--;
        }   
        if(res.length() > 0 || num[i] != '0') {
            res.push_back(num[i]); //to avoid the case when we have preceeding zeros
        }       
    }   
    while(res.length() > 0 && k > 0) {
        res.pop_back();
        k--;
    }
    if(res == "") {
        return "0";
    }
    return res;    
}



int main()
{
    string num = "1432219";
    int k = 3;
    string ans = removeKdigits(num,k);
    cout << "ans is :" << ans << endl;
    return 0;
}
