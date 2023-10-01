#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > fourSum(vector<int> &arr, int target) {
   vector<vector<int>> ans;

        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0; i<n;i++){
            if(i>0 && arr[i]==arr[i-1]){
                continue;
            }
            for(int j=i+1; j<n; j++){
                if(j!=i+1 && arr[j]==arr[j-1]){
                    continue;
                }
                int k=j+1;
                int l = n-1;
                while(k<l){
                    int sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if(sum == target){
                        ans.push_back({arr[i],arr[j],arr[k],arr[l]});
                        l--;
                        k++;
                        while(k<l && arr[l]==arr[l+1]){
                            l--;
                        }
                        while(k<l && arr[k]==arr[k-1]){
                            k++;
                        }
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        k++;
                    }
                }
            }
        }
        return ans;
}

int main()
{
    int N = 5; 
    int K = 3;
    vector<int> arr {0,0,2,1,1};
    // vector<vector<int>> ans = fourSum(arr,K);

    //  for (int i = 0; i < arr.size(); i++) {
    //     for (int j = 0; j < arr[i].size(); j++)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }
    
    return 0;
}
