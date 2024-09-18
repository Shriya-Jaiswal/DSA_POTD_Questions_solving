#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// // ▶️ Ask by :  Salesforce ✯   Microsoft ✯   Facebook ✯   Amazon ✯   Apple ✯   Adobe   Goldman Sachs   Visa   Oracle  MakeMyTrip, Paytm, Zoho, 

// 👉 Leetcode Version
// ⏲️ Time Complexity  : O(nlogn)
// 🛢️ Space Complexity : O(1) (I am ignoring the space taken by result of size n which we have to return

static bool myFunction(int a, int b) {
    string s1 = to_string(a);
    string s2 = to_string(b);
        
    return (s1+s2) > (s2+s1);
}
string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), myFunction);
          
    if(nums[0] == 0)
        return "0";
    string result = "";
    for(int i:nums)
        result += to_string(i);
    return result;  
}

// // ▶️ GFG Version
// // ⏲️ Time Complexity : O(nlogn)
// // 🛢️ Space Complexity : O(1) (I am ignoring the space taken by result of size n which we have to return

// string printLargest(int n, vector<string> &arr) {
//     auto myComparator = [](string &s1, string &s2) {
//         if(s1+s2 > s2+s1) {
//             return true;
//         }
//         return false;
//     };
            
// 	sort(begin(arr), end(arr), myComparator);
	    
// 	string result = "";
// 	for(string &s : arr) {
// 	    result += s;
// 	}
	    
// 	return result;
// }

int main()
{
    vector<int>  nums = {10,2};
    string ans = largestNumber(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
