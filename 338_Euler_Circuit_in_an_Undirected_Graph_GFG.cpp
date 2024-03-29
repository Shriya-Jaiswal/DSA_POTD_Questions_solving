#include<iostream>
#include<vector>
using namespace std;

bool isEularCircuitExist(int v, vector<int>adj[]){
	for(int i=0;i<v;i++){
	    if(int(adj[i].size())%2==1) return false;
	} 
	return true;
}

// ⏲️ Expected Time Complexity: O(v + e)
// 🛢️ Expected Space Complexity: O(v)

int main()
{
    int v = 4 ;
    vector<int>edges[] = {{0, 1}, 
                          {0, 2}, 
                          {1, 3}, 
                          {2, 3}};

    bool ans = isEularCircuitExist(v,edges);
    cout << "ans is :" << ans << endl;

    return 0;
}
