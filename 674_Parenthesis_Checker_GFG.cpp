#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

// ▶️ Ask by : Flipkart | Amazon | Microsoft | OYO Rooms | Snapdeal | Oracle | Walmart | Adobe | Google | Yatra.com

bool ispar(string x)
{
    unordered_map<char,char> mm;
    mm[')']='(';
    mm[']']='[';
    mm['}']='{';
    stack<char> st;
    for(auto c:x){
        if(c=='(' or c=='[' or c=='{')st.push(c);
        else if(st.empty())return false;
        else{
            if(st.top()!=mm[c])return false;
            st.pop();
        }
    }
    return st.empty();
}


// ⏲️ Expected Time Complexity: O(|x|)
// 🛢️ Expected Auixilliary Space: O(|x|)

int main()
{
    string s = "{([])}";
    bool ans = ispar(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
