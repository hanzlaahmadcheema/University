/*Merge sort is a divide-and-conquer sorting algorithm that divides the array into smaller parts, sorts them, and then merges them back together in sorted order. This recursive approach makes it much more efficient than simple algorithms like bubble sort or insertion sort, especially for large datasets.

Steps of Merge Sort
Divide the array into two halves until each subarray contains only one element (since a single element is trivially sorted).
Conquer by recursively sorting each half.
Combine the two sorted halves by merging them into a single sorted array.
Example
Suppose we want to sort the array [38, 27, 43, 3, 9, 82, 10] using merge sort.

Initial Array: [38, 27, 43, 3, 9, 82, 10]
Divide Step:
Split into two halves: [38, 27, 43] and [3, 9, 82, 10]
Recursive Division:
Split [38, 27, 43] into [38] and [27, 43]
Split [27, 43] into [27] and [43]
Merge [27] and [43] to get [27, 43]
Merge [38] and [27, 43] to get [27, 38, 43]
Split [3, 9, 82, 10] into [3, 9] and [82, 10]
Split [3, 9] into [3] and [9]
Merge [3] and [9] to get [3, 9]
Split [82, 10] into [82] and [10]
Merge [82] and [10] to get [10, 82]
Merge [3, 9] and [10, 82] to get [3, 9, 10, 82]
Merge the Final Halves:
Merge [27, 38, 43] and [3, 9, 10, 82] to get [3, 9, 10, 27, 38, 43, 82]
The sorted array is [3, 9, 10, 27, 38, 43, 82].

Complexity
Time Complexity: 

O(nlogn) for all cases (worst, average, and best). This efficiency comes from repeatedly splitting the array (logarithmic) and merging (linear).
Space Complexity: 

O(n), as it requires additional space for merging arrays.
Key Points
Merge sort is efficient for large datasets and guarantees 

O(nlogn) performance.
It is stable (preserves the order of equal elements).
It is not in-place; it requires additional memory for merging, which makes it less space-efficient than some other sorts.*/