#include<iostream>
using namespace std;

// ▶️ Ask by : Amazon

int gameOfXor(int N , int A[]) {
    if(N%2==0){ return 0;}
    int ans=A[0];
    for(int i=2;i<N;i+=2){
        ans^=A[i];
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(N)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    int N = 3; 
    int Arr[] = {1,2,3};
    int ans = gameOfXor(N,Arr);
    cout<< "ans is : " << ans << endl;
    return 0;
}
