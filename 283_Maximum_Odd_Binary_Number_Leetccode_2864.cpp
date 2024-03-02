#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// // ▶️ Approach-1 (greedily assigning 1s)
// // ⏲️ T.C : O(n)
// // 🛢️ S.C : O(n) for result

// string maximumOddBinaryNumber(string s) {
//     int n = s.length();
//     string result = string(n, '0');
//     int i = 0;
//     for(char &ch : s) {
//         if(ch == '1') { 
//             if(result[n-1] == '1') {
//                 result[i] = '1';
//                 i++;
//             } else {
//                 result[n-1] = '1';
//             }
//         }
//     }
//     return result;
// }

// ▶️ Approach-2 (Count 1s and assign)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(n) for result


 string maximumOddBinaryNumber(string s) {
        int n = s.length();
        
        string result = string(n, '0');
        
        int count_1 = count(s.begin(), s.end(), '1');
        
        int j = 0;
        
        while(count_1 > 1) {
            result[j] = '1';
            j++;
            
            count_1--;
        }
        
        result[n-1] = '1';
        return result;
}

int main()
{
    string s = "010";
    string ans = maximumOddBinaryNumber(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
