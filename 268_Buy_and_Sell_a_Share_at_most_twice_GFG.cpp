#include<iostream>
#include<vector>
using namespace std;

// ▶️ Amazon | Facebook

int maxProfit(vector<int> &price){
    int n = price.size();
    vector<int> temp(n, 0);
    int maxi = price[n - 1];
    for (int i = n - 2; i >= 0; i--){
        maxi = max(maxi, price[i]);
        temp[i] = max(temp[i + 1], maxi - price[i]);
    }
    int mini = price[0];
    for (int i = 1; i < n; i++){
        mini = min(price[i], mini);
        temp[i] = max(temp[i - 1], price[i] - mini + temp[i]);
    }
    return temp[n - 1];
}

// ⏲️ Expected Time Complexity: O(n)
// 🛢️ Expected Space Complexity: O(n)

int main()
{
    vector<int> prices = {10,22,5,75,65,80};
    int ans = maxProfit(prices);
    cout << "ans is : " << ans << endl;
    return 0;
}
