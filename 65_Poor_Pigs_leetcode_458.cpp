#include<iostream>
#include<math.h>
using namespace std;

// ▶️ Hard ---> Aptitude round Question

int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    // 👉 (T+1)^pigs = buckets
    // 👉 pigs = log(buckets)/log(T+1)


    return ceil(log2(buckets)/log2(minutesToTest/minutesToDie + 1));
}

int main()
{
    int buckets = 4, minutesToDie = 15, minutesToTest = 15;
    int ans = poorPigs(buckets,minutesToDie,minutesToTest);
    cout<< "ans is : " << ans << endl;
    return 0;
}
