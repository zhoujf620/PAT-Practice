// 1056. Mice and Rice (25)

// <i>Mice and Rice</i> is the name of a programming contest in which each programmer must write a piece of code to control the movements of a mouse in a given map.  The goal of each mouse is to eat as much rice as possible in order to become a FatMouse.

// First the playing order is randomly decided for NP programmers.  Then every NG programmers are grouped in a match.  The fattest mouse in a group wins and enters the next turn.  All the losers in this turn are ranked the same.  Every NG winners are then grouped in the next match until a final winner is determined.

// For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits his/her code.  Given the weights of all the mice and the initial playing order, you are supposed to output the ranks for the programmers.

// Input Specification:

// Each input file contains one test case.  For each case, the first line contains 2 positive integers: NP and NG (<= 1000), the number of programmers and the maximum number of mice in a group, respectively.  If there are less than NG mice at the end of the player's list, then all the mice left will be put into the last group.  The second line contains NP distinct non-negative numbers Wi (i=0,...NP-1) where each Wi is the weight of the i-th mouse respectively.  The third line gives the initial playing order which is a permutation of 0,...NP-1 (assume that the programmers are numbered from 0 to NP-1).  All the numbers in a line are separated by a space.

// Output Specification:

// For each test case, print the final ranks in a line.  The i-th number is the rank of the i-th programmer, and all the numbers must be separated by a space, with no extra space at the end of the line.

// Sample Input:
// 11 3
// 25 18 0 46 37 3 19 22 57 56 10
// 6 0 8 7 10 5 9 1 4 2 3

// Sample Output:
// 5 5 5 2 5 5 5 3 1 3 5


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Mouse{
    int weight, rank;
};
int main(){
    int NP, NG;
    cin >> NP >> NG;

    vector<Mouse> mice(NP);
    for(int i=0; i<NP; i++) 
        scanf("%d", &mice[i].weight);
    
    queue<int> q;
    int order;
    for(int i=0; i<NP; i++){
        scanf("%d", &order);
        q.push(order);
    }

    while(q.size()>1){
        int last_group = q.size()%NG==0 ? NG : q.size()%NG;
        int num_group = (q.size()-1) / NG + 1;

        for(int i=0; i<num_group; i++){
            int cur_size = i==num_group-1 ? last_group : NG;
            int index = q.front();

            for(int j=0; j<cur_size; j++){
                mice[q.front()].rank = num_group + 1;
                if(mice[q.front()].weight > mice[index].weight)
                    index = q.front();
                q.pop();
            }
            q.push(index);
        }
    }
    mice[q.front()].rank=1; 

    for(int i=0; i<NP; i++)
        printf("%s%d",i>0?" ":"",mice[i].rank);
    return 0;

}
