#include<iostream>

#include<vector>
using namespace std;

// ▶️ Ask by :  Google ✯   Facebook ✯  

// ▶️ Approach - Using TRIE 
// ⏲️ Time Complexity : O(n*l), n = number of words, l = average length of each word
// 🛢️ Space Complexity : O(n*l), need to store all characters of words

struct trieNode {
    int countP = 0;
    trieNode* children[26];
};

class Solution {
public:

    trieNode* getTrieNode() {
        trieNode* newNode = new trieNode();
        for(int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }
        newNode->countP = 0;
        return newNode;
    }

    void insert(string& word, trieNode* root) {
        trieNode* crawl = root;

        for(char &ch : word) {
            int idx = ch - 'a';

            if(!crawl->children[idx]) {
                crawl->children[idx] = getTrieNode();
            }

            crawl->children[idx]->countP += 1;
            crawl = crawl->children[idx];
        }
    }

    int getScore(string& word, trieNode* root) {
        trieNode* crawl = root; //"abc"
        int score = 0;

        for(char &ch : word) {
            int idx = ch - 'a';
            score += crawl->children[idx]->countP;

            crawl = crawl->children[idx]; // now i am at "b" wala node
        }

        return score;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();

        trieNode* root = getTrieNode();
        for(string &word : words) {
            insert(word, root);
        }

        vector<int> result(n);
        //result[i] = sum of scores of prefixes of words[i]
        for(int i = 0; i < n; i++) {
            result[i] = getScore(words[i], root);
        }

        return result;
    }
};

int main()
{
    Solution S;
    vector<string> words = {"abc","ab","bc","b"};
    vector<int> ans = S.sumPrefixScores(words);
    for(int i = 0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
