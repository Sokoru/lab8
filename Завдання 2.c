#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputArray(int *arr, int size)
{
    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void outputArray(int *arr, int size)
{
    printf("Елементи масиву:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sumOfElementsWithOddIndexes(int *arr, int size)
{
    int sum = 0;
    for (int i = 1; i < size; i += 2)
    {
        sum += arr[i];
    }
    return sum;
}

int productOfElementsBetweenNegatives(int *arr, int size)
{
    int product = 1;
    int first_negative_index = -1;
    int last_negative_index = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            if (first_negative_index == -1)
            {
                first_negative_index = i;
            }
            last_negative_index = i;
        }
    }
    if (first_negative_index != -1 && last_negative_index != -1 && first_negative_index < last_negative_index)
    {
        for (int i = first_negative_index + 1; i < last_negative_index; i++)
        {
            product *= arr[i];
        }
    }
    else
    {
        product = 0;
    }
    return product;
}
int check_negatives(int *arr, int size)
{
    if (arr[0] >= 0 || arr[size - 1] >= 0)
    {
        printf("Добуток елементів між першим та останнім від'ємними елементами не може бути вичислений.\n");
        return 0;
    }
    return 1;
}

int main()
{
    srand(time(0));

    int n;
    printf("Введіть розмір масиву: ");
    scanf("%d", &n);

    int *array = (int *)malloc(n * sizeof(int));

    if (array == 0)
    {
        printf("Помилка виділення пам'яті\n");
        return 1;
    }

    inputArray(array, n);
    outputArray(array, n);

    int sum = sumOfElementsWithOddIndexes(array, n);
    printf("Сума елементів з непарними номерами: %d\n", sum);

    if (!check_negatives(array, n))
    {
        return 0;
    }
    int product = productOfElementsBetweenNegatives(array, n);
    if (product == 0)
    {
        printf("Добуток елементів між першим та останнім від'ємними елементами не може бути вичислений.\n");
    }
    else
    {
        printf("Добуток елементів між першим та останнім від'ємними елементами: %d\n", product);
    }

    free(array);

    return 0;
}
