#include <stdio.h>

void factorize(int n) {
    int i;
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            printf("%d=%d*%d\n", n, i, n / i);
            return;
        }
    }
    printf("%d=%d*%d\n", n, 1, n);
}

int main(int argc, char *argv[]) {
    FILE *file;
    int number;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(file, "%d", &number) == 1) {
        factorize(number);
    }

    fclose(file);
    return 0;
}
