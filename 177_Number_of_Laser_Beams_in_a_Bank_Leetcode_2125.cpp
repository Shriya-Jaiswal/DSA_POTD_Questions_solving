#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :   ✯  Amazon

// ◀️ Approach (Simple iterate and count)
// ⏲️ Time Complexity  : O(m*n) - Total number of characters in all string
// 🛢️ Space Complexity : O(1)

int numberOfBeams(vector<string>& bank) {
    int n = bank.size(); 
    int prevDeviceCount = 0;
    int result    = 0;
    for(int i = 0; i<n; i++) { 
        int currDeviceCount = 0;
        for(char &ch : bank[i]) {
            if(ch == '1') {
                currDeviceCount++;
            }
        }   
        result += (prevDeviceCount * currDeviceCount);  
        prevDeviceCount = currDeviceCount == 0 ? prevDeviceCount : currDeviceCount;       
    }
    return result;
}


int main()
{
    vector<string>  bank = {"000","111","000"};
    int ans = numberOfBeams(bank);
    cout << "ans is : " << ans << endl;
    return 0;
}
