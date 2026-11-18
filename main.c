#include <stdio.h>
#include "myarrfunc.h"

#define MAX 100

int main(void)
{
    int arr[MAX] = {0};
    size_t idx[MAX];
    size_t n = 0;
    char c;
    int val, k, m, res, r;
    size_t cnt, i;

    while (1) {
        printf("\na Задать размер массива\n"
               "b Заполнить массив\n"
               "c Представление массива (значения, адреса)\n"
               "d Минимальное значение в диапазоне индексов k-m\n"
               "e Значение последнего отрицательного элемента\n"
               "f Сумма элементов выше заданного k\n"
               "g Сумма элементов ниже заданного k\n"
               "h Индексы элементов ниже среднего значения\n"
               "i Выход\n"
               "Выберите пункт: ");

        if (scanf(" %c", &c) != 1)
            break;

        if (c == 'i')
            break;

        if (c == 'a') {
            printf("Размер массива (1-%d): ", MAX);
            r = scanf("%d", &val);
            if (r == EOF)
                break;
            if (r != 1) {
                scanf("%*s");
                printf("Ошибка ввода\n");
                continue;
            }
            if (val <= 0 || val > MAX) {
                printf("Размер должен быть от 1 до %d\n", MAX);
                continue;
            }
            n = val;
            continue;
        }

        if (c < 'b' || c > 'h') {
            printf("Неверный пункт меню\n");
            continue;
        }

        if (n == 0) {
            printf("Сначала задайте размер массива (пункт a)\n");
            continue;
        }

        switch (c) {
        case 'b':
            if (arr_fill(arr, n) != 0) {
                scanf("%*s");
                printf("Ошибка ввода\n");
            }
            break;
        case 'c':
            arr_print(arr, n);
            break;
        case 'd':
            printf("Введите k и m: ");
            r = scanf("%d %d", &k, &m);
            if (r == EOF)
                return 0;
            if (r != 2) {
                scanf("%*s");
                printf("Ошибка ввода\n");
                break;
            }
            if (k < 0 || m < 0 ||
                arr_min_range(arr, n, k, m, &res) != 0)
                printf("Неверный диапазон индексов\n");
            else
                printf("Минимум: %d\n", res);
            break;
        case 'e':
            if (arr_last_negative(arr, n, &res) != 0)
                printf("Отрицательных элементов нет\n");
            else
                printf("Последний отрицательный: %d\n", res);
            break;
        case 'f':
        case 'g':
            printf("Введите k: ");
            r = scanf("%d", &k);
            if (r == EOF)
                return 0;
            if (r != 1) {
                scanf("%*s");
                printf("Ошибка ввода\n");
                break;
            }
            if (c == 'f')
                printf("Сумма: %d\n", arr_sum_above(arr, n, k));
            else
                printf("Сумма: %d\n", arr_sum_below(arr, n, k));
            break;
        case 'h':
            cnt = arr_idx_below_avg(arr, n, idx);
            if (cnt == 0) {
                printf("Таких элементов нет\n");
            } else {
                printf("Индексы:");
                for (i = 0; i < cnt; i++)
                    printf(" %zu", *(idx + i));
                printf("\n");
            }
            break;
        }
    }

    return 0;
}