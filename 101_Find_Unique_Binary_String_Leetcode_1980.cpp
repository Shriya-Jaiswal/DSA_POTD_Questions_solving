#include<iostream>
#include<vector>
#include<unordered_set>
#include<bitset>
using namespace std;

// ▶️ Ask by ---> AMAZON | META | GOOGLE |

// // ▶️ Approach-1 (Using simple conversion)
// // ⏲️ Time Complexity : O(n^2) - Iterating on each string and converting each character to integer
// // 🛢️ Space Complexity : O(n) - Using set

// string findDifferentBinaryString(vector<string>& nums) {
//     unordered_set<int> st;   
//     for(string &num : nums) {
//         st.insert(stoi(num, 0, 2)); // 👉 convert string to number but here 2 represent binary string means ye binary number ko string me convert kr dega
//     }
//     int n = nums.size();
//     string result= "";
//     for(int number = 0; number <= 65536; number++) {
//         if(st.find(number) == st.end()) {
//             result = bitset<16>(number).to_string(); // 👉 set the bitset of 16 length
//             break;
//         }
//     }
//     return result.substr(16-n);   
// }

// // ▶️ Approach-2 (Improving above code)
// // 👉 We no need to check from 0 to 65536. Only need to check from 0 to n
// // ⏲️ Time Complexity : O(n^2) - Iterating on each string and converting each character to integer
// // 🛢️ Space Complexity : O(n) - Using set

//  string findDifferentBinaryString(vector<string>& nums) {
//     unordered_set<int> st;   
//     for(string &num : nums) {
//         st.insert(stoi(num, 0, 2));
//     }
//     int n = nums.size();
//     string result= "";
//     for(int number = 0; number <= n; number++) {
//         if(st.find(number) == st.end()) {
//             result = bitset<16>(number).to_string();
//             break;
//         }
//     }
//     return result.substr(16-n);    
// }


// ▶️ Approach-3 (By discarding matching characters in each position)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)
string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size(); 
    string result;
    for(int i = 0; i<n; i++) {
        char ch = nums[i][i];  
        result += (ch == '0') ? "1" : "0"; // 👉 discarding nums[i]
    }
    return result;
}

int main()
{
    vector<string> nums {"01","10"};
    string ans = findDifferentBinaryString(nums);
    cout << "ans is : " << ans << endl;
    return 0;
}
