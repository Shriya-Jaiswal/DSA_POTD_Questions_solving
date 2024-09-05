#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Microsoft ✯  

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    int l = m+n;
    int sum = 0;
    for(auto arr : rolls ){
        sum += arr;
    }        
    int total = l*mean;
    int left = total-sum;
    if(left >=n && left <= 6*n){
        vector<int> ans ;
        int each = left/n;
        int rem = left%n;
        while(n--){
            int extra = 0;
            if(rem>0){
                rem--;
                extra = 1;
            }
            ans.push_back(each + extra);
        }
        return ans;
    }
    vector<int> x;
    return x;
}

int main()
{
    vector<int> rolls = {3,2,4,3};
    int mean = 4;
    int n = 2;
    vector<int> ans = missingRolls(rolls,mean,n);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
