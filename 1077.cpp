#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+(c&15); c=getchar();}
    return x*f;
}
const int Mod=1000007;
int a[105],f[105][10005];
int main()
{
    int n=read(),m=read(),sum=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        sum+=a[i];
    }
    int t=sum-m;
    for(int i=min(a[1],t);i>=0;i--)
    {
        f[1][i]=1;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=t;j++)
        {
            for(int k=0;k<=min(a[i],j);k++)
            {
                f[i][j]=(f[i][j]+f[i-1][j-k])%Mod;
            }
            
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=0;j<=t;j++)
    //     {
    //         printf("f[%d][%d]=%d\n",i,j,f[i][j]);
    //     }
    // }
    printf("%d",f[n][t]);
    return 0;
}