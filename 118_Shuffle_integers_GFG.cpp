#include<iostream>
using namespace std;

// ▶️ Ask by : Amazon | OYO Rooms

void solve(int arr[], int i, int j, int n) {
	if(n <= 0)
	    return;
	        
	int a = arr[i];
	int b = arr[j];
	   
	solve(arr, i-1, j-1, n-2);
	   
	arr[n-2] = a;
	arr[n-1] = b;
}

// 👉 Don't use Extra Space
void shuffleArray(int arr[],int n)
{
	int i=n/2-1;
	int j=n-1;
	solve(arr,i,j,n);
}

// ⏲️ Expected Time Complexity: O(n).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    int n = 4;
    int arr[] = {1, 2, 9, 15};
    shuffleArray(arr,n);
    for(int i=0; i<n; i++){
        cout<< arr[i] <<" ";
    }
    cout<< endl;
    return 0;
}
