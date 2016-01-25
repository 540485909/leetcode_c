#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 102
int main()
{
    int a[M][M];

    int test_case=1;
    int n;
    while(scanf("%d",&n)&&n>0)
    {
        int cou=1;
        memset(a,0,sizeof(a));

          int i,j,k;

           for(i=0;i<n;++i){
                k=i;
                for(j=0;j<=i;++j){
                    a[k--][j]=cou++;
                }
            }
        printf("Case %d:\n",test_case++);
        for(i=0;i<n;++i){
            for(j=0;j<n-i;++j){
                if(j==0){
                    printf("%d",a[i][j]);
                }else{
                     printf(" %d",a[i][j]);
                }
            }

            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
