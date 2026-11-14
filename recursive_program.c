#include <stdio.h>

long long sumNaturalNumbers(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + sumNaturalNumbers(n - 1);
}

long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

/* Returns the nth Fibonacci term, using F1 = 0 and F2 = 1. */
long long fibonacciTerm(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    return fibonacciTerm(n - 1) + fibonacciTerm(n - 2);
}

/* Prints n Fibonacci terms recursively. */
void printFibonacciTerms(int n, long long first, long long second) {
    if (n <= 0) {
        return;
    }

    printf("%lld ", first);
    printFibonacciTerms(n - 1, second, first + second);
}

int main(void) {
    int n;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Sum from 1 to %d: %lld\n", n, sumNaturalNumbers(n));
    printf("%d factorial: %lld\n", n, factorial(n));

    if (n > 0) {
        printf("Fibonacci term %d: %lld\n", n, fibonacciTerm(n));
    }

    printf("First %d Fibonacci terms: ", n);
    printFibonacciTerms(n, 0, 1);
    printf("\n");

    return 0;
}
