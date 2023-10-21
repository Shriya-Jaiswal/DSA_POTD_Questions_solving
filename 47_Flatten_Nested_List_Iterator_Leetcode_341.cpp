#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

// ▶️ google, uber, Linkedin, Apple, facebook,Airbnb, Twitter, Amazon, salesforce


// // ▶️ ▶️ Approach 1
// class NestedIterator_Approach_1 {
// public:
//     stack<NestedInteger>s;

//      NestedIterator_Approach_1(vector<NestedInteger> &nestedList) {
//         int n = nestedList.size();
//         for(int i=n-1; i>=0; i--){
//             s.push(nestedList[i]);
//         }    
//     }
//     int next() {
//         int num = s.top().getInteger();
//         s.pop();

//         return num;
//     }
    
//     bool hasNext() {
//        if(s.empty()){
//         return false;
//        }
//        while(!s.empty()){
//         NestedInteger curr =  s.top();
//         if(curr.isInteger()){
//             return true;
//         }
//         s.pop();
//         vector<NestedInteger> vec = curr.getList();
//         for(int i = vec.size()-1; i>=0; i-- ){
//             s.push(vec[i]);
//         }
//        }
//        return false;
//     }
// };



// // // ▶️ ▶️ Approach 2
// class NestedIterator_Approach_2 {
// public:
//     stack<NestedInteger*>s;

//      NestedIterator_Approach_2(vector<NestedInteger> &nestedList) {
//         int n = nestedList.size();
//         for(int i=n-1; i>=0; i--){
//             s.push(&nestedList[i]); // &obj
//         }    
//     }
//     int next() {
//         int num = s.top()->getInteger();
//         s.pop();

//         return num;
//     }
    
//     bool hasNext() {
//        if(s.empty()){
//         return false;
//        }
//        while(!s.empty()){
//         NestedInteger curr* =  s.top();
//         if(curr->isInteger()){
//             return true;
//         }
//         s.pop();
//         vector<NestedInteger>& vec = curr->getList(); // 👉 receive by ref
//         for(int i = vec.size()-1; i>=0; i-- ){
//             s.push(&vec[i]);
//         }
//        }
//        return false;
//     }
// };


// ▶️ ▶️ Approach 3
class NestedIterator {
public:
    queue<int> q;

    void Flatten(vector<NestedInteger> &nestedList){
        int n = nestedList.size();
        for(int i=0; i<n; i++){
            NestedInteger & obj = nestedList[i];
            if(obj.isInteger()){
                q.push(obj.getInteger());
            }
            else{
                Flatten(obj.getList());
            }
        }
    }


    NestedIterator(vector<NestedInteger> &nestedList) {
        Flatten(nestedList);    
    }
    
    int next() {
        int num =  q.front();
        q.pop();
        return num;
    }
    
    bool hasNext() {
        if(q.empty()){
            return false;
        }
        return true;
    }
};

int main()
{
    // NestedIterator obj;
    vector<vector<int>> nestedList = {{1,1},{2},{1,1}};
    return 0;
}
