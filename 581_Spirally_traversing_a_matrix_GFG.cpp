#include<iostream>
#include <vector>
using namespace std;

// ▶️ Ask by : Paytm | Flipkart | Morgan Stanley | Microsoft | OYO Rooms | Snapdeal | D-E-Shaw | MakeMyTrip | Oracle | MAQ Software | Adobe | nearbuy | Nagarro | BrowserStack | Salesforce

vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
    int n = matrix.size(),m=matrix[0].size(),s=n*m;
    //a -> row start, b -> col start, c -> row end, d -> col end
    int a=0,b=0,c=n-1,d=m-1;
    vector<int> ans;
    while(ans.size()<s){
        for(int i=b;i<=d && ans.size()<s;i++)ans.push_back(matrix[a][i]);
        a++;
        for(int i=a;i<=c && ans.size()<s;i++)ans.push_back(matrix[i][d]);
        d--;
        for(int i=d;i>=b && ans.size()<s;i--)ans.push_back(matrix[c][i]);
        c--;
        for(int i=c;i>=a && ans.size()<s;i--)ans.push_back(matrix[i][b]);
        b++;
    }
    return ans;
}

// ⏲️ Expected Time Complexity: O(n2)
// 🛢️ Expected Auxiliary Space: O(n2)


int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                    {5, 6, 7, 8},
                                    {9, 10, 11, 12},
                                    {13, 14, 15,16}};
    vector<int> ans = spirallyTraverse(matrix);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
