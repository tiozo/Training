#include<bits/stdc++.h>
#define maxn 10500
#define oo 10000005
#define fs first
#define sc second
using namespace std;
int c[maxn][maxn],a[maxn],head[maxn],chain[maxn],cnt,dem,h[maxn],trc[maxn],n,id[maxn][maxn],pos[maxn],res;
typedef pair<int,int> II;
II dm[maxn];
struct _data
{
        int minn,maxx,lazy,change;
};
_data st[6*maxn];
vector<int> e[maxn];
void hld(int u)
{
        if (head[cnt]==0) head[cnt]=u;
        a[++dem]=u;
        pos[u]=dem;
        chain[u]=cnt;
        int vtx=-1;
        for (int i=0; i<(int)e[u].size(); i++)
        {
                int v=e[u][i];
                if (v==trc[u]) continue;
                trc[v]=u;
                if (vtx==-1) vtx=v;
        }
        if (vtx!=-1) hld(vtx);
        for (int i=0; i<(int)e[u].size(); i++)
        {
                int v=e[u][i];
                if (v==trc[u]||v==vtx) continue;
                cnt++;
                h[cnt]=h[chain[u]]+1;
                hld(v);
        }
}
int lca(int u,int v)
{
        while(chain[u]!=chain[v])
        {
                if (h[chain[u]]>h[chain[v]]) u=trc[head[chain[u]]];
                else v=trc[head[chain[v]]];
        }
        if (pos[u]<pos[v]) return u;
        else return v;
}
void build(int id,int l,int r)
{
        if (l==r)
        {
                st[id].minn=c[trc[a[l]]][a[l]];
                st[id].maxx=c[trc[a[l]]][a[l]];
                st[id].lazy=0;
                st[id].change=0;
                return;
        }
        int m=(l+r)>>1;
        build(id*2,l,m);
        build(id*2+1,m+1,r);
        st[id].minn=min(st[id*2].minn,st[id*2+1].minn);
        st[id].maxx=max(st[id*2].maxx,st[id*2+1].maxx);
        st[id].lazy=0;
        st[id].change=0;
}
void down(int id)
{
        int tmp=st[id].lazy;
        st[id*2].lazy+=tmp;
        st[id*2+1].lazy+=tmp;
        if (tmp%2)
        {
                if (st[id*2].change==0) st[id*2].change=1;
                else st[id*2].change=0;
        }
        if (tmp%2)
        {
                if (st[id*2+1].change==0) st[id*2+1].change=1;
                else st[id*2+1].change=0;
        }
        st[id].lazy=0;
}
void update1(int id,int l,int r,int i,int val)
{
        if (l>i||r<i) return;
        if (l==r&&l==i)
        {
                st[id].maxx=val;
                st[id].minn=val;
                st[id].lazy=0;
                st[id].change=0;
                return;
        }
        int m=(l+r)>>1;
        down(id);
        update1(id*2,l,m,i,val);
        update1(id*2+1,m+1,r,i,val);
        int minn1,maxx1,minn2,maxx2;
        if (st[id*2].change==0)
        {
                maxx1=st[id*2].maxx;
                minn1=st[id*2].minn;
        }
        else
        {
                maxx1=-st[id*2].minn;
                minn1=-st[id*2].maxx;
        }
        if (st[id*2+1].change==0)
        {
                maxx2=st[id*2+1].maxx;
                minn2=st[id*2+1].minn;
        }
        else
        {
                maxx2=-st[id*2+1].minn;
                minn2=-st[id*2+1].maxx;
        }
        st[id].maxx=max(maxx1,maxx2);
        st[id].minn=min(minn1,minn2);
        st[id].change=0;
}
void update2(int id,int l,int r,int i,int j)
{
        if (l>j||r<i) return;
        if (l>=i&&r<=j)
        {
                if (st[id].change) st[id].change=0;
                else st[id].change=1;
                st[id].lazy++;
                while (st[id].lazy>=2) st[id].lazy-=2;
                return;
        }
        down(id);
        int m=(l+r)>>1;
        update2(id*2,l,m,i,j);
        update2(id*2+1,m+1,r,i,j);
        int minn1,maxx1,minn2,maxx2;
        if (st[id*2].change==0)
        {
                maxx1=st[id*2].maxx;
                minn1=st[id*2].minn;
        }
        else
        {
                maxx1=-st[id*2].minn;
                minn1=-st[id*2].maxx;
        }
        if (st[id*2+1].change==0)
        {
                maxx2=st[id*2+1].maxx;
                minn2=st[id*2+1].minn;
        }
        else
        {
                maxx2=-st[id*2+1].minn;
                minn2=-st[id*2+1].maxx;
        }
        st[id].maxx=max(maxx1,maxx2);
        st[id].minn=min(minn1,minn2);
        st[id].change=0;
}
void change(int u,int w)
{
        while(1)
        {
                int cu=chain[u],cw=chain[w];
                if (cu==cw)
                {
                        update2(1,2,n,pos[w]+1,pos[u]);
                        break;
                }
                update2(1,2,n,pos[head[cu]],pos[u]);
                u=trc[head[cu]];
        }
}
int get(int id,int l,int r,int i,int j)
{
        if (l>j||r<i) return -oo;
        if (l>=i&&r<=j)
        {
                if (st[id].change==0)
                        return st[id].maxx;
                else return -st[id].minn;
        }
        down(id);
        int m=(l+r)>>1;
        int tmp1=get(id*2,l,m,i,j);
        int tmp2=get(id*2+1,m+1,r,i,j);
        int minn1,maxx1,minn2,maxx2;
        if (st[id*2].change==0)
        {
                maxx1=st[id*2].maxx;
                minn1=st[id*2].minn;
        }
        else
        {
                maxx1=-st[id*2].minn;
                minn1=-st[id*2].maxx;
        }
        if (st[id*2+1].change==0)
        {
                maxx2=st[id*2+1].maxx;
                minn2=st[id*2+1].minn;
        }
        else
        {
                maxx2=-st[id*2+1].minn;
                minn2=-st[id*2+1].maxx;
        }
        st[id].maxx=max(maxx1,maxx2);
        st[id].minn=min(minn1,minn2);
        st[id].change=0;
        return max(tmp1,tmp2);
}
void ques(int u,int w)
{
        while(1)
        {
                int cu=chain[u],cw=chain[w];
                if (cu==cw)
                {
                        res=max(res,get(1,2,n,pos[w]+1,pos[u]));
                        break;
                }
                res=max(res,get(1,2,n,pos[head[cu]],pos[u]));
                u=trc[head[cu]];
        }
}
int main()
{
        //freopen("D:\\C++\\debug\\QTREEX.inp","r",stdin);
        //freopen("D:\\C++\\debug\\QTREEX.out","w",stdout);
        int test;
        scanf("%d", &test);
        while(test--)
        {
                scanf("%d", &n);
                cnt=1;
                dem=0;
                memset(head,0,sizeof(head));
                for (int i=1; i<=n; i++)
                        e[i].clear();
                for (int i=1; i<n; i++)
                {
                        int u,v,val;
                        scanf("%d%d%d", &u, &v, &val);
                        e[u].push_back(v);
                        e[v].push_back(u);
                        c[u][v]=val;
                        c[v][u]=val;
                        id[u][v]=i;
                        id[v][u]=i;
                        dm[i]=II(u,v);
                }
                c[0][1]=-oo;
                c[1][0]=-oo;
                hld(1);
                build(1,2,n);
                char s[10];
                while(1)
                {
                        scanf("%s", s + 1);
                        if (s[1]=='D') break;
                        if (s[1]=='C')
                        {
                                int u,val;
                                scanf("%d%d", &u, &val);
                                if (dm[u].fs==trc[dm[u].sc])
                                        update1(1,2,n,pos[dm[u].sc],val);
                                else update1(1,2,n,pos[dm[u].fs],val);
                                continue;
                        }
                        if (s[1]=='N')
                        {
                                int u,v,w;
                                scanf("%d%d", &u, &v);
                                w=lca(u,v);
                                change(u,w);
                                change(v,w);
                                continue;
                        }
                        if (s[1]=='Q')
                        {
                                int u,v,w;
                                scanf("%d%d", &u, &v);
                                w=lca(u,v);
                                res=-oo;
                                ques(u,w);
                                ques(v,w);
                                if (res!=-oo) printf("%d\n", res);
                                else printf("%d\n", 0);
                        }
                }
        }
        return 0;
}
