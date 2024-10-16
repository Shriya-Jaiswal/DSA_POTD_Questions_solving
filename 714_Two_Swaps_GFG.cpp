#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : 

bool checkSorted(vector<int> &arr) {
    int count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=i+1){
            swap(arr[i],arr[arr[i]-1]);
            count++;
            i--;
        }
        if(count>2)return false;
    }
    return count==2|count==0;
}


int main()
{
    vector<int> arr = {4, 3, 2, 1};
    bool ans = checkSorted(arr);
    cout << "ans is : " << ans << endl;
    return 0;
}
