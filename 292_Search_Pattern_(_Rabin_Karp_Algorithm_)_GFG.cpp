#include<iostream>
#include<vector>
using namespace std;

// ▶️ Ask by : Microsoft

vector <int> search(string pat, string txt){
    vector<int>res;
    int q=101;
    int d=26;
    int M=pat.size();
    int N=txt.size();
    int p=0;
    int t=0;
    int h=1;
            
    //h=pow(d,M-1)%q;
    for(int i=0;i<M-1;i++){
        h=(h*d)%q;
    }
            
    //calcualate the hash value of pattern and first window of text
    for(int i=0;i<M;i++){
        p=(d*p+pat[i])%q;
        t=(d*t+txt[i])%q;
    }
            
    //slide the pattern over thext one by one
    for(int i=0;i<=N-M;i++){
        //check the hash if they are equal
        if(p==t){
            //check for characters one by one
            int j=0;
            for(j=0;j<M;j++){
                if(txt[i+j]!=pat[j]){
                    break;
                }
            }
            if(j==M){
                res.push_back(i+1);
            }
                    
        }
        if(i<N-M){
            t=(d*(t-txt[i]*h)+txt[i+M])%q;
            if(t<0){
                t=t+q;
            }
        }
    }
    return res;
}

// ⏲️ Expected Time Complexity: O(|text| + |pattern|).
// 🛢️ Expected Auxiliary Space: O(1).

int main()
{
    string text = "birthdayboy";
    string pattern = "birth";
    vector<int> ans = search(pattern,text);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
