#include<stdio.h>
#include<stdlib.h>

 int min(int x,int y){
    return(x>y)?y:x;
}
int main()
{
	int orate,drop=0,cap,x,count=0,inp[10]={0},i=0,nsec,ch;
	printf("\n enter bucket size : ");
	scanf("%d",&cap);
	printf("\n enter output rate : ");
	scanf("%d",&orate);
	do{
	printf(" \n enter number of packets coming at time %d second :  ",i+1);
	scanf("%d",&inp[i]);
	if(inp[i]>cap)
	{
		printf("Bucket overflow\n");
		printf("packet discarded \n");
		exit(0);
		}
	i++;
	printf("\n enter 1 to continue or 0 to quit : ");
	scanf("%d",&ch);
	}
	while(ch);
	nsec=i;
	printf("\nSecond\tRecieved\tSent\tDropped\tRemainder\n");
	for(
	i=0;count ||i<nsec;i++)
	{
	printf(" %d",i+1);
	printf("\t%d\t ",inp[i]);
	printf("\t%d",min((inp[i]+count),orate));
	if((x=inp[i]+count-orate)>0)
	{
		 if(x>cap)
		 {
		 	 count=cap;
		 	 drop =x-cap;
		}
		else
		{
			count=x;
			drop=0;
		}
		}
	else
	{
	drop=0;
	count=0;
	}
	printf("\t%d\t%d\n",drop,count);
	}
	return 0;
	}