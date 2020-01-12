// 1012. The Best Rank (25)

// To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English.  At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

// For example, The grades of C, M, E and A - Average of 4 students are given as the following:
// StudentID  C  M  E  A
// 310101     98 85 88 90
// 310102     70 95 88 84
// 310103     82 87 94 88
// 310104     91 91 91 91

// Then the best ranks for all the students are <i>No.1</i> since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

// Input

// Each input file contains one test case.  Each case starts with a line containing 2 numbers N and M (<=2000), which are the total number of students, and the number of students who would check their ranks, respectively.  Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100) of that student in the order of C, M and E.  Then there are M lines, each containing a student ID.

// Output

// For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

// The priorities of the ranking methods are ordered as A &gt; C &gt; M &gt; E.  Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

// If a student is not on the grading list, simply output "N/A".

// Sample Input
// 5 6
// 310101 98 85 88
// 310102 70 95 88
// 310103 82 87 94
// 310104 91 91 91
// 310105 85 90 90
// 310101
// 310102
// 310103
// 310104
// 310105
// 999999

// Sample Output
// 1 C
// 1 M
// 1 E
// 1 A
// 3 A
// N/A


#include <iostream>
#include <algorithm>
using namespace std;

struct item {
    int id, best;
    float score[4];
    int rank[4];
}stu[2001];

int course = -1;
bool cmp(item a, item b) {return a.score[course] > b.score[course];}

int main() {
    int N, M;
    cin >> N >> M;

    int id;
    for(int i = 0; i < N; i++) {
        scanf("%d %f %f %f", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0;
    }

    for(course = 0; course <= 3; course++) {
        sort(stu, stu + N, cmp);

        stu[0].rank[course] = 1;
        for(int i = 1; i < N; i++) {
            stu[i].rank[course] = i + 1;
            if(stu[i].score[course] == stu[i-1].score[course])
                stu[i].rank[course] = stu[i-1].rank[course];
        }
    }

    int exist[1000000] = {0};
    for(int i = 0; i < N; i++) {
        exist[stu[i].id] = i + 1;
        stu[i].best = distance(stu[i].rank, min_element(stu[i].rank, stu[i].rank+4));
    }

    char c[5] = {'A', 'C', 'M', 'E'};
    for(int i = 0; i < M; i++) {
        scanf("%d", &id);
        int asked_id = exist[id];
        if(asked_id) {
            int best = stu[asked_id-1].best;
            printf("%d %c\n", stu[asked_id-1].rank[best], c[best]);
        } 
        else {
            printf("N/A\n");
        }
    }
    return 0;
}
