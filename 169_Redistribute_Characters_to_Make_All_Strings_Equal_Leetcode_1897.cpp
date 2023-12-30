#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


// ▶️ Ask by :  Moengage ✯  


// // ▶️ Approach-1 (Using hashmap to store frequency)
// // ⏲️ T.C : O(n)
// // 🛢️ S.C : O(n)

// bool makeEqual(vector<string>& words) {
//         int n = words.size();
//         unordered_map<char, int> count;

//         for (string& word : words) {
//             for (char &ch : word) {
//                 count[ch]++;
//             }
//         }

//         for (auto &it : count) {
//             if (it.second % n != 0) {
//                 return false;
//             }
//         }

//         return true;
//     }


// // ▶️ Approach-2 (Using array as hashmap for storing frequency)
// // ⏲️ T.C : O(n)
// // 🛢️ S.C : O(26)

//  bool makeEqual(vector<string>& words) {
//         int n = words.size();
        
//         int count[26] = {0};
        
//         for(string &word : words) {
            
//             for(char &ch : word) {
//                 count[ch-'a']++;
//             }
            
//         }
        
//         for(int i = 0; i < 26; i++) {
//             if(count[i]%n != 0) {
//                 return false;
//             }
//         }
        
//         return true;
        
    // }


// ◀️ Approach-3 (Using STL+lambda and array as hashmap)
// ⏲️ T.C : O(n)
// 🛢️ S.C : O(1)

    bool makeEqual(vector<string>& words) {
       int n = words.size();
        int count[26] = {0};
        
        for (string &word : words) {
            for (char &ch : word) {
                ++count[ch - 'a'];
            }
        }
        
        auto lambda = [&](int c) {
                   return c % n == 0;
        };
        
        return all_of(begin(count), end(count), lambda);
        
        
        /*  Or, you can also write like this
            return all_of(begin(count), end(count), [&](int c) {
                   return c % n == 0;
            });
            
        */
         
}

int main()
{
    vector<string> words = {"abc","aabc","bc"};
    bool ans = makeEqual(words);
    cout << "ans is : "<< ans << endl;
    return 0;
}
