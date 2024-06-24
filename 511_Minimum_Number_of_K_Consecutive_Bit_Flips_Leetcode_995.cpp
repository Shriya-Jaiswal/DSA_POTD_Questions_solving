#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// ▶️ Ask by :  Google ✯   Akuna Capital ✯  

// // ▶️ Approach-1 (Using auxiliary array to mark Flipped indices)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// int minKBitFlips(vector<int>& nums, int k) {
//     int n = nums.size();

//     int flips = 0;
//     vector<bool> isFlipped(n, false);
//     int flipCountFromPastForCurri = 0;

//     for(int i = 0; i < n; i++) {
//         if(i >= k && isFlipped[i-k] == true){
//             flipCountFromPastForCurri--;                     
//         }
            
//         if(flipCountFromPastForCurri % 2 == nums[i]) {
//             if(i+k > n){
//                 return -1;
//             }
//             flipCountFromPastForCurri++;
//             isFlipped[i] = true;
//             flips++;
//         }
//     }
//     return flips;
// }



// // ▶️ Approach-2 (Using same input to mark Flipped indices - We will be manipulating the input as well)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Spac Complexity : O(1)

// int minKBitFlips(vector<int>& nums, int k) {
//     int n = nums.size();

//     int flips = 0;
        
//     int flipCountFromPastForCurri = 0;

//     for(int i = 0; i < n; i++) {

//         if(i >= k && nums[i-k] == 2) { //Was it flipped
//             flipCountFromPastForCurri--;
//         }
            
//         if(flipCountFromPastForCurri % 2 == nums[i]) {
//             if(i+k > n){
//                 return -1;
//             }
//             flipCountFromPastForCurri++;
//             nums[i] = 2; //Marking as flipped
//             flips++;
//         }
//     }

//     return flips;
// }


// ▶️ Approach-3 (Using deque to mark Flipped indices)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(k)

int minKBitFlips(vector<int>& nums, int k) {
    int n = nums.size();

    int flips = 0;
    deque<int> flipQue;
    int flipCountFromPastForCurri = 0;

    for(int i = 0; i < n; i++) {
        if(i >= k){
            flipCountFromPastForCurri -= flipQue.front();
            flipQue.pop_front();
        }
            
        if(flipCountFromPastForCurri % 2 == nums[i]) {
            if(i+k > n){
                return -1;
            }
            flipCountFromPastForCurri++;
            flipQue.push_back(1);
            flips++;
        } else {
            flipQue.push_back(0);
        }
    }

    return flips;
}

int main()
{
    vector<int>  nums = {0,1,0};
    int k = 1;
    int ans = minKBitFlips(nums,k);
    cout << "ans is : " << ans << endl;
    return 0;
}
