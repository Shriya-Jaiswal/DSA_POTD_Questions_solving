#include<iostream>
#include<unordered_map>
#include<limits.h>
using namespace std;

// ➡️ Ask by : Microsoft | Snapdeal

int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int ans = 0;
	    unordered_map<int, int> mp;
	    int rem = 0;
	    for(int i = 0; i < n; i += 1){
	        rem = (rem + arr[i]%k + k)%k;
	        if(rem == 0){
	            ans = max(ans, i + 1);
	        }else if(mp.find(rem) == mp.end()){
	            mp[rem] = i;
	        }else{
	            ans = max(ans, i - mp[rem]);
	        }
	    }
	    return ans;
}

// ⏲️ Expected Time Complexity: O(N).
// 🛢️ Expected Auxiliary Space: O(N).

int main()
{
    int N = 6;
    int K = 3;
    int arr[] = {2, 7, 6, 1, 4, 5};
    int ans = longSubarrWthSumDivByK(arr,N,K);
    cout << "ans is : " << ans << endl;
    return 0;
}
