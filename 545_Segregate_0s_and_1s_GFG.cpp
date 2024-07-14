#include<iostream>
#include<vector>
using namespace std;


// ▶️ Ask by : Paytm | Goldman Sachs | Fab.com

void segregate0and1(vector<int> &arr) {
    int zero=0,one=arr.size()-1;
    while(zero<one){
        if(arr[zero]){
            swap(arr[zero],arr[one]);
            one--;
        }
        else zero++;
    }
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<int>  arr = {0, 0, 1, 1, 0};
    segregate0and1(arr);
    for(int i=0; i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
