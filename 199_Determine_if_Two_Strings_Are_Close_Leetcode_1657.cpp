#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Facebook ✯   Google ✯   Postmates ✯  

// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(26) ~ O(1)

bool closeStrings(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
        
    if(m != n)
        return false;
        
    vector<int> freq1(26);
    vector<int> freq2(26);
        
    for(int i = 0; i<m; i++) {
        char ch1 = word1[i];
        char ch2 = word2[i];
            
        int idx1 = ch1-'a';
        int idx2 = ch2-'a';
        
        freq1[idx1]++;
        freq2[idx2]++;
            
    }

    //1st point - jo char word1 me hai, wo char word2 me bhi hona chaie
    for(int i = 0; i<26; i++) {
        if(freq1[i] != 0 && freq2[i] != 0) continue;
            
        if(freq1[i] == 0 && freq2[i] == 0) continue;
            
        return false;
    }
        
    //2nd point = match freq
    sort(begin(freq1), end(freq1));
    sort(begin(freq2), end(freq2));
        
    return freq1 == freq2;
}

int main()
{
    string word1 = "abc";
    string word2 = "bca";
    bool ans = closeStrings(word1,word2);
    cout << "ans is : " << ans << endl;
    return 0;
}
