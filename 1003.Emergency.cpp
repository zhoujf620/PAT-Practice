// 1003 Emergency (25分)

// As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

// Input

// Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) – the number of cities (and the cities are numbered from 0 to N-1), M – the number of roads, C1 and C2 – the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

// Output

// For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
// All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

// Sample Input

// 5 6 0 2
// 1 2 1 5 3
// 0 1 1
// 0 2 2
// 0 3 1
// 1 2 1
// 2 4 1
// 3 4 1

// Sample Output

// 2 4

#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 99999999;

int main() {
    int N, M, C1, C2;
    cin >> N >> M >> C1 >> C2;

    int teams[501];
    for(int i = 0; i < N; i++)
        scanf("%d", &teams[i]);

    int edgelist[501][501], dists[501];
    fill(edgelist[0], edgelist[0] + 501*501, INF);
    int city1, city2, dist;
    for(int i = 0; i < M; i++) {
        scanf("%d%d%d", &city1, &city2, &dist);
        edgelist[city1][city2] = edgelist[city2][city1] = dist;
    }
    
    fill(dists, dists + 501, INF);
    dists[C1] = 0;

    int path_count[501], team_sum[501];
    team_sum[C1] = teams[C1];
    path_count[C1] = 1;

    bool visit[501];
    for(int i = 0; i < N; i++) {

        int u = -1, dmin = INF;
        for(int j = 0; j < N; j++) {
            if(visit[j] == false && dists[j] < dmin) {
                u = j;
                dmin = dists[j];
            }
        }    
        if(u == -1) break;
        visit[u] = true;

        for(int v = 0; v < N; v++) {
            if(visit[v] == false && edgelist[u][v] != INF) {
                if(dists[u] + edgelist[u][v] < dists[v]) {
                    dists[v] = dists[u] + edgelist[u][v];
                    path_count[v] = path_count[u];
                    team_sum[v] = team_sum[u] + teams[v];

                } else if(dists[u] + edgelist[u][v] == dists[v]) {
                    path_count[v] += path_count[u];
                    if(team_sum[u] + teams[v] > team_sum[v])
                        team_sum[v] = team_sum[u] + teams[v];
                }
            }
        }
    }
    printf("%d %d", path_count[C2], team_sum[C2]);
    return 0;
}
