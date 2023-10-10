#include<iostream>
#include<vector>
using namespace std;


int firstPosition(vector<int>&nums, int target){
    int mid;
    int left = 0;
    int right = nums.size()-1;
    int position = -1;

    while(left <= right){
        mid = (left + right)/2;
        if(nums[mid] == target){
            position = mid;
            right = mid -1;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid -1;
        }
    }
    return position;
}

int lastPosition(vector<int>&nums, int target){
    int mid;
    int left = 0;
    int right = nums.size()-1;
    int position = -1;

    while(left <= right){
        mid = (left + right)/2;
        if(nums[mid] == target){
            position = mid;
            left = mid + 1;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid -1;
        }
    }
    return position;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result;
    int firstIndex = firstPosition(nums,target);
    int lastIndex = lastPosition(nums,target);

    result.push_back(firstIndex);
    result.push_back(lastIndex);
    return result;
}

int main()
{
    
    vector<int> nums {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = searchRange(nums,target);
    for(int i = 0; i<ans.size(); i++){
        cout<< ans[i] << " ";
    }
    cout<< endl;
    return 0;
}
