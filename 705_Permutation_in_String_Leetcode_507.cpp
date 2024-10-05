#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// // ▶️ Ask by :  Microsoft ✯   Apple ✯   Yandex ✯   Oracle ✯   Amazon ✯   Google   Bloomberg   ByteDance  

// // ▶️ Approach-1 (Brute Force) - TLE
// // ⏲️ Time Complexity : O(n! * m)
// // 🛢️ Space Complexity : O(n)


// int n;
// bool result;
// void solve(int idx, string& s1, string& s2) {
//     if (idx == n) {
//         if (s2.find(s1) != string::npos) {
//             result = true;
//         }
//         return;
//     }

//     for (int i = idx; i < n; i++) {
//         swap(s1[i], s1[idx]);
            
//         solve(idx + 1, s1, s2);

//         swap(s1[i], s1[idx]);

//         // 👉 Early exit if a permutation has been found in s2
//         if (result == true) 
//             return;
//     }
// }

// bool checkInclusion(string s1, string s2) {
//     n = s1.length();
//     result = false;  // 👉 Reset result for each call
//     solve(0, s1, s2);
//     return result;  // 👉 Return whether a permutation of s1 is found in s2
// }


// // ▶️ Approach-2 (Using Sorting and Comparing) - ACCEPTED
// // ⏲️ Time Complexity : O((m-n) * nlogn)
// // 🛢️ Space Complexity : O(n)

// bool checkInclusion(string s1, string s2) {
//     int n = s1.length();
//     int m = s2.length();

//     // 👉 If s1 is longer than s2, it cannot be a substring
//     if (n > m) return false;

//     // 👉 Sort the string s1
//     string sorted_s1 = s1;
//     sort(sorted_s1.begin(), sorted_s1.end());

//     // 👉 Iterate over each substring of s2 of length equal to s1
//     for (int i = 0; i <= m - n; i++) {
//             // 👉 Extract a substring of length n from s2 starting at index i
//         string temp = s2.substr(i, n);

//         // 👉 Sort the substring
//         sort(temp.begin(), temp.end());

//         // 👉 If the sorted substring matches the sorted s1, return true
//         if (temp == sorted_s1) return true;
//     }

//     // 👉 No permutation found in s2
//     return false;
// }


// ▶️ Approach-3 (Sliding Window) - ACCEPTED
// ⏲️ Time Complexity : O(m+n)
// 🛢️ Space Complexity : O(26)

bool checkInclusion(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    // 👉 If s1 is larger than s2, no permutation can exist
    if (n > m) return false;

    // 👉 Frequency vectors for s1 and the current window in s2
    vector<int> s1_freq(26, 0);
    vector<int> s2_freq(26, 0);

    // 👉 Fill frequency of characters in s1
    for (int i = 0; i < n; i++) {
        s1_freq[s1[i] - 'a']++;
    }

    // 👉 Slide the window over s2
    int i = 0; // 👉 left index of the sliding window
    int j = 0; // 👉 right index of the sliding window
    while (j < m) {
        // 👉 Include a new character from the right end of the window
        s2_freq[s2[j] - 'a']++;

        // 👉 Check if the current window size matches the size of s1
        if (j - i + 1 > n) {
            // 👉 If we have passed the size of s1, we need to remove the leftmost character
            s2_freq[s2[i] - 'a']--;
            i++;
        }

        // 👉 Check if the current window's frequency matches s1's frequency
        if (s1_freq == s2_freq) {
            return true;
        }
        j++;
    }

    // 👉 No matching window found
    return false;
}


int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool ans = checkInclusion(s1,s2);
    cout << "ans is : " << ans << endl;
    return 0;
}
