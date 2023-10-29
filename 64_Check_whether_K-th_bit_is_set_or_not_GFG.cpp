#include<iostream>
#include<vector>
using namespace std;


bool checkKthBit(int n, int k)
{
    // It can be a one liner logic!! Think of it!!
    while(k--){
        n = n>>1;
    }    
    return n&1;
}

// ⏲️ Time Complexity : Expected Time Complexity: O(1).
// 🛢️ Space complexity : Expected Auxiliary Space: O(1).

int main()
{
    int n = 4;
    int k = 2;
    bool ans = checkKthBit(n,k);
    if(ans == 1){
        cout<< "YES" << endl;
    }
    else{
        cout<< "NO"<< endl;
    }
    return 0;
}
