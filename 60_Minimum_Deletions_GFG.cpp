#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int minimumNumberOfDeletions(string S) { 
       int n = S.length();
        int arr[n + 1][n + 1];
        string s = S;
        reverse(s.begin(), s.end());

        for (int i = n; i >= 0; i--) {
            for (int j = n; j >= 0; j--) {
                if (i == n || j == n)
                    arr[i][j] = 0;
                else if (S[i] == s[j])
                    arr[i][j] = 1 + arr[i + 1][j + 1];
                else
                    arr[i][j] = max(arr[i][j + 1], arr[i + 1][j]);
            }
        }

        return n - arr[0][0];
    } 


// ⏲️ Time Complexity :  Expected Time Complexity: O(|S|2)
// 🛢️ space complexity : Expected Auxiliary Space: O(|S|2)


int main()
{
    string S = "aebcbda";
    int ans = minimumNumberOfDeletions(S);
    cout << "ans is : " << ans << endl;
    return 0;
}


