#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Snapdeal | Adobe | Zomato


int func(int p[], int q[], int r[]) {
    if (q[0] <= max(p[0], r[0]) && q[0] >= min(p[0], r[0]) && q[1] <= max(p[1], r[1]) && q[1] >= min(p[1], r[1])){
        return 1;
    }
    return false;
}

int direction(int p[], int q[], int r[]) {
    long long val =
        1LL * (q[1] - p[1]) * (r[0] - q[0]) - 1LL * (q[0] - p[0]) * (r[1] - q[1]);

    if (val == 0)
        return 0; 
        
    if(val>0){
        return 1;
    }
    else return -1;
}

string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
        
    int o1 = direction(p1, q1, p2);
    int o2 = direction(p1, q1, q2);
    int o3 = direction(p2, q2, p1);
    int o4 = direction(p2, q2, q1);
        
    if (o1 != o2 && o3 != o4){
        return "true";
    }
    if (o1 == 0 && func(p1, p2, q1)){
        return "true";
    }
    if (o2 == 0 && func(p1, q2, q1)){
        return "true";
    }
    if (o3 == 0 && func(p2, p1, q2)){
        return "true";
    }
    if (o4 == 0 && func(p2, q1, q2)){
        return "true";
    }
    return "false";
}

// ⏲️ Expected Time Complexity: O(1)
// 🛢️ Expected Auxillary Space: O(1)

int main()
{
    int p1[] = {1,1};
    int q1[] = {10,1};
    int p2[] = {1,2};
    int q2[] = {10,2};
    string ans = doIntersect(p1,q1,p2,q2);
    cout << "ans is : " << ans << endl;
    return 0;
}
