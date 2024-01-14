#include<iostream>
#include<vector>
#include<set>
using namespace std;

// ▶️ Ask by : Microsoft

vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
{ 
    vector<int> ans;
    set<vector<int>> st;
    for(int i=0;i<M;i++){
        if(st.find(matrix[i])!=st.end()){
            ans.push_back(i);
        }else{
            st.insert(matrix[i]);
        }
    }
    return ans;    
} 

// ⏲️ Expected Time Complexity: O(R * C)
// 🛢️ Expected Auxiliary Space: O(R * C)

int main()
{
    int R = 4, C = 3;
    vector<vector<int>> matrix = {{ 1, 0, 0},
                                  { 1, 0, 0},
                                  { 0, 0, 0},
                                  { 0, 0, 0}};

    vector<int> ans = repeatedRows(matrix,R,C);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    

    return 0;
}
