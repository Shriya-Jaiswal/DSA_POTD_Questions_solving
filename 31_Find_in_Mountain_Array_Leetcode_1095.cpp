#include<iostream>
#include<vector>
using namespace std;


class MountainArray {
   public:
     int get(int index);
     int length();
};

int peakIndexInMountainArray(MountainArray &mountainArr){
    int n = mountainArr.length();

    int l = 0;
    int r = n-1;

    while(l<r){
        int mid = l + (r-l)/2;

        if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l;
}

//👉 binary search in assending order 
int binarySearch(MountainArray &mountainArr , int l, int r, int target){
    int mid ;
    while(l <= r){
        mid = l + (r-l)/2;

        if(mountainArr.get(mid) == target){
            return mid;
        }
        else if(mountainArr.get(mid) > target){
            // 👉 left side
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}


int reverseBinarySearch(MountainArray &mountainArr , int l, int r, int target){
    int mid ;
    while(l <= r){
        mid = l + (r-l)/2;

        if(mountainArr.get(mid) == target){
            return mid;
        }
        else if(mountainArr.get(mid) > target){
            // 👉 left side
            l = mid + 1; // 👉 decending order 
        }
        else{
            r = mid -1;
        }
    }
    return -1;
}

int findInMountainArray(int target, MountainArray &mountainArr) {
    int n = mountainArr.length();
    int idx = peakIndexInMountainArray(mountainArr);

    //  0 to idx
    int result_idx = binarySearch(mountainArr,0,idx,target);

    if(result_idx != -1){
        return result_idx;
    }  

    //  idx+1 to n-1
    result_idx = reverseBinarySearch(mountainArr, idx+1, n-1, target);

    return result_idx;
}

int main()
{
    // MountainArray mountainArr[] = (1,2,3,4,5,3,1);
    // int target = 3;

    // int ans = findInMountainArray(target, mountainArr);
    // cout << "ans is : " << ans << endl;

    return 0;
}
