#ifndef MYARRFUNC_H
#define MYARRFUNC_H

int arr_fill(int *arrptr, size_t n);
void arr_print(int *arrptr, size_t n);
int arr_min_range(int *arrptr, size_t n, size_t k, size_t m, int *res);
int arr_last_negative(int *arrptr, size_t n, int *res);
int arr_sum_above(int *arrptr, size_t n, int k);
int arr_sum_below(int *arrptr, size_t n, int k);
size_t arr_idx_below_avg(int *arrptr, size_t n, size_t *idx);

#endif