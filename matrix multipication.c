#include <stdio.h>
int matrix_multiply(int n,int a[n][n],int b[n][n],int mat[n][n])
{
    int i;
    for(i=0;i<n;i++)
    {
        int j;
        for(j=0;j<n;j++)
        {
            int k;
            int sum=0;
            for(k=0;k<n;k++)
                sum+=a[i][k]*b[k][j];
            mat[i][j]=sum;
        }
    }
}
void print(int n,int mat[n][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }
}
int main()
{
    int a[3][3]={{1,1,1},{1,1,1},{1,1,1}};
    int b[3][3]={{1,1,1},{1,1,1},{1,1,1}};
    int mat[3][3]={{1,1,1},{1,1,1},{1,1,1}};
    matrix_multiply(3,a,b,mat);
    print(3,mat);
    return 0;
}
