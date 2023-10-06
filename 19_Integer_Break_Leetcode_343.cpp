#include<iostream>
#include<vector>
#include<limits.h>
#include<cstring>
using namespace std;


int solveUsingRec(int n){
    if(n==1){
        return 1;
    }
    int result = INT_MIN;
    for(int i = 1; i<=n-1; i++){
        int prod = i * max(n-i, solveUsingRec(n-i));
        result = max(result,prod);
    }
    return result;
} 


// ⏲️ Time complexity ---< O(n*n^n-1) exponential

// ◀️ solve using memoization ---> only one variable hi change ho raha hai that is n toh one dimention dp use ho rahi hai

int t[59];

int solveUsingMem(int n){
    if(n==1){
        return 1;
    }
    if(t[n]!= -1){
        return t[n];
    }
    int result = INT_MIN;
    for(int i = 1; i<=n-1; i++){
        int prod = i * max(n-i, solveUsingMem(n-i));
        result = max(result,prod);
    }
    return t[n] = result;
} 


int integerBreak(int n) {
    // return solveUsingRec(n);

    memset(t,-1, sizeof(t));
    return solveUsingMem(n);
}

// ⏲️ Time complexity ---< O(n * n-1) approximatly O(n^2) 


int main()
{
    int n = 10;
    int ans = integerBreak(n);
    cout<< "ans is : " << ans << endl;
    return 0;
}
