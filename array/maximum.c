#include<stdio.h>
int main()
{
    int m,max,min;
    printf("enter the size of array:");
    scanf("%d",&m);
    int a[m];
    printf("Enter the elements of array:\n");
    for(int i=0;i<m;i++)
    { 
        scanf("%d",&a[i]);
    }
    printf("Array elements are:\n");
    for(int l=0;l<m;l++){
        printf("%d\t",a[l]);
    }
    printf("\n");
    max=min=a[0];
    for(int j=1;j<m;j++)
{
    if (a[j]>max)
    {
        max=a[j];
    }
}
    printf("MAXIMUM VALUE IS: %d\n",max);
    min=max;
    for(int k=0;k<m;k++)
    {
        if (min>a[k])
        {
            min=a[k];
        }
    }
    printf("MINIMUM VALUE IS: %d",min);

return 0;
}
