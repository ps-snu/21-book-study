#include <iostream>
#include <float.h>
#include <vector>
using namespace std;

double minAverage(vector<int>& costs, int m);

int main() {
    int C, n, l;
    int cost;
    vector<int> N, L;

    cin >> C;
    vector<vector<int>> costs(C);

    for (int i = 0; i < C; i++) {
        cin >> n >> l;
        N.push_back(n);
        L.push_back(l);

        for (int j = 0; j < n; j++) {
            cin >> cost;
            costs[i].push_back(cost);
        }           
    }

    for (int i = 0; i < C; i++) {
        double result = DBL_MAX;
        for (int m = L[i]; m <= N[i]; m++) {
            double partMin = minAverage(costs[i], m);
            result = min(result, partMin);
        }
        printf("%.8f\n", result);
    }
    
    return 0;
}

double minAverage(vector<int>& costs, int m) {
    int n = costs.size();
    double resultSum = DBL_MAX;
    double sum = 0;

    for (int i = 0; i < m - 1; i++) {
        sum += costs[i];
    }

    for (int i = m - 1; i < n; i++) {
        sum += costs[i];
        resultSum = min(resultSum, sum);
        sum -= costs[i - m + 1];
    }

    return resultSum / m;
}