#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Zoho | Flipkart | Amazon | Microsoft | Google | Fab.com | One97 | United Health Group

int celebrity(vector<vector<int> >& mat) {
    int n=mat.size();
    int a=0, b=n-1;
    while(a<b){
        if(mat[a][b]){
            a++;
        }
        else{
            b--;
        }
    }
        
    for(int i=0;i<n;i++){
        if(i==a) continue;
        if(!mat[i][a] || mat[a][i]){
            return -1;
        }
    }
    return a;
}

// ⏲️ Expected Time Complexity: O(n2)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    vector<vector<int>> mat = {{0, 1, 0},
                        {0, 0, 0}, 
                        {0, 1, 0}};
    int ans = celebrity(mat);
    cout << "ans is : " << ans << endl;
    return 0;
}
