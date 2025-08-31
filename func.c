#include "func.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void prefixToInfix(const char* prefix, char* infix) {
    Stack s;
    initStack(&s);

    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--) {
        char c = prefix[i];
        if (isOperand(c)) {
            char op[2] = {c, '\0'};
            push(&s, op);
        } else if (isOperator(c)) {
            char *op1 = pop(&s);
            char *op2 = pop(&s);
            char temp[MAX_EXPR_SIZE];
            snprintf(temp, MAX_EXPR_SIZE, "(%s%c%s)", op1, c, op2);
            push(&s, temp);
        }
    }
    strcpy(infix, pop(&s));
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int isOperand(char c) {
    return isdigit(c);
}

void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, const char* str) {
    s->top++;
    strcpy(s->items[s->top], str);
}

char* pop(Stack* s) {
    return s->items[s->top--];
}

// Very basic infix evaluation (without parentheses support, for demo):
int evalInfix(const char* infix) {
    int a, b;
    char op;
    sscanf(infix, "%d%c%d", &a, &op, &b);
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}
