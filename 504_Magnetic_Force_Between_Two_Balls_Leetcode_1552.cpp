#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Roblox ✯  

// ▶️ Approach-1 (Using Binary Search on Answer)
// ⏲️ Time Complexity : O(nlogn + n*log(max_force_diff))
// 🛢️ Space Complexity : O(1)


bool possibleToPlace(int force, vector<int>& position, int m) {
    int prev       = position[0];
    int countBalls = 1;
    for(int i = 1; i < position.size(); i++) {
        int curr = position[i];
        if(curr - prev >= force) {
            countBalls++;
            prev = curr;
        }
        if(countBalls == m)
            break;
    }
    return countBalls == m;
}

int maxDistance(vector<int>& position, int m) {
    int n = position.size();
    sort(begin(position), end(position));
    int minForce = 1;
    int maxForce = position[n-1] - position[0]; // 👉 better value (comment me batao)
    int result = 0;
    while(minForce <= maxForce) {
        int midForce = minForce + (maxForce - minForce)/2;
        if(possibleToPlace(midForce, position, m)) {
            result = midForce;
            minForce = midForce+1;
        } else {
            maxForce = midForce-1;
        }
    }
    return result;
}


int main()
{
    vector<int> position = {1,2,3,4,7};
    int m = 3;
    int ans = maxDistance(position,m);
    cout << "ans is : " << ans << endl;
    return 0;
}
