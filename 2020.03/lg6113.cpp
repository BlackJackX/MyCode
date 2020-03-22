/*
抄的
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1009,M=100009;
int n,m,ans,ord,q[M],pre[N];
int ql,qr,hd[N],dfn[N],lk[N];
int pn,cl[N],nt[M],to[M],g[N];
void rd(int&x){//貌似加了快读瞬间加速近30ms，因此还是加了。
    char c=getchar();x=0;
    while(c>57||c<48)c=getchar();
    while(c>47&&c<58)
        x+=(x<<3)+x+c-48,c=getchar();
}
int find(int x){
    return g[x]==x?x:g[x]=find(g[x]);
}
void ade(int u,int v){//为方便起见，直接加双向边。
    ++pn,to[pn]=v,nt[pn]=hd[u],
    hd[u]=pn,++pn,nt[pn]=hd[v],
    hd[v]=pn,to[pn]=u;
}
int lca(int x,int y){
    for(++ord;x=find(x);swap(x,y))
        if(dfn[x]==ord)return x;//奇环编号相同，说明找到了。
        else dfn[x]=ord,x=pre[lk[x]];
}
void flw(int x,int y,int p){//开花。
    while(find(x)!=p){
        pre[x]=y,y=lk[x];
        if(cl[y]==2)cl[y]=1,q[++qr]=y;
        g[x]=p,g[y]=p,x=pre[y];
    }
}
bool dfs(int x){
    for(int i=1;i<=n;++i)g[i]=i;
    memset(cl,0,sizeof(cl));
    memset(pre,0,sizeof(pre));
    cl[q[ql=qr=1]=x]=1;//颜色为黑。
    for(int x=q[ql];ql<=qr;x=q[++ql])
        for(int i=hd[x],v,z;i;i=nt[i]){
            if(cl[v=to[i]]==2)continue;
            if(find(v)==find(x))continue;
            if(cl[v]==1)
                z=lca(x,v),flw(x,v,z),flw(v,x,z);
            else if(!cl[v]){
                cl[v]=2,pre[v]=x;
                if(!lk[v]){
                    for(int u=v,lst,y;u;u=lst)
                        lst=lk[y=pre[u]],lk[u]=y,lk[y]=u;//找到增广路了，一路取反。
                    return true;//答案+1。
                }
                cl[lk[v]]=1,q[++qr]=lk[v];//匹配它的点一定是黑点。
            }
        }
    return false;
}
int main(){
    freopen("input.txt", "r", stdin);
    scanf("%d%d",&n,&m);
    for(int u,v;m;--m)
        rd(u),rd(v),ade(u,v);
    for(int i=1;i<=n;++i)
        ans+=(!lk[i]&&dfs(i));
    printf("%d\n",ans);
    for(int i=1;i<=n;++i)
        printf("%d ",lk[i]);
    return 0*puts("");
}