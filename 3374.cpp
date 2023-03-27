#include<bits/stdc++.h>
using namespace std;
int n,m;
inline int read()
{
    int x=0,f=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c&15); c=getchar();}
    return x*f;
}
int a[500005];
void add(int x,int y)
{
    for(int i=x;i<=n;i+=i&-i) a[i]+=y;
}
int ask(int l,int r)
{
    if(l>r) return 0;
    int ans=0;
    for(int i=r;i;i-=i&-i) ans+=a[i];
    for(int i=l-1;i;i-=i&-i) ans-=a[i];
    return ans;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        add(i,read());
    }
    for(int i=1;i<=m;i++)
    {
        int opt=read(),x=read(),y=read();
        //printf("!\n");
        if(opt==1)
        {
            add(x,y);
        }
        else
        {
            printf("%d\n",ask(x,y));
        }
        
    }
    return 0;
}