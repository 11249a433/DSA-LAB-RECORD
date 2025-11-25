#include<stdio.h>
int binarysearch (int arr[],int size,int target)
{
int low=0;
int high=size-1;
while(low<=high)
{
int mid=low+(high-low)/2;
if (arr[mid]==target)
{
return mid;
}
else if (arr[mid]<target)
{
low=mid+1;
}
else
{
high=mid-1;
}
}
return -1;
}
int main()
{
int arr[]={10,20,30,40,50,60,70,80,90,100};
int size=sizeof (arr)/sizeof (arr[0]);
int target=70;
int result=binarysearch(arr,size,target);
if(result!=-1)
{
printf("element %d found at index %d.\n",target,result);
}
else
{
printf("element %d not found in the array.\n",target);
}
return 0;
}


