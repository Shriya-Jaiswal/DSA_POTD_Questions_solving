#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Goldman Sachs ✯   Apple ✯   Salesforce ✯  


int heightChecker(vector<int>& heights) {
    vector<int> arr(heights.begin(), heights.end());
    sort(arr.begin(),arr.end());
    int count = 0;
    for(int i=0; i<heights.size();i++){
        if(arr[i]!=heights[i]){
            count++;
        }
    }        
    return count;
}

int main()
{
    vector<int> heights = {1,1,4,2,1,3};
    int ans = heightChecker(heights);
    cout << "ans is : " << ans << endl;
    return 0;
}
