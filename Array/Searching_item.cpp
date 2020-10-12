#include <bits/stdc++.h>
using namespace std;
 
// function to search an element in
// minimum number of comparisons
int search(int arr[], int n, int x)
{
    // 1st comparison
    if (arr[n - 1] == x)
        return n-1;
 
    int backup = arr[n - 1];
    arr[n - 1] = x;
 
    // no termination condition and thus
    // no comparison
    for (int i = 0;; i++) {
        // this would be executed at-most n times
        // and therefore at-most n comparisons
        if (arr[i] == x) {
            // replace arr[n-1] with its actual element
            // as in original 'arr[]'
            arr[n - 1] = backup;
 
            // if 'x' is found before the '(n-1)th'
            // index, then it is present in the array
            // final comparison
            if (i < n - 1)
                return i;
 
            // else not present in the array
            return -1;
        }
    }
}
 
// Driver program to test above
int main()
{
    int arr[] = { 4, 6, 1, 5, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 1;
    cout << search(arr, n, x);
    return 0;
}

