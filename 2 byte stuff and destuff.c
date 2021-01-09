#include <stdio.h>
#include <string.h>

int main()
{
    char data[50],dstuff[50];
    int i,j,k,loop;
    printf("Enter data: \n");
    scanf("%s",&data);
     j= strlen(data);
    printf("Data after Stuffing: \n");
    for(i=0;i<j;i++)
    {
    	if(data[i] == 'e' || data[i] == 'f')
    	{
    		printf("e");
    		printf("%c",data[i]);
    
    	}
    	else
    	{
    		printf("%c",data[i]);
		}
	}
    k=0;
    for(i=0;i<loop;i++)
    {
    	if(data[i] != 'e' || data[i] != 'f')
    	{
    		dstuff[k]=data[i];
    		k++;
		}
	}
    printf("\n destuffed data is : %s ",dstuff);
    return 0;
}
