#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Uber ✯ MICROSOFT  ⚒️ Hard

// ▶️ Using heap and greedily picking up projects
// ⏲️ Time Complexity : O(nlogn)
// 🛢️ Space Complexity : O(n)

int findMaximizedCapital(int k, int paissa, vector<int>& profits, vector<int>& capital) {
    int n = profits.size();
    vector<pair<int, int>> vec(n);   
    for (int i = 0; i < n; i++) {
        vec[i] = {capital[i], profits[i]};
    }
    sort(vec.begin(), vec.end());
    int i = 0;
    priority_queue<int> pq;

    while (k--) {
        while (i < n && vec[i].first <= paissa) {
            pq.push(vec[i].second);
            i++;
        }
        if (pq.empty())
            break;
        paissa += pq.top();
        pq.pop();
    }
    return paissa;
}

int main()
{
    int k = 2;
    int w = 0;
    vector<int> profits = {1,2,3};
    vector<int> capital = {0,1,1};
    int ans = findMaximizedCapital(k,w,profits,capital);
    cout << "ans is : " << ans << endl;
    return 0;
}
