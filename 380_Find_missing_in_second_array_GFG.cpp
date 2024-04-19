#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// ▶️ Ask by : Zoho | Accolite | Microsoft | Snapdeal

vector<int> findMissing(int a[], int b[], int n, int m) {
	unordered_set<int>st;
	for(int i=0;i<m;i++){
	    st.insert(b[i]);
	} 
	vector<int>ans;
	for(int i=0;i<n;i++){
	    if(st.find(a[i])==st.end()){
	        ans.push_back(a[i]);
	    }
	}
	return ans;
} 

// ⏲️ Expected Time Complexity: O(n+m).
// 🛢️ Expected Auxiliary Space: O(m).

int main()
{
    int n = 6;
    int m = 5;
    int a[] = {1, 2, 3, 4, 5, 10};
    int b[] = {2, 3, 1, 0, 5};
    vector<int> ans = findMissing(a,b,n,m);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
