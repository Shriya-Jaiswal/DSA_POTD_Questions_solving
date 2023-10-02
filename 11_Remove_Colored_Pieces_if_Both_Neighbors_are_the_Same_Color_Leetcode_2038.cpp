#include<iostream>
#include<vector>
using namespace std;

bool winnerOfGame(string colors) {
    int n = colors.size();
    int i = 0;
    int a = 0; 
    int b = 0;

    // 👉 Dry RUN on ---> AAABBBAABB
    while(i<n){
        int a1 = 0;
        int b1 = 0;
        while(i<n && colors[i] == 'A'){ // 👉 this while loop count --> continuous AAA
            a1++;
            i++;
        }
        while(i<n && colors[i] == 'B'){ // 👉 this while loop count continuous BBB
            b1++;
            i++;
        }
        if(a1 > 2){
            a+= a1-2;
        }
        if(b1>2){
            b+=b1-2;
        }
    }        
    if(a>b){
        return true; // 👉 bob wins
    }
    if(a<b){
        return false; // 👉 alice wins
    }
    return false; // 👉 bob wins
}


// 👉 ➡️ 2nd Approach
bool winnerOfGame2(string colors) {
        int aliceScore = 0, bobScore = 0; // Initialize scores for Alice and Bob

        // Iterate through the colors, excluding the edge pieces
        for (int i = 1; i < colors.size() - 1; i++) {
            char currentColor = colors[i];
            char prevColor = colors[i - 1];
            char nextColor = colors[i + 1];

            // Check if Alice can make a move here
            if (currentColor == 'A' && prevColor == 'A' && nextColor == 'A')
                aliceScore++; // Alice can remove 'A'

            // Check if Bob can make a move here
            else if (currentColor == 'B' && prevColor == 'B' && nextColor == 'B')
                bobScore++; // Bob can remove 'B'
        }

        // Determine the winner based on the scores
        return aliceScore > bobScore;
    }


int main()
{
    string colors = "AAABABB";
    // bool ans = winnerOfGame(colors);
    bool ans = winnerOfGame2(colors);
    cout <<"ans is : "<< ans << endl;
    return 0;
}
