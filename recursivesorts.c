#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int temp[100];
    int i = low, j = mid + 1, k = low;

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

    for(i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int low, int high)
{
    int mid;

    if(low < high)
    {
        mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    int j, temp;

    for(j = low; j < high; j++)
    {
        if(a[j] < pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i+1];
    a[i+1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    int p;

    if(low < high)
    {
        p = partition(a, low, high);

        quickSort(a, low, p-1);
        quickSort(a, p+1, high);
    }
}

void display(int a[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int a[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    printf("Original array: ");
    display(a, n);

    mergeSort(a, 0, n-1);

    printf("After Merge Sort: ");
    display(a, n);

    return 0;
}