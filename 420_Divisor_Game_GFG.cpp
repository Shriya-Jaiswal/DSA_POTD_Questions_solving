#include<iostream>
#include<vector>
using namespace std;

 bool divisorGame(int n) {
    return n%2==0;
}

// ⏲️ Expected Time Complexity: O(1)
// 🛢️ Expected Auxiliary Space: O(1) 

int main()
{
    int n = 2;
    bool ans = divisorGame(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
