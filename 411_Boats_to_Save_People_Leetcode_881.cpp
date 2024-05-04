#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Salesforce ✯   Amazon ✯   Intuit ✯   Microsoft ✯   Uber ✯   Apple   Bloomberg  Google

int numRescueBoats(vector<int>& people, int limit) {
    int n = people.size();
        
    //sort the array
    sort(begin(people), end(people));
    int i = 0, j = n-1;
    int boats = 0;
    while(i <= j) {
        if(people[j] + people[i] <= limit) {
            i++;
            j--;
        } else {
            j--;
        }
        boats += 1;
    }
    return boats;
}

int main()
{
    vector<int> people = {1,2};
    int limit = 3;
    int ans = numRescueBoats(people,limit);
    cout << "ans is : " << ans << endl;
    return 0;
}
