#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Atlassian ✯   Amazon ✯   Apple ✯  

// ▶️ Simply Simulation
// ⏲️ T.C : O(n)
// 🛢️ S.C : O(1)

bool lemonadeChange(vector<int>& bills) {
    int five = 0;
    int ten  = 0;


    for(int &bill : bills) {
        if(bill == 5) {
            five++;
        } else if(bill == 10) { // 👉 return 5$ to customer
            if(five > 0) {
                five--;
                ten++;
            } else {
                return false;
            }
        } else if(five > 0 && ten > 0) { // 👉 return 15$ to customer
            five--;
            ten--;
        } else if(five >= 3) { //5, 5, 5
            five -= 3;
        } else {
            return false;
        }
    }

    return true;
}

int main()
{
    vector<int>  bills = {5,5,5,10,20};
    bool ans = lemonadeChange(bills);
    cout << "ans is : " << ans << endl;
    return 0;
}
