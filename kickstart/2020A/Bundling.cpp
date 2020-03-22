#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n, k;
struct node {
    node* ptr[26];
    int num, len;
};

void insert(node* root, char* s) {
    for(int i=0 ;i<strlen(s); i++) {
        if(root->ptr[s[i]-'A'] != NULL) {
            root->num += 1;
        }
        else {
            root->ptr[s[i]-'A'] = new node();
            root->num = 1;
            root->ptr[s[i]-'A']->num = root->num + 1;
        }
    }
}

void read() {
    char s[1000010];
    node* root = new node();
    root->num = 0;
    root->len = 0;
    for(int i=0; i<n; i++) {
        scanf("%s", s+1);
        s[0] = ' ';
        insert(root, s);
    }
}

void solve() {
    if()


}

int main() {
    scanf("%d", &t);
    for(int ce=1; ce<=t; ce++) {
        scanf("%d%d", &n, &k);
        read();
        solve();

    }


    return 0;
}