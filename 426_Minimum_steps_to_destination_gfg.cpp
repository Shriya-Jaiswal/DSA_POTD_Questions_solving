#include <iostream>
#include <vector>
using namespace std;

// ▶️ Ask by : Flipkart | Amazon | InMobi

int minSteps(int d) {
    d=abs(d);   
    int sum=0, steps=0;
    while(sum<d || abs(sum-d)%2!=0){
        steps++;
        sum+=steps;
    }    
    return steps;
}

// ⏲️ Expected Time Complexity: O(sqrt(d))
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    int  d = 2;
    int ans = minSteps(d);
    cout << "ans is : " << ans << endl;
    return 0;
}
