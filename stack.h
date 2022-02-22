typedef struct stack  {
    void *arrp;
    int top_of_stack;
    int stack_depth;
    int obj_size;
    void (*push)(void*, void*);
    void* (*pull)(void *, void*);
    int (*isempty)(void *);
    int (*isfull)(void*);
    } stack_t;

void init_stack(stack_t *stackp, int obj_size, int array_len);
