#include<iostream>
#include<vector>
using namespace std;


//  ▶️ Ask by : Adobe ✯  

// int minMovesToSeat(vector<int>& seats, vector<int>& students) {
//     int n = seats.size();

//     vector<int> positionSeat(101,0);        
//     vector<int> positionStu(101,0);        

//     for(int &pos : seats){
//         positionSeat[pos]++;
//     }
//     for(int &pos : students){
//         positionStu[pos]++;
//     }

//     int i = 0;
//     int j = 0;
//     int moves = 0;


//     while(i <= 100 && j <= 100){
//         if(positionSeat[i] == 0){
//             i++;
//         }
//         if(positionStu[j] == 0){
//             j++;
//         }

//         if( i<=100 && j<=100 && positionSeat[i] != 0 && positionStu[j] != 0){
//             moves += abs(i-j);
//             positionSeat[i]--;
//             positionStu[j]--;
//         }
//     }
//     return moves;
// }


// ▶️ more optimized

int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    int n = seats.size();

    vector<int> positionSeat(101,0);        
    vector<int> positionStu(101,0);        

    for(int &pos : seats){
        positionSeat[pos]++;
    }
    for(int &pos : students){
        positionStu[pos]++;
    }

    int i = 0;
    int j = 0;
    int moves = 0;


    while(n > 0){
        if(positionSeat[i] == 0){
            i++;
        }
        if(positionStu[j] == 0){
            j++;
        }

        if(positionSeat[i] != 0 && positionStu[j] != 0){
            moves += abs(i-j);
            positionSeat[i]--;
            positionStu[j]--;
            n--;
        }
    }
    return moves;
}

int main()
{
    vector<int> seats = {3,1,5};
    vector<int> students = {2,7,4};
    int ans = minMovesToSeat(seats,students);
    cout << "ans is : " << ans << endl;
    return 0;
}
