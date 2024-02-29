#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Google

long long sumBitDifferences(int arr[], int n) {
	long long ans = 0;
	for(int i = 0;i<32;i++){
	    long long count = 0;
	    for(int j = 0;j<n;j++){
	        if(arr[j]&(1<<i))count++;
	    }
	    ans+=count*(n-count)*2;
	}
	return ans;
}

// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    int n = 2;
    int arr[] = {1, 2};
    long long ans = sumBitDifferences(arr,n);
    cout << "ans is : " << ans << endl;
    return 0;
}
