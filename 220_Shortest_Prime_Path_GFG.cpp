#include<iostream>
#include<queue>
#include<unordered_set>
using namespace std;

// ▶️ Ask by : Adobe

int solve(int Num1,int Num2){
    vector<int> prime(10000,1);
    for(int i=2;i*i<10000;i++){
        if(prime[i]){
            for(int j=2*i;j<10000;j+=i) prime[j]=0;
        }
    }
    unordered_set<int> st;
    for(int i=1000;i<10000;i++) if(prime[i]) st.insert(i);
    queue<pair<int,int>> q;
    q.push({0,Num1});
    while(!q.empty()){
        int dist = q.front().first;
        int n = q.front().second;
        q.pop();
        if(n == Num2) return dist;
        string num=to_string(n);
        for(int i=0;i<4;i++){
            for(int j=0;j<=9;j++){
                char c=num[i];
                num[i]=('0'+j);
                int nNum=stoi(num);
                if(st.find(nNum) != st.end())
                {
                st.erase(nNum);
                if(Num2 == nNum) return dist+1;
                q.push({dist+1,nNum});
                }
                num[i]=c;
            }
        }
    }
    return -1;      
}

// ⏲️ Expected Time Complexity: O(nlogn)
// 🛢️ Expected Auxiliary Space: O(n)

int main()
{
    int num1 = 1033 ;
    int num2 = 8179;
    int ans = solve(num1,num2);
    cout << "ans is : " << ans << endl;
    return 0;
}
