#include <iostream>
using namespace std;

int main()
{
    int arr[] = {6, 2, 55, 10, 6};
    int n = 5;
    int target = 12;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << i << "(" << arr[i] << ") " << j << "(" << arr[j] << ")" << endl;
            }
        }
    }
    return 0;
}