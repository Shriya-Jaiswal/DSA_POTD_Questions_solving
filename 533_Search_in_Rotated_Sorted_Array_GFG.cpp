#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Paytm | Flipkart | Amazon | Microsoft | Snapdeal | D-E-Shaw | FactSet | Hike | MakeMyTrip | Intuit | Adobe | Google | BankBazaar | Times Internet

int search(vector<int>& arr, int key) {
    int low=0,high=arr.size()-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==key)return mid;
        else if(arr[mid]<arr[0]){
            if(key>arr[mid] && key<=arr[high])low=mid+1;
            else high=mid-1;
        }
        else{
            if(key<arr[mid] && key>=arr[low])high=mid-1;
            else low=mid+1;
        }
    }
    return -1;
}


// ⏲️ Expected Time Complexity: O(log n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 10;
    int ans = search(arr,key);
    cout << "ans is : " << ans << endl;
    return 0;
}
