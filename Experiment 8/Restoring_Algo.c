#include <stdio.h>

void binaryPrint(int n, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main() {
    int M, Q, A = 0, count;
    int n;

    printf("Enter the divisor (M): ");
    scanf("%d", &M);
    printf("Enter the dividend (Q): ");
    scanf("%d", &Q);
    printf("Enter the number of bits: ");
    scanf("%d", &n);

    count = n;

    printf("\nInitial values:\n");
    printf("A: ");
    binaryPrint(A, n);
    printf("Q: ");
    binaryPrint(Q, n);
    printf("M: ");
    binaryPrint(M, n);
    printf("\n");

    while (count > 0) {
        A = (A << 1) | ((Q >> (n - 1)) & 1);
        Q = (Q << 1);

        printf("After left shift:\n");
        printf("A: ");
        binaryPrint(A, n);
        printf("Q: ");
        binaryPrint(Q, n);

        A = A - M;

        printf("After subtraction:\n");
        printf("A: ");
        binaryPrint(A, n);

        if (A < 0) {
            A = A + M;
            Q = Q & ~(1);
        } else {
            Q = Q | 1;
        }

        printf("After restore (if needed):\n");
        printf("A: ");
        binaryPrint(A, n);
        printf("Q: ");
        binaryPrint(Q, n);
        printf("\n");

        count--;
    }

    printf("Final quotient (Q): ");
    binaryPrint(Q, n);
    printf("Final remainder (A): ");
    binaryPrint(A, n);

    return 0;
}
/*
Enter the divisor (M): 3
Enter the dividend (Q): 8
Enter the number of bits: 4

Initial values:
A: 0000
Q: 1000
M: 0011

After left shift:
A: 0001
Q: 0000
After subtraction:
A: 1110
After restore (if needed):
A: 0001
Q: 0000

After left shift:
A: 0010
Q: 0000
After subtraction:
A: 1111
After restore (if needed):
A: 0010
Q: 0000

After left shift:
A: 0100
Q: 0000
After subtraction:
A: 0001
After restore (if needed):
A: 0001
Q: 0001

After left shift:
A: 0010
Q: 0010
After subtraction:
A: 1111
After restore (if needed):
A: 0010
Q: 0010

Final quotient (Q): 0010
Final remainder (A): 0010

*/
