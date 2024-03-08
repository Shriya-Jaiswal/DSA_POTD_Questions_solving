#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Zoho

bool allSame(vector<int> &freq){
    int curr = -1;
    for(auto it :  freq){
        if(it==0)continue;
        else if(curr == -1) curr = it;
        else if(curr != it) return false; 
    }
    return true;
}

bool sameFreq(string s){
    int n=s.length();
	vector<int>freq(26,0);
	for(int i=0;i<s.length();i++){
	    freq[s[i]-'a']++;
	}
	if(allSame(freq)){
        return true;
    }
    for(int i=0; i<freq.size(); i++){
        if(freq[i]!=0){
            freq[i]--;
            if(allSame(freq)){
                return true;
            }
            freq[i]++;
        }
    }
    return false;
}

// ⏲️ Expected Time Complexity: O(|s|) 
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    string s = "xyyz";
    bool ans = sameFreq(s);
    cout << "ans is : " << ans << endl;
    return 0;
}
