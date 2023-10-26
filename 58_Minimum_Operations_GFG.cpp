#include<iostream>
#include<vector>
using namespace std;

int minOperation(int n)
{
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    int steps = 2;
    while(n>2){
        if(n%2==0){
            n = n/2;
        }
        else{
            n = n-1;
        }
        steps++;
    }
    return steps;
}

// ⏲️ Time Complexity : Expected Time Complexity: O(LogN)
// 🛢️ Space Complexity : Expected Auxiliary Space: O(1)

int main()
{
    int n = 8;
    int ans = minOperation(n);
    cout << "ans is : " << ans << endl; 
    return 0;
}
