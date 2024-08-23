#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Goldman Sachs ✯  

// ▶️ Approach-1 (Simple simulation)
// ⏲️ Time Complexity : O(n), n = length of expression
// 🛢️ Space Complexity : O(1)

string fractionAddition(string expr) {
    int nume = 0;
    int deno = 1;

    int i = 0;
    int n = expr.length();
    while(i < n) {
        int currNume = 0;
        int currDeno = 0;

        bool isNeg = (expr[i] == '-');
            
        if(expr[i] == '+' || expr[i] == '-') {
            i++;
        }

        // 👉 Build the currNume
        while(i < n && isdigit(expr[i])) {
            int val = expr[i] - '0';
            currNume = (currNume*10) + val;
            i++;
        }

        i++; // 👉 numerator / denominator //skipiing the divisrio character '/'

        if(isNeg == true) {
            currNume *= -1;
        }

        // 👉 Build the currDeno
        while(i < n && isdigit(expr[i])) {
            int val = expr[i] - '0';
            currDeno = (currDeno * 10) + val;
            i++;
        }

        nume = nume * currDeno + currNume * deno;
        deno = deno * currDeno;
    }

    // 👉 num
    // 👉 deno
    //-3 / 6 //GCD : 3
    int GCD = abs(__gcd(nume, deno)); //3

    nume /= GCD; //-1
    deno /= GCD; //2

    return to_string(nume) + "/" + to_string(deno); //"-1/2"
}

int main()
{
    string expression = "-1/2+1/2";
    string ans = fractionAddition(expression);
    cout << "ans is : " << ans << endl;
    return 0;
}
