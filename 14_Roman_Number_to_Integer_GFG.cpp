#include<iostream>
#include<unordered_map>
using namespace std;

int romanToDecimal(string &str) {
    unordered_map<char,int> mp = {{'I',1}, 
                                  {'V',5}, 
                                  {'X',10}, 
                                  {'L' , 50}, 
                                  {'C',100},
                                  {'D', 500}, 
                                  {'M', 1000}};
    int sum = mp[str.back()];
    for(int i =0; i< str.length()-1; i++){
        if(mp[str[i]] < mp[str[i+1]]){
            sum-= mp[str[i]];
        }
        else{
            sum += mp[str[i]];
        }
    }
    return sum;
}

// ⏲️ Time Complexity --> O(n) --> n is a length of string
// 🛢️ Space complexity --> O(1)


int main()
{
    // string s = "V";
    string s = "III";
    int ans = romanToDecimal(s);
    cout << "ans is : " << ans << endl;    
    return 0;
}
