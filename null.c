#include <stdio.h>

int main() {
    int nothing;
    // Print null pointer. Garanteed to crash.
    int *ptr = NULL;
    printf("%d\n", *ptr); 
    scanf("%d", &nothing);
    return 0;
}