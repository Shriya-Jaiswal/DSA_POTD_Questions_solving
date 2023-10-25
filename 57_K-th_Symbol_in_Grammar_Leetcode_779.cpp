#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// ▶️ AmaZon Adobe 

int kthGrammar(int n, int k) {
    if(n == 1 && k == 1){
        return 0;
    }        

    int length = pow(2, n-1);
    int mid = length/2;

    if(k <= mid){
        return kthGrammar(n-1, k);
    }
    return !kthGrammar(n-1, k-mid);
}

int main()
{
    int n = 1;
    int k = 1;   
    int ans = kthGrammar(n,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
