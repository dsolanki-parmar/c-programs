#include<stdio.h>
#define MAX 20

void printarray(int a[],int n);
void merge(int a[],int low, int mid, int high)
{
    int temp1[MAX];
    int temp2[MAX];
    int n1 = mid - low +1;
    int n2 = high - mid ;
    int i = 0, j = 0, k = low;
    for (i = 0;i<n1;i++)
	{
	    temp1[i] = a[i+low];
	}
    for (i = 0;i<n2;i++)
	{
	    temp2[i] = a[i+mid+1];
	}
    for(i=0,j=0;i<n1 && j <n2;k++)
	{
	    if(temp1[i] > temp2[j]) {
		a[k]=temp2[j++];
	    }
	    else {
		a[k] = temp1[i++];
	    }
	}
    while(i<n1) {
	a[k++] = temp1[i++];
    }

        while(j<n2) {
	a[k++] = temp2[j++];
    }

	printarray(a,k);
}
void mergesort(int a[], int low, int high)
{
    int mid = 0;
    if(low < high) {
	mid = low + (high - low) /2;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,high);
    }
}

void swap(int *a, int *b)
{int temp = *a ;
    *a = *b;
    *b = temp;
}
int partition(int a[], int low, int high)
{
    int left = low - 1;
    int right = high;
    int partition = high;
    while(left <right) {
	while(a[++left] < a[partition] && left < high);
	while(a[--right] > a[partition] && right > 0);
	if (left < right) {
	    swap(&a[left],&a[right]);
	}
    }
    swap(&a[partition], &a[left]);
    printarray(a,high);
    return left;
    
}
void quicksort(int a[], int low, int high)
{
    int index = 0;
    if(low<high)
    {
	index = partition (a,low,high);
	quicksort(a,low, index-1);
	quicksort(a,index+1,high);
    }
}

void heapify(int a[], int high, int index)
{
    int l= 2*index +1;
    int r = 2*index +2;
    int largest = index;
    if(a[largest] < a[l] && l < high) {
	largest = l;
    }

    if(a[largest] < a[r] && r <high) {
	largest  = r;
    }
    if(largest != index) {
	swap(&a[largest],&a[index]);
	heapify(a,high,largest);
    }
    printarray(a,high);    
}
void heapsort(int a[], int low, int high)
{ int node = high/2 - 1;
    int max = high;
    while(node>=0){

	heapify(a,high,node);
	node--; 
    }

    while(max>0) {
    /* put first at the end */
	max--;
	swap(&a[0],&a[max]);
	heapify(a,max,0);
    }

}
void printarray(int a[],int n)
{
    int i = 0;
    for(i=0;i<n;i++)
	{
	    printf("%d\t",a[i]);
	}
    printf("Done\n");
}
    
void main()

{

    int a[] = {3,56,89,11,2,23,4};
    int n = sizeof(a)/ sizeof(a[0]);

    //    mergesort(a,0,n-1);
    //       quicksort(a,0,n-1);
    heapsort(a,0,n);
    printarray(a,n);
}
