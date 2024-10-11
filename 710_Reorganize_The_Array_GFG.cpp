#include<iostream>
#include<vector>
using namespace std;

 
vector<int> rearrange(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);  // Initialize result array with -1
    
    // Traverse the input array and place elements at their correct positions
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1 && arr[i] < n) {
            result[arr[i]] = arr[i];  // Place element in the correct index
        }
    }
    
    return result;  // Return the rearranged array
}

int main()
{
    vector<int>  arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    vector<int> ans = rearrange(arr);
    for(int i = 0 ; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout<< endl;
    return 0;
}
