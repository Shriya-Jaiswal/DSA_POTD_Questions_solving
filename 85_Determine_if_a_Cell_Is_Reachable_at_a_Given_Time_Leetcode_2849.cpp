#include<iostream>
#include<vector>
using namespace std;


// // ▶️ Approach - 1 (Brute Force : Won't work with High Contraints - Infinte Board)

// vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, 1}, {1, -1}, {1, 1}, {-1, -1}};
// bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
//      if(sx < 0 || sy < 0) {
//             return false;
//         }
        
//         if(t == 0) {
//             return sx == fx && sy == fy;
//         }
        
//         for(auto &dir : directions) {
//             int sx_ = sx + dir[0];
//             int sy_ = sy + dir[1];
            
//             if(isReachableAtTime(sx_, sy_, fx, fy, t-1))
//                 return true;
//         }
        
//         return false;
// }


// // ▶️ Approach-2 (Using Maths)
// // ⏲️ Time Complexity : O(1)
bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    int vert_dist = abs(sy-fy);
    int hor_dist  = abs(sx-fx);
        
    if(vert_dist == 0 && hor_dist == 0 && t == 1) {
        return false;
    }
        
    return t >= max(vert_dist, hor_dist);    
}


int main()
{
    int sx = 3, sy = 1, fx = 7, fy = 3, t = 3;
    bool ans = isReachableAtTime(sx,sy,fx,fy,t);
    cout << "ans is : " << ans << endl;

    return 0;
}
