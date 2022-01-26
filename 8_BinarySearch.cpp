#include <iostream>
using namespace std;

int binarySearch(int a[], int size, int element)
{
    int first = 0, last = size - 1;
    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (a[mid] == element)
            return mid;
        else if (a[mid] < element)
            first = mid + 1;
        else
            last = mid - 1;
    }

    return -1;
}

int main()
{
    int n, element, *a;

    cout << "Enter size of array : ";
    cin >> n;

    a = new int[n];

    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter element to search : ";
    cin >> element;

    int output = binarySearch(a, n, element);

    if (output == -1)
        cout << "Element not found\n";
    else
        cout << "Element found at " << output << endl;
    return 0;
}