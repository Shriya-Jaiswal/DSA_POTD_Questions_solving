#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Paytm | VMWare | Amazon | Microsoft | Intuit

void rearrange(vector<int> &arr) {
    vector<int> positive,negative;
    for(auto x:arr){
        if(x>=0)positive.push_back(x);
        else negative.push_back(x);
    }
    int i=0,j=0,k=0;
    while(i<positive.size() and j<negative.size()){
        if(k%2)arr[k++]=negative[j++];
        else arr[k++]=positive[i++];
    }
    while(i<positive.size())arr[k++]=positive[i++];
    while(j<negative.size())arr[k++]=negative[j++];
}


// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    vector<int> arr = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    rearrange(arr);
    for(int i = 0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
