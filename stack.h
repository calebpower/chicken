struct Stack {
  int maxsize;
  int top;        
  int *items;
};
 
struct Stack* newStack(int capacity) {
  struct Stack *p = (struct Stack*)malloc(sizeof(struct Stack));
 
  p->maxsize = capacity;
  p->top = -1;
  p->items = (int*)malloc(sizeof(int) * capacity);
 
  return p;
}
 
int size(struct Stack *p) {
  return p->top + 1;
}
 
int isEmpty(struct Stack *p) {
  return p->top == -1;
}
 
int isFull(struct Stack *p) {
  return p->top == p->maxsize - 1;
}
 
void push(struct Stack *p, int x) {
  if (isFull(p)) {
    printf("OverFlow\nProgram Terminated\n");
    exit(EXIT_FAILURE);
  }

  printf("Inserting %d\n", x);

  p->items[++p->top] = x;
}
 
int peek(struct Stack *p) {
  if (!isEmpty(p))
    return p->items[p->top];
  else
    exit(EXIT_FAILURE);
}
 
int pop(struct Stack *p) {
  if (isEmpty(p)) {
    printf("UnderFlow\nProgram Terminated\n");
    exit(EXIT_FAILURE);
  }

  printf("Removing %d\n", peek(p));

  return p->items[p->top--];
}
