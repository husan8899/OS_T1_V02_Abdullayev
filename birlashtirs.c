
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *birlashtir(const char *a, const char *b) {
    if (a == NULL || b == NULL) {
        return NULL;
    }

    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    if (len_a > (size_t)-1 - len_b - 1) {
        return NULL;
    }

    char *natija = malloc(len_a + len_b + 1);

    if (natija == NULL) {
        return NULL;
    }

    memcpy(natija, a, len_a);
    memcpy(natija + len_a, b, len_b + 1);

    return natija;
}

int main(void) {
    char a[200];
    char b[200];

    printf("Birinchi satrni kiriting: ");
    if (fgets(a, sizeof(a), stdin) == NULL) {
        printf("Xato: satrni o'qib bo'lmadi.\n");
        return 1;
    }

    printf("Ikkinchi satrni kiriting: ");
    if (fgets(b, sizeof(b), stdin) == NULL) {
        printf("Xato: satrni o'qib bo'lmadi.\n");
        return 1;
    }

    a[strcspn(a, "\n")] = '\0';
    b[strcspn(b, "\n")] = '\0';

    char *natija = birlashtir(a, b);

    if (natija == NULL) {
        printf("Xato: xotira ajratilmadi.\n");
        return 1;
    }

    printf("Birlashtirilgan satr: %s\n", natija);

    free(natija);

    return 0;
}
