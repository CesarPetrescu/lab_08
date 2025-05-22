#include <stdio.h>

#define MAX_LEN 100

static int get_max(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

static void counting_sort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int idx = (arr[i] / exp) % 10;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

static void radix_sort(int arr[], int n)
{
    int m = get_max(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        counting_sort(arr, n, exp);
}

static void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(void)
{
    int arr[MAX_LEN], len;

    printf("What's the length of the array? Maximum length is %d\n", MAX_LEN);
    scanf("%d", &len);

    printf("Gimme the %d elements\n", len);
    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);

    printf("Nonsorted array: ");
    print_array(arr, len);

    radix_sort(arr, len);

    printf("Sorted array: ");
    print_array(arr, len);

    return 0;
}
