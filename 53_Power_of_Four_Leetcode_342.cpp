#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// // ▶️ ▶️ ▶️ Approach 1
//  bool isPowerOfFour(int n) {
//     if(n == 0){
//         return false;
//     }

//     while(n%4 == 0){
//         n = n/4;
//     }

//     if(n==1){
//         return true;
//     }
//     return false;
// }

// ▶️ ▶️ ▶️ Approach 2

// bool isPowerOfFour(int n) {
//     if(n<=0){
//         return 0;
//     }        

//     int x = (log(n)/log(4));

//     if(pow(4,x)==n){
//         return true;
//     }
//     return false;
// }


// ▶️ ▶️ ▶️ Approach 3
bool isPowerOfFour(int n) {
   if(n <=0){
    return 0;
   }

   if((n&(n-1)) == 0 && (n-1)%3 == 0){
    return true;
   }
   return false;
}


int main()
{
    int n = 16;
    bool ans = isPowerOfFour(n);
    cout<< "ans is : "<< ans << endl;
    return 0;
}
