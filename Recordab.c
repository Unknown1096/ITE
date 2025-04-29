#include <stdio.h>
#define MAX 5  // Define the maximum size of the stack
// Stack structure
struct Stack {
    int top;
    int arr[MAX];
};
// Function to initialize the stack
void initialize(struct Stack *s) {
    s->top = -1;
}
// Function to push an element onto the stack
void push(struct Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++s->top] = value;
    printf("%d pushed into stack\n", value);
}
// Function to pop an element from the stack
void pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
        return;
    }
    printf("%d popped from stack\n", s->arr[s->top--]);
}
// Function to return the top element of the stack
void peek(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", s->arr[s->top]);
}
// Function to display the stack
void display(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--)
        printf("%d ", s->arr[i]);
    printf("\n");
}
// Main function to test stack operations
int main() {
    struct Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    pop(&s);
    peek(&s);

    push(&s, 40);
    push(&s, 50);
    push(&s, 60); // Should cause overflow
    display(&s);
    return 0;
}
