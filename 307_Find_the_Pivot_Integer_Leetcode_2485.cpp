#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// // ▶️ Ask by : Apple

// // ▶️ Approach-1 (Using Brute Force)
// // ⏲️ Time Complexity : O(n^2)
// // 🛢️ Space Complexity : O(1)

// int pivotInteger(int n) {
//     if(n == 1)
//         return 1;
        
//     for(int pivot = 1; pivot <= n; pivot++) {
            
//         int leftSum  = 0;
//         int rightSum = 0;
            
//         for(int j = 1; j <= pivot; j++) {
//             leftSum += j;
//         }
            
//         for(int j = pivot; j <= n; j++) {
//             rightSum += j;
//         }
        
//         if(leftSum == rightSum) {
//             return pivot;
//         } 
//     }
//     return -1;
// }



// // ▶️ Approach-2 (Optimising above using Maths)

// int pivotInteger(int n) {
//     if(n == 1)
//         return 1;
        
//     int totalSum = n * (n+1)/2;
        
//     for(int pivot = 1; pivot <= n; pivot++) {
            
//         int leftSum  = pivot * (pivot+1)/2;
            
//         int rightSum = totalSum - leftSum + pivot;
            
//         if(leftSum == rightSum)
//             return pivot;
            
//     }
//     return -1;
// }


// // ▶️ Approach-3 (Using two pointer)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(1)

// int pivotInteger(int n) {
//     if(n == 1)
//         return 1;
//     int i = 1;
//     int j = n; 
//     int frontSum = 1;
//     int backSum  = n;
        
//     while(i < j) {
//         if(frontSum < backSum) {
//             i++;
//             frontSum += i;
//         } else {
//             j--;
//             backSum += j;
//         }
//     }
//     return frontSum == backSum ? i : -1;
// }


// // ▶️ Approach-4 (Using Binary Search)
// // ⏲️ Time Complexity : log(n)
// // 🛢️ Space Complexity : O(1)

// int pivotInteger(int n) {
//     if(n == 1)
//         return 1;
        
//     int totalSum = n * (n+1)/2;  
//     int left = 1, right = n;
//     while(left <= right) {
            
//         int mid_pivot = left + (right-left)/2;
            
//         if(mid_pivot * mid_pivot == totalSum) {
//             return mid_pivot;
//         } else if(mid_pivot * mid_pivot < totalSum) {
//             left = mid_pivot+1;
//         } else {
//             right = mid_pivot-1;
//         } 
//     }  
//     return -1;
// }



// ▶️ Approach-5 (Using quick math)
// ⏲️ Time Complexity : O(1)
// 🛢️ Space Complexity : O(1)

int pivotInteger(int n) {
    if(n == 1)
        return 1;
        
    int totalSum = n * (n+1)/2;
        
    int pivot = sqrt(totalSum);
        
    if(pivot*pivot == totalSum)
        return pivot;
        
    return -1;      
}

int main()
{
    int n = 8;
    int ans = pivotInteger(n);
    cout << "ans is : " << ans << endl;
    return 0;
}
