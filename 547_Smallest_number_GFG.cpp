#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : OYO Rooms | MAQ Software

string smallestNumber(int s, int d) {
    string ans="";
    int i=1;
    while(i<=d){
        int num = s-(d-i)*9<=0?0:s-(d-i)*9;
        if(num==0 and i==1)num=1;
        if(num>9)return "-1";
        ans+=(num+'0');
        i++;
        s-=num;
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(d)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    int  s = 9;
    int d = 2;
    string ans = smallestNumber(s,d);
    cout << "ans is : " << ans << endl;
    return 0;
}
