//divide and conquer approach!!11!1!
// splits unsorted array into smaller parts then merge the "sorted" arrays into a complete sorted array 
// has nlogn time complexity 


#include <iostream>

void merge(int a[], int left, int middle, int right) {
    // need temp arrays to store two halves of array
    int left_len = middle - left+1; 
    int right_len = right - middle; 

    // make temp arrays
    int left_temp[left_len];
    int right_temp[right_len];


    // copy elements from a[] to temp arrays 
    for (int i = 0; i < left_len; i++) {
        left_temp[i] = a[left+i]; 
    }

    for (int i = 0; i < right_len; i++) {
        right_temp[i] = a[middle+1+i];
    }


    // initialise index counters 
    int i = 0;
    int j = 0;

    for (int k = left; k <= right; k++) {
        if ((i < left_len) && (j >= right_len || left_temp[i] <= right_temp[j])) {
            a[k] = left_temp[i];
            i++; 
        } else {
            a[k] = right_temp[j]; 
            j++; 
        }
    }

}

// void mergeSort(int arr[], int length) {
//     mergeSortRecursion(arr, 0, length-1);
// };

void mergeSortRecursion(int array[], int left, int right) { // left: index of left most element of interest, right, index of right most 
    if (left < right) {
        int middle = left + (right-left) / 2; // the middle index 

        mergeSortRecursion(array, left, middle);
        mergeSortRecursion(array, middle+1, right);

        merge(array, left, middle, right);
    }

};



int main() {
    int array[] = {6,0,1,4,2,3,8,5,9,7};
    int length = 10; 

    mergeSortRecursion(array, 0, length-1);

    std::cout << "Sorted array : " << std::endl; 
    for (int i =0; i < length; i++) {
        std::cout << array[i] << " "; 
    }

    std::cout << std::endl; 


}