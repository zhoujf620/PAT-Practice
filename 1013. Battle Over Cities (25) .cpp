
// 1013. Battle Over Cities (25)

// It is vitally important to have all the cities connected by highways in a war.  If a city is occupied by the enemy, all the highways from/toward that city are closed.  We must know immediately if we need to repair any other highways to keep the rest of the cities connected.  Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

// For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3.  Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.

// Input

// Each input file contains one test case.  Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively.  Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects.  The cities are numbered from 1 to N.  Finally there is a line containing K numbers, which represent the cities we concern.

// Output

// For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

// Sample Input
// 3 2 3
// 1 2
// 1 3
// 1 2 3

// Sample Output
// 1
// 0
// 0

#include <iostream>
#include <algorithm>
using namespace std;

int cities[1001][1001];
bool visited[1001];
int N;

void DFS(int city) {
    visited[city] = true;
    for(int i = 1; i <= N; i++) {
        if(visited[i] == false && cities[city][i] == 1)
            DFS(i);
    }
}
int main() {
    int M, K;
    cin >> N >> M >> K;

    int city1, city2;
    for(int i = 0; i < M; i++) {
        scanf("%d%d", &city1, &city2);
        cities[city1][city2] = cities[city2][city1] = 1;
    }

    for(int i = 0; i < K; i++) {
        fill(visited, visited + 1001, false);

        scanf("%d", &city1);
        int cnt = 0;
        visited[city1] = true;
        for(int j = 1; j <= N; j++) {
            if(visited[j] == false) {
                DFS(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}