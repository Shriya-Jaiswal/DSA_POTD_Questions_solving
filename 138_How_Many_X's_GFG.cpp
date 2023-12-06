#include<iostream>
using namespace std;

// ▶️ Ask by : Amazon

int countX(int L, int R, int X) {
    int count=0;
    for(int a=L+1; a<R; a++){
    int temp =a;
    while(temp > 0){
        int digit = temp % 10; 
        if(digit == X){
                count++;
        }
            temp /=10;
        }
    }
    return count;
}

// ⏲️ Expected Time Complexity:O(RLogR)
// 🛢️ Expected Auxillary Space:O(1)

int main()
{
    int L=10, R=19, X=1;
    int ans = countX(L,R,X);
    cout << "ans is : " << ans << endl;
    return 0;
}
