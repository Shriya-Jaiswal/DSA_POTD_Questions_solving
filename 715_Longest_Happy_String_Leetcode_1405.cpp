#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// ▶️ Ask by :  Tiktok ✯   Amazon ✯   Microsoft ✯   DRW ✯   Wayfair ✯  

// ▶️ Approach (simple thought process - heap)
// ⏲️ Time Complexity : O(a+b+c)
// 🛢️ Space Complexity : O(1)

typedef pair<int, char> P;
string longestDiverseString(int a, int b, int c) {
    priority_queue<P, vector<P>> pq; //max-heap

    if(a > 0) {
        pq.push({a, 'a'});
    }
    if(b > 0) {
        pq.push({b, 'b'});
    }
    if(c > 0) {
        pq.push({c, 'c'});
    }

    string result = "";

    while(!pq.empty()) {
        int currCount = pq.top().first;
        int currChar = pq.top().second;
        pq.pop();

        if(result.length() >= 2 && result[result.length()-1] == currChar && result[result.length()-2] == currChar) {
            //we can't use currChar. Check for next largest freqency char
            if(pq.empty()) {
                break;
            }

            int nextCount = pq.top().first;
            int nextChar = pq.top().second;
            pq.pop();

            result.push_back(nextChar);
            nextCount--;
            if(nextCount > 0) {
                pq.push({nextCount, nextChar});
            }
        } else {
            currCount--;
            result.push_back(currChar);
        }

        if(currCount > 0) {
            pq.push({currCount, currChar});
        }
    }

    return result;
}

int main()
{
    int a = 1, b = 1, c = 7;
    string ans = longestDiverseString(a,b,c);
    cout << "ans is : " << ans << endl;
    return 0;
}
