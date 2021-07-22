#include <bits/stdc++.h>
using namespace std;
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
void insertHeap(int a[], int i)
{
    int temp = a[i];
    while (i > 0)
    {
        if (temp > a[(i + 1) / 2 - 1])
        {
            a[i] = a[(i + 1) / 2 - 1];
            i = (i + 1) / 2 - 1;
        }
        else
            break;
    }
    a[i] = temp;
}
int del(int a[], int n)
{
    int val = a[0];
    //cout<<val <<" <-- val "<<endl;
    a[0] = a[n - 1];
    int i = 0;
    int j = 2 * i + 1;
    while (j < n)
    {
        if (j < n - 1 && a[j] < a[j + 1])
        {
            j = j + 1;
        }
        if (a[i] < a[j])
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = j;
            j = 2 * j + 1;
        }
        else
            break;
    }
    a[n - 1] = val;
    return val;
}
void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[largest] < a[l])
    {
        largest = l;
    }
    if (r < n && a[largest] < a[r])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}
main()
{
    int a[] = {0, 45, 36, 14, 39, 53, 18, 27};
    int n = sizeof(a) / sizeof(int);
    // print(a, n);
    cout << n << endl;
    cout << "After inserting in Heap" << endl;
    // for (int i = 1; i < n; i++)
    //     insertHeap(a, i);
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    print(a,n);
    for(int i =n-1;i>=0;i--){
        swap(a[i],a[0]);
        heapify(a,i,0);
        
    }
    // print(a, n);
    // for (int i = n; i > 0; i--)
    // {
    //     int delete_key = del(a, i);
    //     cout << delete_key << endl;
    // }
    print(a, n);
}