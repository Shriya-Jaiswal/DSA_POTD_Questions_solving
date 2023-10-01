#include <iostream>
#include<vector>
using namespace std;


vector<int> duplicates(int arr[], int n){

    vector<int> ans;
    for(int i=0; i<n;i++){
        int index = arr[i]%n;
        arr[index]+=n; 
    }

    for(int i =0; i<n;i++){
        if((arr[i]/n)>=2){
            ans.push_back(i);
        }
    }

    if(ans.size()==0){
        return {-1}; // 👈 it means we are returning vector --> itself it create vector which containg -1
    }
    return ans;
}
 
int main()
{
    int n ;
    cout << "enter n : " << endl; // 👈 only write here this line
    cin >> n;
    // int arr[] = {0,3,1,2};         
    int arr[] = {2,3,1,2,3};         
    vector<int> ans = duplicates(arr,n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}
