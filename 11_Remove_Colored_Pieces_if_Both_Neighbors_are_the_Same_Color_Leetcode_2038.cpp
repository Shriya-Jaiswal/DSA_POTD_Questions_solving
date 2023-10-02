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

int main()
{
    string colors = "AAABABB";
    bool ans = winnerOfGame(colors);
    cout <<"ans is : "<< ans << endl;
    return 0;
}
