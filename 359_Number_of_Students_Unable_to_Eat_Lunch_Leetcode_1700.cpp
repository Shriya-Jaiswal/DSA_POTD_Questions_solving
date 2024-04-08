#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

// // ▶️ Ask by :  Flipkart ✯  

// // ▶️ Approach-1 (Simply simulate whatever the problem asks for)
// // ⏲️ Time Complexity : O(n)
// // 🛢️ Space Complexity : O(n)

// int countStudents(vector<int>& students, vector<int>& sandwiches) {
//     int len = students.size();
//     queue<int> que;
//     stack<int> st;
//     for (int i = 0; i < len; i++) {
//         st.push(sandwiches[len - i - 1]);
//         que.push(students[i]);
//     }
//     int lastServed = 0;
//     while (!que.empty() && lastServed < que.size()) {
//         if (st.top() == que.front()) {
//             st.pop();
//             que.pop();
//             lastServed = 0;
//         } else {
//             que.push(que.front());
//             que.pop();
//             lastServed++;
//         }
//     }
//     return que.size();
// }

// ▶️ Aproach-2 (Using counter only)
// ⏲️ Time Complexity : O(n)
// 🛢️ Space Complexity : O(1)

int countStudents(vector<int>& stud, vector<int>& sand) {
    int n = stud.size();
    int arr[2] = {0};
    //arr[0] = count of student who like circular
    //arr[1] = count of student who like square
          
    for(int &x : stud)
        arr[x]++;
        
    for(int i = 0; i<n; i++) {
        if(arr[sand[i]] == 0) return n-i;
        arr[sand[i]]--;
    }
        
    return 0;
}

int main()
{
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    int ans = countStudents(students,sandwiches);
    cout << "ans is : " << ans << endl;
    return 0;
}
