#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// ▶️ ▶️ Ask by company ---> JPMorgan & Chase ✯   Accenture ✯   Goldman Sachs ✯   Amazon ✯   Apple ✯   Adobe   Infosys  


int countOneBits(int nums){
    int count = 0;

    while(nums){
        count += nums & 1; // 👉 find last bit as a set
        nums >>= 1; // 👉 right shift
    }
    return count;
}

//                      👇 sorting
// ⏲️ Time complexity : O(nlog(n)) * O(log2(nums)) 

vector<int> sortByBits(vector<int>& arr) {

    //           👇 [] capture clause ---> used for capture outside declared variable in comparator --> here we are taking by ref 
    auto lambda = [&](int &a, int &b){
        int count_a = countOneBits(a);
        int count_b = countOneBits(b);

        if(count_a == count_b){
            return a<b; // 👉 assending order me sort krdo
        }

        return count_a < count_b; // 👉assending on basis 1 bit
    };

    sort(begin(arr),end(arr),lambda); // 👉 lambda is a comparator

    return arr;
}


// ➡️ Approach 2 ---> with out write another function for count bits ---> we have a STL function 👉 __buildin_popcount() ----> jisme hum koi bhi number pass karenge toh uss number ke corresponding binary representation me 1 bit kitne hai woh bta dega  ⏲️ time complexity O(1)

// ➡️ 👉 in java inbuild count set bit function is : 👉 Integer.bitcount(nums);

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

// :time Time complexity overall ---> O(nlogn) ---> for sorting

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
