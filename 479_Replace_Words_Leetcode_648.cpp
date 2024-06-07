#include<iostream>
#include<vector>
#include<string>
using namespace std;

// ▶️ Ask by :  Facebook ✯  UBER

// ▶️ Using Trie
// ⏲️ Time Complexity : o(n*l + m*l) , n = number of words in the dictionary, m be the number of words in the sentence, and l be the average length of each word.
// 🛢️ Space Complexity : O(n*l + m*l)

struct trieNode { 
    trieNode *children[26]; 
    bool isEndOfWord; 
};
    
trieNode* getNode() {
    trieNode* newNode = new trieNode();
    newNode->isEndOfWord = false;
        
    for (int i = 0; i < 26; i++) {
		newNode->children[i] = NULL;
	} 
    return newNode;
}
  
trieNode* root;

/** Inserts a word into the trie. */
void insert(string word) {
    trieNode *crawler = root; 
        
    for (int i = 0; i < word.length(); i++) { 
        int index = word[i] - 'a'; 
        if (!crawler->children[index]) 
            crawler->children[index] = getNode();
            
        crawler = crawler->children[index]; 
    }
        
    crawler->isEndOfWord = true; 
}
    
/** Returns if the word is in the trie. */
string search(string word) {
    trieNode *crawler = root; 
        
    for (int i = 0; i < word.length(); i++) { 
        int index = word[i] - 'a'; 
        if (!crawler->children[index]) 
            return word; 
        crawler = crawler->children[index];
        if(crawler->isEndOfWord) {
            return word.substr(0, i+1);
        }
    }
    return word;
}

string replaceWords(vector<string>& dictionary, string sentence) {

    stringstream ss(sentence);
    string word;
    string result;
    root = getNode();
    for (string word : dictionary) {
        insert(word);
    }

    while(getline(ss, word, ' ')) {
        result += search(word) + " ";
    }

    result.pop_back();
    return result;
}


int main()
{
    vector<string>  dictionary = {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    string ans = replaceWords(dictionary,sentence);
    cout << "ans is : " << ans << endl;

    return 0;
}
