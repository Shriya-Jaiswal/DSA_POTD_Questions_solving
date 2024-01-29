#include<iostream>
#include<stack>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Microsoft ✯   Goldman Sachs ✯   eBay ✯   Google ✯  

// ⏲️ Time Complexity : push - O(1), pop - Amortized O(1) , peek() - O(1), empty() - O(1)
// 🛢️ Space.Complexity : O(n)

class MyQueue {
public:
    
    stack<int> input;
    stack<int> output;
    int peekEl = -1;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()) {
            peekEl = x;
        }
        input.push(x); //ye to har baar karna hai
    }
    //amortized O(1)
    int pop() {
        if(output.empty()) {
            //input -> output O(n)
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        
        int val = output.top(); //O(1)
        output.pop();
        return val;
    }
    
    int peek() {
        if(output.empty())
            return peekEl;
        
        return output.top();
    }
    
    bool empty() {
        if(input.empty() && output.empty())
            return true;
        
        return false;
    }
};

int main()
{
    MyQueue q;
    q.push(2);
    q.push(12);
    q.push(21);
    q.push(22);
    q.push(24);
    q.push(52);
    q.push(532);

    cout << q.peek() << endl; 
    cout << q.empty() << endl; 

    q.pop();
    cout << q.peek() << endl; 
    return 0;
}
