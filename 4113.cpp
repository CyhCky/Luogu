#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+(c&15); c=getchar();}
    return x*f;
}
int a[2000005],t[2000005],nex[2000005],col_las[2000005],fir[2000005];
void add(int x,int n,int k)
{
    for(;x<=n;x+=(-x&x)) t[x]+=k;
}
int ask(int x)
{
    int ans=0;
    //printf("!\n");
    for(;x;x-=(-x&x)) ans+=t[x];
    return ans;
}
struct init
{
    int l,r,id,ans;
}b[2000005];
bool cmp1 (init x,init y)
{
    return x.l<y.l;
}
bool cmp2 (init x,init y)
{
    return x.id<y.id;
}
int main()
{
    int n=read(),c=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        if(!fir[a[i]]) fir[a[i]]=i;
        if(col_las[a[i]]) nex[col_las[a[i]]]=i;
        col_las[a[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        b[i].l=read(); b[i].r=read(); b[i].id=i;
    }
    sort(b+1,b+m+1,cmp1); 
    for(int i=1;i<=c;i++) if(fir[i]&&nex[fir[i]]) add(nex[fir[i]],n,1);
    int cnt=1;
    for(int i=1;i<=m;i++)
    {
        for(;cnt<b[i].l;cnt++)
        {
            if(nex[nex[cnt]]&&nex[cnt]) add(nex[nex[cnt]],n,1);//printf("!\n");
            if(nex[cnt]) add(nex[cnt],n,-1);
        }
        b[i].ans=ask(b[i].r)-ask(b[i].l-1);
        //if(b[i].l>=b[i].r) b[i].ans=0;
    }
    sort(b+1,b+m+1,cmp2);
    for(int i=1;i<=m;i++) printf("%d\n",b[i].ans);
    return 0;
}
