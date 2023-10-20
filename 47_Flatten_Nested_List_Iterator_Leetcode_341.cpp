#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// ▶️ google, uber, Linkedin, Apple, facebook,Airbnb, Twitter, Amazon, salesforce

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
    vector<vector<int>> nestedList = {{1,1},{2},{1,1}};
    return 0;
}
