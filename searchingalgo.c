#include <stdio.h>

int linearSearch(int a[], int n, int key)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(a[i] == key)
            return i;
    }

    return -1;
}

int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n-1, mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == key)
            return mid;
        else if(a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 30;
    int pos;

    pos = linearSearch(a, n, key);

    if(pos != -1)
        printf("Linear Search: Element found at index %d\n", pos);
    else
        printf("Element not found\n");

    pos = binarySearch(a, n, key);

    if(pos != -1)
        printf("Binary Search: Element found at index %d\n", pos);
    else
        printf("Element not found\n");

    return 0;
}