#include <stdio.h>

int s_dzielnikow(int l)
{
    int s=0;
    for (int j=1;j<l;j++)
    {
        if (l%j==0)
            s += j;
    }
    return s;
}

void friends(int przedzial)
{
    int s_d,s_d2;
    for (int i=1;i<=przedzial;i++)
    {
        s_d = s_dzielnikow(i);
        s_d2 = s_dzielnikow(s_d);
        if (s_d2==i && i>s_d)
        {
            printf("friends: %d %d \n",i,s_d);
        }
    }
}

void doskonale(int przedzial)
{
    int s=0;
    for (int i=1;i<=przedzial;i++)
    {
        s=0;
        for (int j=1;j<i;j++)
        {
            if (i%j==0)
                s += j;
        }
        if (i==s)
            printf("found: %d\n",i);
    }
}

int main() {
    printf("Friends\n");
    friends(10000);
    printf("Doskonale\n");
    doskonale(10000);
    return 0;
}