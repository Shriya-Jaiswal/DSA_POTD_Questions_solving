#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;


// ▶️ Ask by meta, google, Amazon

// ➡️ Using simple Greedy
// ⏲️ Time Complexity : O(nlogn)

typedef pair<int, int> P;
int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int n = dist.size();
        
        vector<int> vec(n);
        
        for(int i = 0; i<n; i++) {
            vec[i] = ceil((float) dist[i] / speed[i]);
        }
        
        
        sort(begin(vec), end(vec));
        

        
        int count = 1;
        
        int time_passed = 1;
        for(int i = 1; i<n; i++) {
            if(vec[i] - time_passed <= 0)
                return count;
            
            count++;
            time_passed++;
        }
        
        return count;
}

int main()
{
    vector<int> dist {1,3,4};
    vector<int> speed {1,1,1};
    int ans = eliminateMaximum(dist,speed);
    cout << "ans is : " << ans << endl;

    return 0;
}
