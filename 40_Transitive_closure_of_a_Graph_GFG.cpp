#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
{
    for(int k=0; k<N; k++){
        for(int i=0; i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j){
                    graph[i][j]=1;
                }
                if(graph[i][j]==0){
                    if(graph[i][k]==1 && graph[k][j]==1){
                        graph[i][j]=1;
                    }
                }
            }
        }
    }
    return graph;
}

// ⏲️ Expected Time Complexity: O(N3)
// 🛢️ Expected Auxiliary Space: O(N2)

int main()
{
    int N = 4;
     vector<vector<int>> graph {{1, 1, 0, 1}, 
                                {0, 1, 1, 0}, 
                                {0, 0, 1, 1}, 
                                {0, 0, 0, 1}};
    
    vector<vector<int>> ans = transitiveClosure(N,graph);
    for(int i=0; i<ans.size();i++){
        for(int j=0; j<ans[i].size();j++){
            cout<< ans[i][j] << " ";
        }
        cout<< endl;
    }
    return 0;
}
