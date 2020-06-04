/*
考虑不周！！！
过了，没有用c++库
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_SIZE = 35;
int t, r, c;

int graph[MAX_SIZE][MAX_SIZE];
int in[MAX_SIZE];
char s1[MAX_SIZE], s2[MAX_SIZE], s[MAX_SIZE];
int flag[MAX_SIZE];

void make_graph() {
    for(int i=0; i<MAX_SIZE; i++) {
        in[i] = 0;
        flag[i] = 0;
        for(int j=0; j<MAX_SIZE; j++)
            graph[i][j] = 0;         
    }
       

    for(int i=0; i<r; i++) {
        scanf("%s", &s2);
        if(i == 0)
            strcpy(s1, s2);
        for(int j=0; j<c; j++) {
            flag[s1[j]-'A'] = 1;
            flag[s2[j]-'A'] = 1;
            if(s2[j] != s1[j] && graph[s2[j]-'A'][s1[j]-'A'] != 1) {             
                in[s1[j]-'A'] += 1;
                graph[s2[j]-'A'][s1[j]-'A'] = 1;
            }
        }
        strcpy(s1, s2);
    }
}

void topo_sort() {
    int stack[MAX_SIZE];
    int top = -1;
    for(int i=0; i<MAX_SIZE; i++) {
        if(in[i] == 0 && flag[i] == 1) {
            top++;
            stack[top] = i;
        }
    }
    int idx = 0;
    while(top != -1) {
        int i = stack[top];
        s[idx] = i + 'A';
        idx++;
        top--;
        for(int j=0; j<MAX_SIZE; j++) {
            if(graph[i][j] != 0 && in[j] != 0) {
                in[j]--;
                if(in[j] == 0) {
                    top++;
                    stack[top] = j;
                }
            }
        }
    }
    for(int k=0; k<MAX_SIZE; k++) {
        if(in[k] != 0) {
            idx = 0;
            break;
        }
    }
    s[idx] = '\0';
}


int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    
    for(int ce=1; ce<=t; ce++) {
        scanf("%d%d", &r, &c);
        make_graph();
        topo_sort();
        if(strlen(s) == 0)
            printf("Case #%d: %d\n", ce, -1);
        else
            printf("Case #%d: %s\n", ce, s);
    }

    return 0;
}