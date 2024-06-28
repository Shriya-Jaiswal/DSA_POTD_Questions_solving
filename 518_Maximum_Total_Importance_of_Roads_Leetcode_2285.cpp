#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  HRT ✯  ADOBE

// ▶️ Approach (using degree and assiging value greedily)
// ⏲️ Time Complexity : O(E + nlogn)

long long maximumImportance(int n, vector<vector<int>>& roads) {
    //n = total number of nodes numbered from 0 to n-1

    vector<int> degree(n, 0);

    for(auto &vec : roads) {
        int u = vec[0];
        int v = vec[1];

        degree[u]++;
        degree[v]++;
    }

    sort(begin(degree), end(degree)); //ascedning order

    long long value = 1;
    long long sum   = 0;

    for(int i = 0; i < n; i++) {
        sum += (degree[i] * value);
        value++;
    }

    return sum;
}

int main()
{
    int  n = 5;
    vector<vector<int>> roads = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    long long ans = maximumImportance(n,roads);
    cout << "ans is : " << ans << endl;
    return 0;
}
