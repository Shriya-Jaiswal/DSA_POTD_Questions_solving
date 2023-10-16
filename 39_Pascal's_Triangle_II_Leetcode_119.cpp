#include<iostream>
#include<vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int>prev;

    for(int i = 0; i < rowIndex+1; i++){
        vector<int> curr(i+1,1);
        for(int j=1; j<i;j++){
            curr[j] = prev[j] + prev[j-1];
        }
        prev = curr;
    }        
    return prev;
}

int main()
{
    int rowIndex = 3;
    vector<int> ans = getRow(rowIndex);
    for(int i = 0; i<ans.size(); i++){
        cout<< ans[i] <<" ";
    }
    cout<< endl;
    return 0;
}
