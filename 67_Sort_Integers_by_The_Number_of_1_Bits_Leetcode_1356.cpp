#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// ▶️ ▶️ Ask by company ---> JPMorgan & Chase ✯   Accenture ✯   Goldman Sachs ✯   Amazon ✯   Apple ✯   Adobe   Infosys  


int countOneBits(int nums){
    int count = 0;

    while(nums){
        count += nums & 1;
        nums >>= 1;
    }
    return count;
}
// ⏲️ Time complexity : log2(nums)

vector<int> sortByBits(vector<int>& arr) {

    auto lambda =[&](int &a, int &b){
        int count_a = countOneBits(a);
        int count_b = countOneBits(b);

        if(count_a == count_b){
            return a<b;
        }

        return count_a < count_b;
    };

    sort(begin(arr),end(arr),lambda);

    return arr;
}


// ➡️ Approach 2 ---> ⏲️ time complexity O(1)
vector<int> sortByBits_Approach2(vector<int>& arr) {

    auto lambda =[&](int &a, int &b){
        int count_a = __builtin_popcount(a); // ⏲️ O(1)
        int count_b = __builtin_popcount(b); // ⏲️ O(1)

        if(count_a == count_b){
            return a<b;
        }

        return count_a < count_b;
    };

    sort(begin(arr),end(arr),lambda);

    return arr;
}

int main()
{
    vector<int> arr {0,1,2,3,4,5,6,7,8};
    vector<int> ans = sortByBits(arr);
    for(int i=0; i<ans.size();i++){
        cout<< ans[i] << " ";
    }
    cout<< endl;
    return 0;
}
