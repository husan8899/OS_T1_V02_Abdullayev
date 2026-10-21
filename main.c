
#include <stdio.h>
#include <stdlib.h>
#include "tub_sonlar.h"

int main(void) {
    int n;

    printf("N sonini kiriting (2-10000): ");

    if (scanf("%d", &n) != 1 || n < 2 || n > 10000) {
        printf("Xato: N 2 dan 10000 gacha bo'lishi kerak.\n");
        return 1;
    }

    int *sonlar = malloc((size_t)n * sizeof(int));

    if (sonlar == NULL) {
        printf("Xato: xotira ajratilmadi.\n");
        return 1;
    }

    int count = tub_sonlarni_top(n, sonlar);

    if (count < 0) {
        printf("Xato: tub sonlarni hisoblashda muammo yuz berdi.\n");
        free(sonlar);
        return 1;
    }

    printf("Tub sonlar:\n");

    for (int i = 0; i < count; i++) {
        printf("%d ", *(sonlar + i));
    }

    printf("\nTub sonlar soni: %d\n", count);

    free(sonlar);
    return 0;
}
