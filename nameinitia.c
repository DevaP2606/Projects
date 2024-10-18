#include <stdio.h>

int main(){
    char arr[100];
    fgets(arr, sizeof(arr), stdin);
    int count=0;


    for (int i = 0; arr[i]!='\0'; i++)
    {   
        if(arr[i]==' ') 
          {
            count++;
          }

    }
    
    for (int i = 0; arr[i]!='\0'; i++)
    {
        if (i==0)
        {
            printf("%c",arr[0]);
        }
        if(count==0)
        {
            printf("%c",arr[i]);
        }
        if (arr[i]==' ')
        {
            printf(".%c",arr[i+1]);
            i++;
            count--;

        }
      
    }
    
    
    return 0;
}