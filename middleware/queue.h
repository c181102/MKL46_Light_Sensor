/*
 * queue.h
 *
 *  Created on: Mar 19, 2024
 *      Author: DELL
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdint.h>

#define QUEUE_SIZE 10

typedef struct {
	uint16_t data[QUEUE_SIZE];
    int head;
    int tail;
    int size;
} Queue_t;

void Queue_Init(Queue_t *queue);
void Queue_Push(Queue_t *queue, uint16_t data);
void Queue_Print(Queue_t *queue);

#endif /* QUEUE_H_ */
