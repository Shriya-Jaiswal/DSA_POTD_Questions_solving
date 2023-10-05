#include<iostream>
#include<vector>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    if(nums.size() < 2){
        return nums;
    }        

    int potential_1 = nums[0];
    int potential_2 = nums[0];

    int count1 = 1;
    int count2 = 0;

    for(int i = 1; i < nums.size(); i++){
        if(nums[i] == potential_1){
            count1++;
        }
        else if(nums[i] == potential_2){
            count2++;
        }
        else{
            if(count1 == 0){
                potential_1 = nums[i];
                count1++;
            }
            else if(count2 == 0){
                potential_2 = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
    }
    count1 = 0; 
    count2 = 0;
    for(int i : nums){
        if(i == potential_1){
            count1++;
        }
        else if(i == potential_2){
            count2++;
        }
    }

    vector<int> ans;
    if(count1 > nums.size()/3){
        ans.push_back(potential_1);
    }
    if(count2 > nums.size() / 3){
        ans.push_back(potential_2);
    }
    return ans;
}

// ⏲️ Time complexity ---> O() --> 
// 🛢️ space complexity ---> O()


int main()
{
    vector<int> nums {3,2,3};
    vector<int>ans = majorityElement(nums);
    for(int i =0; i<ans.size(); i++){
        cout<< ans[i] << " ";
    }
    cout<< endl;
    return 0;
}
