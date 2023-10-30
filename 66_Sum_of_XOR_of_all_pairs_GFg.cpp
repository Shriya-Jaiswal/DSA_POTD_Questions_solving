#include<iostream>
#include<vector>
using namespace std;

long long int sumXOR(int arr[], int n)
{
    long long sum = 0;
    for(int bit = 0; bit < 32; bit++){
        long long int set_bits = 0;
        long long int unset_bits = 0;

        for(int j=0; j<n; j++){
            if((arr[j]&(1 << bit)) != 0){
                set_bits++;
            }
            else{
                unset_bits++;
            }
        }
        long long possible_combinations = (set_bits)*(unset_bits);
        sum += possible_combinations*(1 << bit);
    }
    return sum;
}

// ⏲️ Time Complexity : Expected Time Complexity: O(n).
// 🛢️ Space complexity : Expected Auxiliary Space: O(1).


int main()
{
    int arr[ ] = {7, 3, 5};
    int n = 3;
    long long int ans = sumXOR(arr,n);
    cout << "ans is : " << ans << endl;
    return 0;
}
