#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// ▶️ Ask by :  Amazon ✯   Arcesium ✯   Google ✯  

// // ▶️ Approach-1 (Brute Force - Heap + Math) - TLE
// // ⏲️ Time Complexity : O(n * (n + klogk))
// // 🛢️ Space Complexity : O(n+k)

// double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
//     int n = quality.size();

//     double result = DBL_MAX; //std::numeric_limits<double>::max()
//     //maximum representable finite floating-point (double) number

//     for(int manager = 0; manager < n; manager++) {
            
//         double managerRatio = (double)min_wage[manager]/quality[manager];

//         vector<double> group;
//         for(int worker = 0; worker < n; worker++) {
//             double worker_wage = quality[worker] * managerRatio;
//             if(worker_wage >= min_wage[worker]) {
//                 group.push_back(worker_wage);
//             }
//         }

//         if(group.size() < k)
//             continue;
            
//         priority_queue<double, vector<double>> pq;
//         double sum = 0;

//         for(double &wage : group) {
//             sum += wage;
//             pq.push(wage);

//             if(pq.size() > k) {
//                 sum -= pq.top();
//                 pq.pop();
//             }
//         }
//         result = min(result, sum);
//     }
//     return result;
// }

// // ▶️ Approach-2 (Improved Brute Force - Heap + Math) - TLE
// // ⏲️ Time Complexity : O(nlogn + n * (n + klogk)) - This is worst case when no one got eliminated 
// // 🛢️ Space Complexity : O(n+k)

// double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
//     int n = quality.size();

//     double result = DBL_MAX; //std::numeric_limits<double>::max()
//     //maximum representable finite floating-point (double) number

//     vector<pair<double, int>> worker_ratio(n);
//     for(int worker = 0; worker < n; worker++) {
//         worker_ratio[worker] = make_pair((double)min_wage[worker]/quality[worker], quality[worker]);
//     }

//     sort(begin(worker_ratio), end(worker_ratio));

//     for(int manager = k-1; manager < n; manager++) {
            
//         double managerRatio = worker_ratio[manager].first;

//         vector<double> group;
//         for(int worker = 0; worker <= manager; worker++) {
//             double worker_wage = worker_ratio[worker].second * managerRatio;
//             group.push_back(worker_wage);
//         }

//         priority_queue<double, vector<double>> pq;
//         double sum = 0;

//         for(double &wage : group) {
//             sum += wage;
//             pq.push(wage);

//             if(pq.size() > k) {
//                 sum -= pq.top();
//                 pq.pop();
//             }
//         }

//         result = min(result, sum);

//     }

//     return result;
// }



// ▶️ Approach-3 (Optimal)
// ⏲️ Time Complexity : O(nlogn + klogk + n*log(k))
// 🛢️ Space Complexity : O(n+k)

double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
    int n = quality.size();

    vector<pair<double, int>> worker_ratio(n);
    for(int worker = 0; worker < n; worker++) {
        worker_ratio[worker] = make_pair((double)min_wage[worker]/quality[worker], quality[worker]);
    }
    sort(begin(worker_ratio), end(worker_ratio));

    priority_queue<int, vector<int>> pq;
        
    double sum_quality = 0;
    for(int i = 0; i < k; i++) { 
        pq.push(worker_ratio[i].second); //push all qualities in max-heap
        sum_quality += worker_ratio[i].second; //Find sum of qualities
    }

    double managerRatio = worker_ratio[k-1].first; 
    double result       = managerRatio * sum_quality;

    for(int manager = k; manager < n; manager++) {
            
        managerRatio = worker_ratio[manager].first;

        pq.push(worker_ratio[manager].second); //push all qualities in max-heap
        sum_quality += worker_ratio[manager].second; //Find sum of qualities

        if(pq.size() > k) {
            sum_quality -= pq.top();
            pq.pop();
        }
        result = min(result, managerRatio*sum_quality);
    }
    return result;
}

int main()
{
    
    vector<int> quality = {10,20,5};
    vector<int> wage = {70,50,30};
    int k = 2;

    double ans = mincostToHireWorkers(quality,wage,k);
    cout << "ans is : " << ans << endl;

    return 0;
}
