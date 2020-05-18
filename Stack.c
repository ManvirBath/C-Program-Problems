//Exercise 12.13 (Postfix Evaluator)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//self-referential structure 
struct stackNode {
  //define data as an int  
  int data;
  //stackNode pointer 
  struct stackNode *nextPtr;
};

//synonym for struct stackNode
typedef struct stackNode StackNode;
//synonym for Stacknode* 
typedef StackNode *StackNodePtr;

//prototypes 
int evaluatePostfixExpression(char *expr);
int calculate(int op1, int op2, char operator);
void push(StackNodePtr *topPtr, int value);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr topPtr);

//driver code 
int main(void) {
    //intro 
    printf("Postfix Evaluator Program");
    printf("\n");
    printf("-------------------------");
    printf("\n");

    char pf[250];
    //input 
    printf("Enter the postfix expression:\n");
    scanf("%s", pf);

    int len = strlen(pf);
    pf[len] = '\0';  

    //prints out result of postfix expression 
    printf("Result: %d", evaluatePostfixExpression(pf));
    printf("\n");
}

//evaluates postfix expression 
int evaluatePostfixExpression(char *expr) {
    int i = 0; 

    StackNodePtr s = NULL;

    while(expr[i] != '\0'){
        //handles digits from 0 to 9
        if(isdigit(expr[i])){ 
          //value of the char - '0' and push 
          push(&s, (expr[i]-'0')); 
        }
        if(expr[i]=='+' || expr[i]=='-'|| expr[i]=='*' ||
         expr[i]=='/' || expr[i]=='^' || expr[i] =='%'){
           //pop, the right side out first 
        int x = pop(&s);
        int y = pop(&s);  
        
        //push calculations of expression 
        int calc = calculate(y, x, expr[i]);
        push(&s, calc);
      }
      i++;
    }
    //return pop value of stack 
    return pop(&s);
}

//evaluates the expression op1 operator op2 
int calculate(int op1, int op2, char operator) {
  //handles all calcuation operators such as +, -, *, /, %, ^
  if(operator == '+') {
    return op1 + op2;
  } else if(operator == '-') {
    return op1 - op2; 
  } else if(operator == '*') {
    return op1 * op2;
  } else if(operator == '/') {
    return op1/op2;
  } else if(operator == '%') {
    return op1 % op2;
  } else if(operator == '^') {
    return pow(op1, op2);
  } else {
    printf("Invalid operator.");
    return 0;
  }
}

//pushes value on the stack 
void push(StackNodePtr *topPtr, int value) {
  StackNodePtr newPtr = malloc(sizeof(StackNode));

  //insert node at stack top
  if(newPtr != NULL) {
    newPtr->data = value;
    newPtr->nextPtr = *topPtr;
    *topPtr = newPtr; 
  } else {
      //no space available
      printf("%d not inserted. No memory available.\n", value);
  }
}

//pops a value off the stack 
int pop(StackNodePtr *topPtr) {
  StackNodePtr tempPtr = *topPtr;
  int popValue = (*topPtr)->data;
  *topPtr = (*topPtr)->nextPtr;
  free(tempPtr);
  return popValue; 
}

//determines where stack is empty 
int isEmpty(StackNodePtr topPtr) {
  return topPtr == NULL;
}

//prints the stack 
void printStack(StackNodePtr topPtr) {
  //if stack is empty
  if(topPtr == NULL) {
    puts("The stack is empty.\n");
  } else {
    puts("The stack is: ");

  //while not end of stack
  while(topPtr != NULL) {
    printf("%d --> ", topPtr->data);
    topPtr = topPtr->nextPtr;
  }
    puts("NULL\n");
  }
}

/* 
Test Case 1: 
Postfix Evaluator Program
-------------------------
Enter the postfix expression:
42+351-*+
Result: 18

Test Case 2:
Postfix Evaluator Program
-------------------------
Enter the postfix expression:
34+2*7/
Result: 2

Test Case 3: 
Postfix Evaluator Program
-------------------------
Enter the postfix expression:
45+
Result: 9

*/