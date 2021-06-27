#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void division(char *p, char *t, int dlen, int plen)
{
    for (int i = 0; i < dlen; i++)
    {
        if (p[0] == t[i])
        {
            for (int j = 0, k = i; j < plen; j++, k++)
                if (t[k] == p[j])
                    t[k] = '0';
                else
                    t[k] = '1';
        }
    }
}
int main()
{
    char dataS[50], dataR[50], polynomial[50], temp[50];
    printf("SENDER SIDE\n\n");
    printf("Enter the data to Send: ");
    scanf("%s", dataS);
    printf("Enter the polynomial: ");
    scanf("%s", polynomial);
    int dlen = strlen(dataS);
    int plen = strlen(polynomial);
    //appending zeroes to data
    for (int i = 0; i < dlen; i++)
        temp[i] = dataS[i];
    for (int i = 0; i < plen - 1; i++)
        temp[dlen + i] = '0';
    printf("\nData after appending zeroes: ");
    for (int i = 0; i < dlen + plen - 1; i++)
        printf("%c", temp[i]);
    division(polynomial, temp, dlen, plen);
    printf("\nCRC : ");
    for (int i = 0; i < plen - 1; i++)
    {
        printf("%c ", temp[dlen + i]);
        dataS[dlen + i] = temp[dlen + i];
    }
    printf("\nTransmitted Message : %s\n\n", dataS);
    printf("RECIEVER SIDE\n\n");
    printf("Enter data recieved: ");
    scanf("%s", dataR);
    strcpy(temp, dataR);
    division(polynomial, temp, dlen, plen);
    printf("\nCRC : ");
    int flag = 0;
    for (int i = 0; i < plen - 1; i++)
    {
        if (temp[dlen + i] == '1')
        {
            flag = 1;
        }
        printf("%c ", temp[dlen + i]);
        dataS[dlen + i] = temp[dlen + i];
    }

    if (flag)
    {
        printf("\nWrong data recieved\n");
    }
    else
    {
        printf("\nNo error in the data\n");
    }

    return 0;
}