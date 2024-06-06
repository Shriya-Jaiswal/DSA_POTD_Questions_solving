#include<iostream>
#include<vector>
#include<map> 
using namespace std;

// ▶️ Ask by :  Google ✯  

// ▶️ Approach (Simply using map)
// ⏲️ Time Complexity  : O(nlogn) + O(n*groupSize)
// 🛢️ Space Complexity  : O(n)

bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();
    if(n % groupSize) {
        return false;
    }
    map<int, int> mp;
    for(int &handNumber : hand) {
        mp[handNumber]++; //O(nlogn)
    }
    while(!mp.empty()) { //O(n*groupSize)
        int curr = mp.begin()->first; //->second : frequency
        for(int i = 0; i < groupSize; i++) {
            if(mp[curr + i] == 0) {
                return false;
            }
            mp[curr+i]--;
            if(mp[curr+i] < 1) {
                mp.erase(curr+i);
            }
        }
    }
    return true;    
}


// ▶️ Approach (Simply using map)
// ⏲️ Time Complexity  : O(nlogn) + O(n*groupSize)
// 🛢️ Space Complexity  : O(n)

// boolean isNStraightHand(int[] hand, int groupSize) {
//     int n = hand.length;

//     if (n % groupSize != 0) {
//         return false;
//     }

//     TreeMap<Integer, Integer> map = new TreeMap<>();
//     for (int card : hand) {
//         map.put(card, map.getOrDefault(card, 0) + 1);
//     }

//     while (!map.isEmpty()) {
//         int curr = map.firstKey();

//         for (int i = 0; i < groupSize; i++) {
//             if (!map.containsKey(curr + i)) {
//                 return false;
//             }

//             map.put(curr + i, map.get(curr + i) - 1);
//             if (map.get(curr + i) == 0) {
//                 map.remove(curr + i);
//             }
//         }
//     }

//     return true;
// }

int main()
{
    vector<int>  hand = {1,2,3,6,2,3,4,7,8}; 
    int groupSize = 3;
    bool ans = isNStraightHand(hand,groupSize);
    cout << "ans is : " << ans << endl;
    return 0;
}
