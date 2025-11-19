#include <iostream>
using namespace std;

int main()
{
    int arr[] = {5, 2, 9, 1, 6};
    int n = 5;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    cout << "Sum: " << sum << endl;
    return 0;
}
