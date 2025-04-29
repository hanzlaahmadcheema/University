/*
In C++, resizing an array directly is not possible because arrays have a fixed size once they are created. 
However, there are several approaches to achieving similar functionality:

Using std::vector: This is the most common and flexible way to handle dynamic arrays in C++. std::vector 
can resize itself automatically when elements are added or removed.

Manually resizing using new and delete: If you need to resize a raw array, you can allocate a new array with
 the desired size, copy the contents from the old array, and then delete the old array.

Using smart pointers and dynamic memory allocation: A similar approach to raw pointers but with smart pointers, 
which can help avoid memory leaks.
*/

#include <iostream>
using namespace std;
#include <vector>

int main() {
   vector<int> arr = {1, 2, 3, 4, 5};  // Initial size is 5
    arr.push_back(6);  // Increases the size automatically
    arr.resize(0);    // Resizes to 10, fills new elements with default value (0 for int)

    for (int i : arr) {
       cout << i << " ";
    }
    return 0;
}
