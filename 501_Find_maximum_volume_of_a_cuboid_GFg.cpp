#include<iostream>
#include<math.h>
using namespace std;

double maxVolume(double perimeter, double area) {
    double ans =
        (pow((perimeter - (sqrt(pow(perimeter, 2) - (24 * area)))) / 12, 2) *
            ((perimeter / 4) -
            (2 * ((perimeter - (sqrt(pow(perimeter, 2) - (24 * area)))) / 12))));

    return ans;
}

// ⏲️ Expected Time Complexity: O(1)
// 🛢️ Expected Auxiliary Space: O(1)

int main()
{
    double perimeter = 22;
    double area = 15;
    double ans = maxVolume(perimeter,area);
    cout << "ans is : " << ans << endl;
    return 0;
}
