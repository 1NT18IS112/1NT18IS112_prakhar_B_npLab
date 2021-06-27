#include <stdio.h>
#include <string.h>
int main()
{
    char a[20], b[30];
    printf("Enter frame :");
    scanf("%s", a);
    int n=strlen(a);
    int i=0,j=0,count,k=0;
    while (i < n)
    {
        if (a[i] == '0')
        {
            count=1;
            b[j++] = a[i];
            for (k = i + 1;(a[k]=='0') && (k < n) && (count < 4); k++)
            {
                b[j++] = a[k];
                count++;
                if (count == 4)
                {
                    b[j++] = '1';
                }
                i = k;
            }
        }
        else
        {
            b[j++] = a[i];
        }
        i++;
    }
    printf("After Bit Stuffing : ");
    for (i = 0; i < j; i++)
        printf("%c", b[i]);
    return 0;
}