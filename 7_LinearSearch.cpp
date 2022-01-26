#include <iostream>
using namespace std;

void linearSearch(int a[], int size, int element)
{

    int i;

    for (i = 0; i < size; i++)
    {
        if (a[i] == element)
        {
            cout << "Element found at " << i << endl;
            break;
        }
    }
    if (i == size)
        cout << "Element not found\n";
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

    linearSearch(a, n, element);

    return 0;
}