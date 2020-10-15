#include <iostream>
#include<stdio.h>

//将有二个有序子数组a[begin...mid]和a[mid+1...end]合并。
void MergeArray(int a[],int begin,int mid,int end,int temp[])
{
    int i=begin,j=mid+1;
    int m=mid,n=end;
    int k=0;

    while(i<=m && j<=n)
    {
        if(a[i]<=a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=m)
        temp[k++]=a[i++];
    while(j<=n)
        temp[k++]=a[j++];

    //把temp数组中的结果装回a数组
    for(i=0;i<k;i++)
        a[begin+i]=temp[i];
}

void mergesort(int a[],int begin,int end,int temp[])
{
    if(begin<end)
    {
        int mid = (begin+end)/2;
        mergesort(a,begin,mid,temp);   //左边有序
        mergesort(a,mid+1,end,temp);   //右边有序
        MergeArray(a,begin,mid,end,temp); //将左右两边有序的数组合并
    }
}
int main()
{
    int num[10]={2,5,9,3,6,1,0,7,4,8};
    int temp[10];
    mergesort(num,0,9,temp);
    for(int i=0;i<10;i++)
    {
        printf("%d",num[i]);
    }
    printf("\n");
}

