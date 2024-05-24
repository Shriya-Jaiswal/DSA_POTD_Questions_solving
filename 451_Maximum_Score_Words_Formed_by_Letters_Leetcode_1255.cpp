#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// ▶️ Ask by :  Google ✯   Amazon ✯  

// ▶️ Using simple backtracking
// ⏲️ Time Complexity : O(2^n) where n is the total number of words
// 🛢️ Space Complexity : O(n)

int n;
int maxScore;

void solve(int i, vector<int>& score, vector<string>& words, int currScore, vector<int>& freq){
          
    maxScore = max(maxScore, currScore);

    if(i >= n)
        return;

    vector<int> tempFreq = freq;

    int j         = 0;
    int tempScore = 0;

    while(j < words[i].length()) {
        char ch = words[i][j];

        tempFreq[ch - 'a']--;
        tempScore += score[ch - 'a'];

        if(tempFreq[ch-'a'] < 0)
            break;

        j++;
    }

    //Take words[i]
    if(j == words[i].length()) { //It means we could form the word words[i]
        solve(i+1, score, words, currScore + tempScore, tempFreq);
    }

    //Not Take words[i]
    solve(i+1, score, words, currScore, freq);
}
int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    vector<int> freq(26, 0);

    for(char &ch : letters){
        freq[ch - 'a']++;
    }
    maxScore = INT_MIN;
    n        = words.size();

    solve(0, score, words, 0, freq);
        
    return maxScore;
}

int main()
{
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    int ans = maxScoreWords(words,letters,score);
    cout << "ans is : " << ans << endl;
    return 0;
}
