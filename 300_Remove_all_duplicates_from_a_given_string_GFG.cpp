#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Amazon | Microsoft | Adobe

string removeDuplicates(string str) {  
	vector<int>vis(256,0);
	string ans="";
	for(int i=0;i<str.length();i++){
	    if(vis[str[i]]==1){
	        continue;
	    }
	    else{
	        vis[str[i]]=1;
	        ans=ans+str[i];
	    }
	}
	return ans;
}

// ⏲️ Expected Time Complexity: O(N)
// 🛢️ Expected Auxiliary Space: O(N)

int main()
{
    string str = "geEksforGEeks";
    string ans = removeDuplicates(str);
    cout << "ans is : " << ans << endl;
    return 0;
}
