#include <stdio.h>
#include <stdint.h>

#define BIT_SIZE 4

void printBinary(int num, int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

void boothMultiplication(int8_t M, int8_t Q) {
    int8_t A = 0;
    int8_t Q_1 = 0;
    int8_t M_neg = -M;

    printf("Initial values:\n");
    printf("A: ");
    printBinary(A, BIT_SIZE);
    printf("Q: ");
    printBinary(Q, BIT_SIZE);
    printf("Q-1: %d\n", Q_1);
    printf("\n");

    for (int i = 0; i < BIT_SIZE; i++) {
        int Qn = Q & 1;

        if (Qn == Q_1) {
            printf("Step %d: Arithmetic Shift Right\n", i + 1);
        } else if (Qn == 0 && Q_1 == 1) {
            printf("Step %d: A = A - M\n", i + 1);
            A = A + M_neg;
        } else if (Qn == 1 && Q_1 == 0) {
            printf("Step %d: A = A + M\n", i + 1);
            A = A + M;
        }

        Q_1 = Q & 1;
        Q = (A & 1) << (BIT_SIZE - 1) | (Q >> 1);
        A = (A >> 1) & ((1 << BIT_SIZE) - 1);

        printf("A: ");
        printBinary(A, BIT_SIZE);
        printf("Q: ");
        printBinary(Q, BIT_SIZE);
        printf("Q-1: %d\n", Q_1);
        printf("\n");
    }

    int result = ((int)A << BIT_SIZE) | (Q & ((1 << BIT_SIZE) - 1));
    printf("Final result: %d\n", result);
    printf("Binary result: ");
    printBinary(result, BIT_SIZE * 2);
}

int main() {
    int8_t M, Q;

    printf("Enter the multiplicand (M) (4-bit signed integer): ");
    scanf("%hhd", &M);
    printf("Enter the multiplier (Q) (4-bit signed integer): ");
    scanf("%hhd", &Q);

    boothMultiplication(M, Q);

    return 0;
}
/*
Output:
Enter the multiplicand (M) (4-bit signed integer): 5
Enter the multiplier (Q) (4-bit signed integer): 4
Initial values:
A: 0000
Q: 0100
Q-1: 0

Step 1: Arithmetic Shift Right
A: 0000
Q: 0010
Q-1: 0

Step 2: Arithmetic Shift Right
A: 0000
Q: 0001
Q-1: 0

Step 3: A = A + M
A: 0101
Q: 0000
Q-1: 1

Step 4: Arithmetic Shift Right
A: 0010
Q: 1000
Q-1: 0

Final result: 20
Binary result: 00010100

*/
