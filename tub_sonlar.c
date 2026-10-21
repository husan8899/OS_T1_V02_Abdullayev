
#include <stdlib.h>
#include "tub_sonlar.h"

int tub_sonlarni_top(int n, int *sonlar) {
    if (n < 2 || n > 10000 || sonlar == NULL) {
        return -1;
    }

    int *p = malloc((size_t)(n + 1) * sizeof(int));

    if (p == NULL) {
        return -1;
    }

    for (int i = 0; i <= n; i++) {
        *(p + i) = 1;
    }

    *(p + 0) = 0;
    *(p + 1) = 0;

    for (int i = 2; i * i <= n; i++) {
        if (*(p + i) == 1) {
            for (int j = i * i; j <= n; j += i) {
                *(p + j) = 0;
            }
        }
    }

    int count = 0;

    for (int i = 2; i <= n; i++) {
        if (*(p + i) == 1) {
            *(sonlar + count) = i;
            count++;
        }
    }

    free(p);
    return count;
}
