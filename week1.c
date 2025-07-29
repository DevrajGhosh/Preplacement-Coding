// 1. Insert an element at end of array
#include <stdio.h>

void insertAtEnd(int arr[], int n, int val) {
    arr[n] = val;
    for (int i = 0; i <= n; i++) printf("%d ", arr[i]);
}

int main() {
    int arr[100], n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &val);
    insertAtEnd(arr, n, val);
    return 0;
}



//2. Find largest element in array
#include <stdio.h>

int findLargest(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    return max;
}

int main() {
    int arr[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d", findLargest(arr, n));
    return 0;
}

//3. Find second largest element
#include <stdio.h>
#include <limits.h>

int findSecondLargest(int arr[], int n) {
    int lg = INT_MIN, sl = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > lg) {
            sl = lg;
            lg = arr[i];
        } else if (arr[i] > sl && arr[i] != lg) {
            sl = arr[i];
        }
    }
    return sl == INT_MIN ? -1 : sl;
}

int main() {
    int arr[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("%d", findSecondLargest(arr, n));
    return 0;
}


//4. Move all zeros to end
#include <stdio.h>

void pushZerosToEnd(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[count] = arr[i];
            count++;
        }
    }
    while (count < n) {
        arr[count] = 0;
        count++;
    }
}

int main() {
    int arr[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    pushZerosToEnd(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

//5. Rotate array by one
#include <stdio.h>

void rotate(int arr[], int n) {
    int last = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = last;
}

int main() {
    int arr[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    rotate(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

//6. Check if array is sorted
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool isSorted(int arr[], int n) {
    int brr[100];
    for (int i = 0; i < n; i++) {
        brr[i] = arr[i];
    }
    qsort(brr, n, sizeof(int), compare);
    for (int i = 0; i < n; i++) {
        if (arr[i] != brr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (isSorted(arr, n)) {
        printf("Sorted\n");
    } else {
        printf("Not sorted\n");
    }
    return 0;
}

//7. Reverse a string
#include <stdio.h>
#include <string.h>

char* reverseString(char* s) {
    int n = strlen(s);
    char brr[1000];
    for (int i = 0; i < n; i++) {
        brr[i] = s[n - 1 - i];
    }
    brr[n] = '\0';
    strcpy(s, brr);
    return s;
}

int main() {
    char s[1000];
    scanf("%s", s);
    reverseString(s);
    printf("%s\n", s);
    return 0;
}

//8. Check if string is palindrome
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(const char* s) {
    int i = 0;
    int j = strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    char s[1000];
    scanf("%s", s);
    if (isPalindrome(s)) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }
    return 0;
}

//9. Count frequency of array elements (1 to n)
#include <stdio.h>

void frequencyCount(int arr[], int n, int freq[]) {
    for (int i = 0; i < n; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 1 && arr[i] <= n) {
            freq[arr[i] - 1]++;
        }
    }
}

int main() {
    int arr[100], freq[100], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    frequencyCount(arr, n, freq);
    for (int i = 0; i < n; i++) {
        printf("%d ", freq[i]);
    }
    return 0;
}

//10. reverse an array
#include <stdio.h>

void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    reverseArray(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
