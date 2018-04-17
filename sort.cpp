#include <vector>

template <typename T>
void quick_sort(std::vector<T> &a, int begin, int end) {

    int b = begin, e = end-1;
    int mid = (b + e) / 2;

    do {
        while (a[b] < a[mid]) b++;
        while (a[e] > a[mid]) e--;

        if (b <= e) {
            T t = a[b];
            a[b] = a[e];
            a[e] = t;
            b++;
            e--;
        }

    } while(b <= e);

    if (e > begin)
        quick_sort(a, begin, e);
    if (b < end)
        quick_sort(a, b, end);
}