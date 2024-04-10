#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// // ▶️ Ask by :  Adobe ✯  

// // ▶️ Approach-1 (Simulation) 
// // ⏲️ Time Complexity : O(nlogn)
// // 🛢️ Space Complexity : O(1)

// vector<int> deckRevealedIncreasing(vector<int>& deck) {
//     int n = deck.size();
//     vector<int> result(n, 0);
//     bool skip = false;
//     int i = 0; //deck
//     int j = 0; //result
//     sort(begin(deck), end(deck));
//     while(i < n) {
//         if(result[j] == 0) { //khali hai   
//             if(skip == false) {
//                 result[j] = deck[i];
//                 i++;
//             }     
//             skip = !skip; //alternate     
//         }     
//         j = (j+1)%n;   
//     }
//     return result;
// }


// ▶️ Approach-2 (Simulation using Queue) 
// ⏲️ Time Complexity : O(nlogn)
// 🛢️ Space Complexity : O(n)

vector<int> deckRevealedIncreasing(vector<int>& deck) {
    int n = deck.size();
    queue<int> que;
    vector<int> result(n);   
    for(int i = 0; i < n; i++) {
        que.push(i);
    }
    sort(begin(deck), end(deck));
    for(int i = 0; i < n; i++) {
        int idx = que.front();
        que.pop();
        result[idx] = deck[i]; 
        if(!que.empty()) {
            que.push(que.front());
            que.pop();
        }       
    }    
    return result;
}

int main(){
    vector<int> deck = {17,13,11,2,3,5,7};
    vector<int> ans = deckRevealedIncreasing(deck);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
