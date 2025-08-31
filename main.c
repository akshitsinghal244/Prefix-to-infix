#include "func.h"

int main() {
    char prefix[MAX_EXPR_SIZE];
    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    char infix[MAX_EXPR_SIZE];
    prefixToInfix(prefix, infix);
    printf("Infix: %s\n", infix);

    int result = evalInfix(infix);
    printf("Result: %d\n", result);

    return 0;
}
