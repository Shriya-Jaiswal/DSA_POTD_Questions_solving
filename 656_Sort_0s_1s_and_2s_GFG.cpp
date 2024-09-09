#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Paytm | Flipkart | Morgan Stanley | Amazon | Microsoft | OYO Rooms | Samsung | Snapdeal | Hike | MakeMyTrip | Ola Cabs | Walmart | MAQ Software | Adobe | Yatra.com | SAP Labs | Qualcomm

void sort012(vector<int>& arr) {
    int n = arr.size(), zero = 0, two = n-1, i = 0;
    while(i<=two){
        if(arr[i]==0){
            swap(arr[zero],arr[i]);
            zero++;
        }
        else if(arr[i]==2){
            swap(arr[i],arr[two]);
            two--;
            i--;
        }
        i++;
    }
}


// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<int> arr= {0, 2, 1, 2, 0};
    sort012(arr);
    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
