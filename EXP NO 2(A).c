#include<stdio.h>
int ls(int arr[],int size,int key)
{
	for (int i=0;i<size;i++)
	{
		if (arr[i]=key)
		return i;
		else
}
return -1;
	}
int main()
{
	int n,key,position;
	printf("Enter the number of elements\t:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter %d elements\n:",n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to search:");
	scanf("%d",&key);
	position=ls(arr,n,key);
	if (position==-1)
	{
	printf("Element %d not found in the array.\n",key);	
	}
	else
	{
		printf("Element %d found at position(index%d).\n",key,position+1,position);
	}
	return 0;
}
