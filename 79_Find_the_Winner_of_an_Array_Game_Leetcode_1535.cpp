// #include<iostream>
// #include<vector>
// #include <cmath>
#include <bits/stdc++.h>
using namespace std;

int getWinner(vector<int>& arr, int k) {
    int n = arr.size();
    int maxEle = *max_element(begin(arr), end(arr));
        
        if(k >= n)
            return maxEle;
        
        int winner = arr[0];
        int wins   = 0;

        for(int i = 1; i<n; i++) {
            if(winner > arr[i]) {
                wins++;
            } else {
                winner = arr[i];
                wins   = 1;
            }
            if(wins == k || winner == maxEle) {
                return winner;
            }
        }
        return winner;      
}

int main()
{
    vector<int> arr {2,1,3,5,4,6,7};
    int k = 2;
    int ans= getWinner(arr,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
