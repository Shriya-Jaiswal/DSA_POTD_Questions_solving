#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Bloomberg ✯  

typedef long long ll;
bool judgeSquareSum(int c) {
    ll low=0, high = sqrt(c);
    while(low<=high)
    {
        ll a=low*low,b=high*high;
        if(a+b==c)
            return true;
        if(a+b>c)
        {
            high--;
        }
        else low++;
    }
    return false;
}

int main()
{
    int c = 5;
    bool ans = judgeSquareSum(c);
    cout << "ans is : " << ans << endl; 
    return 0;
}
