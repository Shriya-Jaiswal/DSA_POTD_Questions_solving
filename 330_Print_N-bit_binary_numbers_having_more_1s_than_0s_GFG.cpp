#include<iostream>
#include<vector>
using namespace std;

void solve(vector<string>&ans, string curr, int ones, int zeroes, int n){
    if(ones<zeroes) return;   
    if(curr.size()==n){
        ans.push_back(curr);
        return;
    }
    solve(ans, curr+'1', ones+1, zeroes, n);
    solve(ans, curr+'0', ones, zeroes+1, n);
    return;
}

vector<string> NBitBinary(int n){
	vector<string>ans;
	string curr="";
	    
	solve(ans, curr, 0, 0, n);
	    
	return ans;
}

// ⏲️ Expected Time Complexity: O(|2n|)
// 🛢️ Expected Auxiliary Space: O(2n)

int main()
{
    int n = 2;
    vector<string> ans = NBitBinary(n);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
