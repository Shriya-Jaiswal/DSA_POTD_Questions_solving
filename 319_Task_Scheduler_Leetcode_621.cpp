#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

// ▶️ Ask by :  Facebook ✯   Amazon ✯   Uber ✯   Rubrik ✯   Microsoft ✯  

int leastInterval(vector<char>& tasks, int p) {
    int n = tasks.size();
    unordered_map<char, int> mp;
        
    for(char &ch : tasks) {
        mp[ch]++;
    }

    priority_queue<int> pq; //max heap
    // 👉 we want to finish the process which is most occurring (having highest frequency)
    // 👉 so that we don't have to finish in the last with p gaps.
    int time = 0;
        
    for(auto &it : mp) {
        pq.push(it.second);
    }
        
    while(!pq.empty()) {
        vector<int> temp;
        for(int i = 1; i<=p+1; i++) {
            // 👉 filling first p+1 characters
            if(!pq.empty()) {
                temp.push_back(pq.top()-1); // 👉 finishing one instance of each process
                pq.pop();
            }
        }
            
        for(int &freq : temp) {
            if(freq > 0)
                pq.push(freq);
        }
            
        if(pq.empty()) // 👉 all processes finished
            time += temp.size();
        else
            time += (p+1); // 👉 we finished p+1 tasks above in the loop    
    }  
    return time;
}

int main()
{
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    int ans = leastInterval(tasks,n);
    cout << "ans is : " << ans << endl;
    return 0;
}
