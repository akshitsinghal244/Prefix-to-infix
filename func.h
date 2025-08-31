#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EXPR_SIZE 100

typedef struct {
    char items[MAX_EXPR_SIZE][MAX_EXPR_SIZE];
    int top;
} Stack;

void prefixToInfix(const char* prefix, char* infix);
int isOperator(char c);
int isOperand(char c);

void initStack(Stack* s);
void push(Stack* s, const char* str);
char* pop(Stack* s);

int evalInfix(const char* infix);

#endif
