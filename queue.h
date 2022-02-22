typedef struct queue  {
    void *arrp;
    int start_of_queue;
    int end_of_queue;
    int queue_depth;
    int obj_size;
    void (*enqueue)(void*, void*);
    void* (*dequeue)(void *, void*);
    int (*isempty)(void *);
    int (*isfull)(void*);
    } queue_t;

void init_queue(queue_t *queuep, int obj_size, int array_len);
