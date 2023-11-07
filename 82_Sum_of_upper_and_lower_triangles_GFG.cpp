#include<iostream>
#include<vector>
using namespace std;

vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
{
    vector<int> ans;
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                sum1+=(matrix[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                sum2+=(matrix[i][j]);
            }
        }

        ans.push_back(sum1);
        ans.push_back(sum2);
        return ans;
}

// ⏲️ Timecomplexity : Expected Time Complexity: O(N * N)
// 🛢️ space complexity : Expected Auxiliary Space: O(1)

int main()
{
   int N = 3 ;
    vector<vector<int>> mat = {{6, 5, 4},
                               {1, 2, 5},
                               {7, 9, 7}};
    vector<int> ans = sumTriangles(mat,N);
    for(int i=0; i<ans[i]; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
