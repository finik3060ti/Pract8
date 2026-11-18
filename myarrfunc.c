#include <stdio.h>
#include "myarrfunc.h"

/* Заполнение массива с клавиатуры. 0 - успех, -1 - ошибка ввода */
int arr_fill(int *arrptr, size_t n)
{
    int *p;
    for (p = arrptr; p < arrptr + n; p++) {
        printf("Элемент %zu: ", (size_t)(p - arrptr));
        if (scanf("%d", p) != 1)
            return -1;
    }
    return 0;
}

/* Вывод значений и адресов элементов */
void arr_print(int *arrptr, size_t n)
{
    int *p;
    for (p = arrptr; p < arrptr + n; p++)
        printf("[%zu] значение = %d, адрес = %p\n",
               (size_t)(p - arrptr), *p, (void *)p);
}

/* №3. Минимум в диапазоне индексов k-m.
   Возвращает 0 и пишет результат в *res, либо -1 при неверном диапазоне */
int arr_min_range(int *arrptr, size_t n, size_t k, size_t m, int *res)
{
    int *p;
    int min;
    if (k > m || m >= n)
        return -1;

    min = *(arrptr + k);
    for (p = arrptr + k; p <= arrptr + m; p++)
        if (*p < min)
            min = *p;

    *res = min;
    return 0;
}

/* №7. Значение последнего отрицательного элемента.
   Возвращает 0 и пишет результат в *res, либо -1, если такого нет */
int arr_last_negative(int *arrptr, size_t n, int *res)
{
    int *p;
    for (p = arrptr + n - 1; p >= arrptr; p--) {
        if (*p < 0) {
            *res = *p;
            return 0;
        }
    }
    return -1;
}

/* №22. Сумма элементов, значения которых выше k */
int arr_sum_above(int *arrptr, size_t n, int k)
{
    int *p;
    int sum = 0;
    for (p = arrptr; p < arrptr + n; p++)
        if (*p > k)
            sum += *p;

    return sum;
}

/* №21. Сумма элементов, значения которых ниже k */
int arr_sum_below(int *arrptr, size_t n, int k)
{
    int *p;
    int sum = 0;
    for (p = arrptr; p < arrptr + n; p++)
        if (*p < k)
            sum += *p;

    return sum;
}

/* №27. Индексы элементов ниже среднего значения.
   Индексы пишутся в idx, возвращается их количество */
size_t arr_idx_below_avg(int *arrptr, size_t n, size_t *idx)
{
    int *p;
    double avg = 0;
    size_t cnt = 0;

    for (p = arrptr; p < arrptr + n; p++)
        avg += *p;
    avg /= n;

    for (p = arrptr; p < arrptr + n; p++) {
        if (*p < avg) {
            *(idx + cnt) = p - arrptr;
            cnt++;
        }
    }
    return cnt;
}