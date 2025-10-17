#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4,5,6,7,8,9,10};
    int target = 10;
    int n = 10;
    int counter=0;
    for (int i = 0; i < n; i++)
    {
                counter++;
    cout<< "Counter: " << counter<<endl;

        if (arr[i] == target)
        {
            return 0;
        }
    }
    
}