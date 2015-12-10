#include <stdio.h>
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int a,b,c;
    scanf("%d %d",&a ,&b);
    c=gcd(a,b);
    printf("Your gcd is :%d",c);
    return 0;
}
