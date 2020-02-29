#define N (100+2)
#define M (N*N+4*N)

/*
* 顶点从0号开始，若从1号开始，不用做特殊处理
* 顶点数+1即可，相当于0号节点不连通
* head[u]为e中最后一条<u,v>的索引
* e[i].next为e中i前一条同u的索引
*/


typedef long long LL;

using namespace std;

struct edge {
  int v, cap, next;
};
edge e[M];

int head[N];
int num_of_edges=0;

int add_edge(int u, int v, int c1, int c2) {
  int i=num_of_edges;

  assert(c1>=0 && c2>=0 && c1+c2>=0); // check for possibility of overflow
  e[i].v = v;
  e[i].cap = c1;
  e[i].next = head[u];
  head[u] = i;
  num_of_edges++;
}

void print_graph(int n) {
  for (int u=0; u<n; u++) {
    printf("%d: ", u);
    for (int i=head[u]; i>=0; i=e[i].next) {
      printf("%d(%d)", e[i].v, e[i].cap);
    }
    printf("\n");
  }
  return;
}

void init_graph(){
  memset(head, -1, sizeof(head));
}

