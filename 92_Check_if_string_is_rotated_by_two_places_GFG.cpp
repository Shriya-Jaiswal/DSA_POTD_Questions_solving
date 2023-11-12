#include<iostream>
using namespace std;

// ▶️ Ask by ---> Accolite Amazon

bool isRotated(string str1, string str2)
{
    int n=str1.length();
    if(n==2) return str1==str2;
    for(int i=0;i<n;i++){
        if( str1[(i+2)%n]==str2[i] || str1[(n+i-2)%n]==str2[i] ) continue;
        else return false;
    }
    return true;
}

// ⏲️ Expected Time Complexity: O(N).
// 🛢️ Expected Auxilary Complexity: O(N).

int main()
{
    string str1 = "amazon";
    string str2 = "azonam";

    bool ans = isRotated(str1, str2);
    cout << "ans is : " << ans;
    return 0;
}
