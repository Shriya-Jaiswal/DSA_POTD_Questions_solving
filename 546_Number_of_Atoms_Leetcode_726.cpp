#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include <map>
using namespace std;

// ▶️ Ask by :  Coupang ✯   Apple ✯   Google ✯   Amazon ✯   Microsoft ✯   HRT  

// ▶️ Using stack
// ⏲️ Time Complexity : O(n^2)
// 🛢️ Space Complexity : O(n)

typedef unordered_map<string, int> MAP;

string countOfAtoms(string formula) {
    int n = formula.length();
        
    stack<MAP> st;
    st.push(MAP());

    int i = 0;

    while (i < n) {
        if (formula[i] == '(') {
            st.push(MAP());
            i++;
        } else if (formula[i] == ')') {
            MAP currMap = st.top();
            st.pop();
            i++;
            string multiplier;
            while (i < formula.length() && isdigit(formula[i])) {
                multiplier += formula[i];
                i++;
            }
            if (!multiplier.empty()) {
                int mult = stoi(multiplier);
                for (auto& [atom, count] : currMap) {
                    currMap[atom] = count * mult;
                }
            }

            for (auto& [atom, count] : currMap) {
                st.top()[atom] += count;
            }
        } else {
            string currAtom;
            currAtom += formula[i];
            i++;
            while (i < formula.length() && islower(formula[i])) {
                currAtom += formula[i];
                i++;
            }

            string currCount;
            while (i < formula.length() && isdigit(formula[i])) {
                currCount += formula[i];
                i++;
            }

            int count = currCount.empty() ? 1 : stoi(currCount);
            st.top()[currAtom] += count;
        }
 
    }
        
    map<string, int> sortedMap(begin(st.top()), end(st.top()));

    string result;
    for (auto& [atom, count] : sortedMap) {
        result += atom;
        if (count > 1) {
            result += to_string(count);
        }
    }

    return result;
}

int main()
{
    string formula = "H2O";
    string ans = countOfAtoms(formula);
    cout << "ans is : " << ans << endl;
    return 0;
}
