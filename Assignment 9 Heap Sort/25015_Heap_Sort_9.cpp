/*
Name : Daphal Chaitanya Ramdas
Class : SE IT
Div : A
Batch : A
Roll no. : 25015
Assignment No. 9 : Heap Sort
*/

#include <iostream>
using namespace std;

void MaxHeapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;

    while (j <= n)
    {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
    return;
}
void HeapSort(int a[], int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        MaxHeapify(a, 1, i - 1);
    }
}
void Build_MaxHeap(int a[], int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
        MaxHeapify(a, i, n);
}
int main()
{
    int n, i;
    cout << "\nEnter the number of data element to be sorted: ";
    cin >> n;
    n++;
    int arr[n];
    for (i = 1; i < n; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }

    Build_MaxHeap(arr, n - 1);
    HeapSort(arr, n - 1);

    cout << "\nSorted Data ";

    for (i = 1; i < n; i++)
        cout << " -> " << arr[i];

    return 0;
}

/*
OUTPUT :

Enter the number of data element to be sorted: 5
Enter element 1: 96
Enter element 2: 87
Enter element 3: 24
Enter element 4: 86
Enter element 5: 76

Sorted Data  -> 24 -> 76 -> 86 -> 87 -> 96
*/