//interval search in a sorted array
#include <iostream>
using namespace ::std;

int binarySearch(int arr[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int num;
    int arr[10];
    int output;
    cout << "enter 10 integers in ascending order\n";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    cout << "enter number to search: ";
    cin >> num;
    output = binarySearch(arr, 0, 9, num);
    if (output == -1)
    {
        cout << "no match found\n";
    }
    else
    {
        cout << "match found at index position: " << output;
    }
    return 0;
}
