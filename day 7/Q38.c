 #include <stdio.h>

int main()
{
    int arr[100];
    int size;
    int start, end;
    int temp;
    int i; 
    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter array:\n"); 
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    start = 0;
    end = size - 1;

    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    printf("Reversed array: ");

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    return 0;
}  
      