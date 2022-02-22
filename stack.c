#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

static void push(stack_t *stackp, void *objp){
    char *dstptr;
    assert(!stackp->isfull(stackp));
    stackp->top_of_stack++;
    dstptr = (char *)stackp->arrp + stackp->top_of_stack*stackp->obj_size;
    memcpy((void*)dstptr, (void*)objp, stackp->obj_size);
    printf("Pushing 0x%x\n",*(int*)dstptr);
}

static void pull(stack_t *stackp, void *objp){
    char *srcptr;
    assert(!stackp->isempty(stackp));
    srcptr = (char *)stackp->arrp + stackp->top_of_stack*stackp->obj_size;
    memcpy(objp, srcptr,stackp->obj_size);
    stackp->top_of_stack--; 
}

static int isfull(stack_t *stackp){
    return(stackp->top_of_stack == stackp->stack_depth-1);
}

static int isempty(stack_t *stackp){
    return(stackp->top_of_stack == -1);
}

/* top of stack == -1 means stack is empty
 * top of stack == (len_of_stack - 1) means stack is full
 * assumed that stack overflow/underflow is programming error and progam
 * will be aborted using assert
  */
void init_stack(stack_t *stackp, int obj_size, int array_len){

    void* obj= (void*)malloc(obj_size*array_len);
    stackp->arrp = obj;
    stackp->top_of_stack = -1; 
    stackp->stack_depth = array_len;
    stackp->obj_size = obj_size;
    stackp->push = (void (*))push;
    stackp->pull = (void (*))pull;
    stackp->isfull = (void (*))isfull;
    stackp->isempty = (void (*))isempty;
}



