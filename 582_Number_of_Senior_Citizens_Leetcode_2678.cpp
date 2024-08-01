#include<iostream>
#include<vector>
using namespace std;

// ⏲️ Time Complexity : O(n) where n = length of details
// 🛢️ Space Complexity : O(1)

int countSeniors(vector<string>& details) {
    int count = 0;
    for(string &detail : details) {
        int secondDigit = detail[11] - '0';
        int firstDigit  = detail[12] - '0';
        int age         = secondDigit*10 + firstDigit;
        if(age > 60)
            count++;
    }
    return count;
}

int main()
{
    vector<string>  details = {"7868190130M7522","5303914400F9211","9273338290F4010"};
    int ans = countSeniors(details);
    cout << "ans is : " << ans << endl;
    return 0;
}
