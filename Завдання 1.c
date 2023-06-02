#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Введіть розмір масиву: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int min = a[0]; // Початкове припущення про мінімальний елемент
    int sum = 0;    // Початкове значення суми елементів

    int *first_neg = 0;  // Покажчик на перший від'ємний елемент
    int *second_neg = 0; // Покажчик на другий від'ємний елемент

    // Знаходимо мінімальний за модулем елемент
    for (int i = 0; i < n; i++)
    {
        if (abs(a[i]) < abs(min))
        {
            min = a[i];
        }
    }

    printf("Мінімальний за модулем елемент: %d\n", min);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            if (first_neg == 0)
            {
                first_neg = &a[i];
            }
            else if (second_neg == 0)
            {
                second_neg = &a[i];
                break; // Зупиняємо цикл, якщо знайдено обидва від'ємних елементи
            }
        }
        else
        {
            printf("Сума елементів між першим та другим від'ємними елементами не може бути вичисленою.");
            return 0;
        }
    }

    if (first_neg != 0 && second_neg != 0)
    {
        // Обчислюємо суму елементів між першим та другим від'ємними елементами
        int *start = first_neg + 1;
        int *end = second_neg;
        for (int *ptr = start; ptr < end; ptr++)
        {
            sum += *ptr;
        }
    }
    printf("Сума елементів між першим та другим від'ємними елементами: %d\n", sum);

    free(a);

    return 0;
}
