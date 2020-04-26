/*
trie树, 别的都挺简单
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_LEN = 2e6+10;

int t, n, k;
char s[MAX_LEN];

struct node {
    char c;
    int num;
    node* next[26];
} *root;

node* create_node(char c) {
    node* p = new node();
    p->c = c;
    p->num = 0;
    for(int i=0; i<26; i++)
        p->next[i] = NULL;
    return p;
}

void insert(char* s, node* root) {
    if(s[0] == '\0')
        return;
    node* p = root->next[s[0]-'A'];
    if(p == NULL)
        p = create_node(s[0]);
    p->num++;
    root->next[s[0]-'A'] = p;
    insert(s+1, p);
}

void read() {
    root = create_node(' ');
    for(int i=0; i<n; i++) {
        scanf("%s", s);
        insert(s, root);        
    }
}

void del_node(node* root) {
    if(root == NULL)
        return;
    for(int i=0; i<26; i++)
        del_node(root->next[i]);
    delete root;
}

int preorder(node* root) {
    if(root == NULL)
        return 0;
    int ans = 0;
    ans += root->num / k;
    for(int i=0; i<26; i++)
        ans += preorder(root->next[i]);
    return ans;
}


int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    for(int ce=1; ce<=t; ce++) {
        scanf("%d%d", &n, &k);
        read();
        printf("Case #%d: %d\n", ce, preorder(root));
        del_node(root);
    }


    return 0;
}