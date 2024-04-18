#include<cstdio>
#include<iostream>
const int M=1500;
int n;
double f[M][M];
int main()
{
    scanf("%d",&n);
        n>>=1;
    for (int i=2;i<=n;i++)
        f[i][0]=1,f[0][i]=1; 
    for (int i=1;i<=n;i++)
        for (int k=1;k<=n;k++)
            f[i][k]=f[i-1][k]*0.5+f[i][k-1]*0.5;
    printf("%.10lf",f[n][n]);
    return 0;
}