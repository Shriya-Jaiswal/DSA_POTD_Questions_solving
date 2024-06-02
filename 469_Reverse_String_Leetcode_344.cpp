#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Microsoft ✯   Adobe ✯   Facebook ✯   tcs ✯   Apple   Intel  

void reverseString(vector<char>& s) { 
    int right = s.size()-1;
    int left = 0;
    while(left < right)
    {
        char c = s[left];
        s[left] = s[right];
        s[right] = c;
            
        left+=1;
        right-=1;
    }
}

int main()
{
    vector<char> s = {'h','e','l','l','o'};
    reverseString(s);
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    
    return 0;
}
