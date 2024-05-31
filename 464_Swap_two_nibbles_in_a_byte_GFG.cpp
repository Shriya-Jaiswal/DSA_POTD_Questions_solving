#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Accolit | Samsung | Cisco | Qualcomm

int swapNibbles(int n) {
    int rn=n &  (0b11110000);
    int ln=n & (0b00001111);
        
    rn=rn>>4;
    ln=ln<<4;
        
    return rn | ln;
}

// ⏲️ Expected Time Complexity: O(1)
// 🛢️ Expected Space Complexity: O(1)

int main()
{
    int n = 100;
    int ans = swapNibbles(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
