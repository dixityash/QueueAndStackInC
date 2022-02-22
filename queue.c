/* 
 * linear queue
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

static void enqueue(queue_t *queuep, void *objp){
    char *dstptr;
    assert(!queuep->isfull(queuep));
    queuep->end_of_queue++;
    dstptr = (char *)queuep->arrp + queuep->end_of_queue*queuep->obj_size;
    memcpy((void*)dstptr, (void*)objp, queuep->obj_size);
}

static void dequeue(queue_t *queuep, void *objp){
    char *srcptr;
    assert(!queuep->isempty(queuep));
    queuep->start_of_queue++; 
    srcptr = (char *)queuep->arrp + queuep->start_of_queue*queuep->obj_size;
    memcpy(objp, srcptr,queuep->obj_size);
    if(queuep->start_of_queue == queuep->end_of_queue)
        queuep->start_of_queue = queuep->end_of_queue = -1;
}

static int isfull(queue_t *queuep){
    return(queuep->end_of_queue == queuep->queue_depth-1);
}

static int isempty(queue_t *queuep){
    return(queuep->end_of_queue == -1);
}

/* end of queue == -1 means queue is empty
 * end of queue == (len_of_queue - 1) means queue is full
 * assumed that queue overflow/underflow is programming error and progam
 * will be aborted using assert
  */
void init_queue(queue_t *queuep, int obj_size, int array_len){

    void* obj= (void*)malloc(obj_size*array_len);
    queuep->arrp = obj;
    queuep->end_of_queue = -1; 
    queuep->start_of_queue = -1; 
    queuep->queue_depth = array_len;
    queuep->obj_size = obj_size;
    queuep->enqueue = (void (*))enqueue;
    queuep->dequeue = (void (*))dequeue;
    queuep->isfull = (void (*))isfull;
    queuep->isempty = (void (*))isempty;
}



