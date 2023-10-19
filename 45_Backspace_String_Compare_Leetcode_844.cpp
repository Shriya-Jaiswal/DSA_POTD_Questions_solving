#include<iostream>
#include<vector>
using namespace std;

// ▶️ leetcode Hard --> Ask by Google
// ➡️ approach 1 ---> take temp string ---> sapce complexity 🛢️ (m+n)
// ➡️ Approach 2 --> reversal traversal from back  ---> space complexity 🛢️ O(1)

// ▶️ Aprroach 1 code
string buildString(string &s){
    string temp = "";
    int n = s.length();

    int i = 0;
    while(i<n){
        if(s[i] != '#'){
            temp.push_back(s[i]);
        }
        else if(s.length() > 0){
            temp.pop_back();
        }
        i++;
    }
    return temp;
}

bool backspaceCompare(string s, string t) {

    // // ▶️ approach 1 
    // string buildForm_s = buildString(s); 
    // string buildForm_t = buildString(t); 

    // return buildForm_s == buildForm_t;

// ▶️ Approach 2

    int m = s.length();
    int n = t.length();

    int i = m-1;
    int j = n-1;

    int skip_s = 0;
    int skip_t = 0;

    while(i>=0 || j >= 0){
        while(i >= 0){
            if(s[i] == '#'){
                skip_s++;
                i--;
            }
            else if(skip_s > 0){
                skip_s--;
                i--;
            }
            else{
                break;
            }
        }


    // 👉 similarity for j
         while(j >= 0){
            if(t[j] == '#'){
                skip_t++;
                j--;
            }
            else if(skip_t > 0){
                skip_t--;
                j--;
            }
            else{
                break;
            }
        }

        char first = i < 0  ? 's' : s[i];
        char second = j < 0 ? 's' : t[j];

        if(first != second){
            return false;
        }
        i--;
        j--;
    }       
    return true; 
}

int main()
{
    string s = "ab#c";
    string t = "ad#c";
    bool ans = backspaceCompare(s, t);
    cout << "ans is : " << ans << endl;
    return 0;
}
