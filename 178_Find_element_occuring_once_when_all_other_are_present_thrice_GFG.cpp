#include<iostream>
using namespace std;

// ➡️ Ask by : Google

int singleElement(int arr[] ,int N) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
        int setbit = 0;
        for (int j = 0; j < N; j++) {
            if ((arr[j] & (1 << i)) != 0) {
                setbit++;
            }
        }
        if (setbit % 3 == 1) {
            res = res | (1 << i);
        }
    }
    return res;
}

// ⏲️ Expected Time Complexity: O(N).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    int N = 4;
    int arr[] = {1, 10, 1, 1};
    int ans = singleElement(arr,N);
    cout << "ans is : " << ans  << endl;
    return 0;
}
