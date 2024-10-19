#include <stdio.h>

int main()
{
    int n;
    int temp;
    printf("Enter length of array:");
    scanf("%d",&n);
   int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("elemet %d:",i+1);
        scanf("%d", &arr[i]);
    }
    
    printf("Enter repeations: ");
    int r;
    scanf("%d",&r);

    for (int j = 0; j < r; j++)
    {

        temp = arr[n-1];
        for (int i = n - 2; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[0] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}