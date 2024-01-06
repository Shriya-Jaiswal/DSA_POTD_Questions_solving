#include<iostream>
using namespace std;

int sumOfPowers(int a, int b){
	long sum = 0;
    for (int i = a; i <= b; i++) {
        int x = i;
        for (int j = 2; j * j <= x; j++) {
            while (x % j == 0) {
                sum++;
                   x = x / j;
            }
        }
        if (x >= 2) sum++;
    }
    return sum;
}

// ⏲️ Expected Time Complexity: O( b*log(b) )
// 🛢️ Expected Space Complexity: O( b*log(b) )

int main()
{
    int a = 9;
    int b = 12;
    int ans = sumOfPowers(a,b);
    cout << "ans is : " << ans << endl;
    return 0;
}
