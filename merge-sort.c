#include <stdio.h>
#include <math.h>

void print_array(int arr[], int length)
{
    printf("[");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void merge(int left[], int right[], int left_length, int right_length)
{
    int combined_length = left_length + right_length;
    int temp[combined_length];
    int* p = temp;

    int* left_end = left + left_length;
    int* right_end = right + right_length;

    int* sorted_base = left;

    while (left < left_end || right < right_end)
    {
        if (left < left_end && (*left <= *right || right == right_end))
        {
            *p = *left;
            left = left + 1;
        }
        else if (right < right_end && (*right < *left || left == left_end))
        {
            *p = *right;
            right = right + 1;
        }
        p++;
    }

    // Replace the left and right with temp which is sorted.
    for (int i = 0; i < combined_length; i++)
    {
        sorted_base[i] = temp[i];
    } 
}

void sort(int arr[], int arr_length)
{
    if (arr_length <= 1) return;

    int middle = floor(arr_length / 2);
    
    sort(arr, middle);
    sort(arr + middle, arr_length - middle);
    
    merge(arr, arr + middle, middle, arr_length - middle);
}

int main()
{
    //int arr[] = {5, 4,-2, 8, 1};
    int arr[] = {1, 5, 2, 3};
    int arr_size = sizeof(arr)/sizeof(int);
    
    print_array(arr, arr_size);
    sort(arr, arr_size);
    //merge(arr, arr + 2, 2, 2);
    print_array(arr, arr_size);

    return 0;
}
