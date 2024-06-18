#include<iostream>
#include<vector>
using namespace std;

int rectanglesInCircle(int r) {
    int ans=0;
    for(int x=1;x<=2*r;x++){
        for(int y=1;y<=2*r;y++){
            if(x*x + y*y <= 4*r*r){
                ans++;
            }
        }
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(r2)
// 🛢️ Expected Auxillary Space: O(1)

int main()
{
    int r =1;
    int ans = rectanglesInCircle(r);
    cout << "ans is : " << ans << endl;
    return 0;
}
