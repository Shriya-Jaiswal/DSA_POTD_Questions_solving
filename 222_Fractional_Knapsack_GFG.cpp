#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by : Microsoft

struct Item{
    int value;
    int weight;
};

static bool comp(Item &a, Item &b){
    return 1.0*a.value/a.weight > 1.0*b.value/b.weight;
}
    
//Function to get the maximum total value in the knapsack.
double fractionalKnapsack(int W, Item arr[], int n)
{
    double profit = 0;
    sort(arr, arr + n, comp);
    for(int i = 0; i < n and W != 0; i++){
        profit += arr[i].value*(1.0*min(arr[i].weight, W)/arr[i].weight);
        W -= min(arr[i].weight, W);
    }
    return profit;
}

// ⏲️ Expected Time Complexity : O(NlogN)
// 🛢️ Expected Auxilliary Space: O(1)


int main()
{
    int N = 3;
    int W = 50;
    Item value[] = {60,100,120};
    double ans = fractionalKnapsack(W,value,N);
    cout << "ans is : " << ans << endl;
    return 0;
}

