/*
 * queue.c
 *
 *  Created on: Mar 19, 2024
 *      Author: DELL
 */

#include "queue.h"
#include <stdint.h>

void Queue_Init(Queue_t *queue)
{
    queue->head = 0;
    queue->tail = 0;
    queue->size = 0;
}

void Queue_Push(Queue_t *queue, uint16_t data)
{
    if (queue->size == QUEUE_SIZE)
    {
    	queue->head = (queue->head - 1 + QUEUE_SIZE) % QUEUE_SIZE;
    }
    else
    {
        queue->head = (queue->head - 1 + QUEUE_SIZE) % QUEUE_SIZE;
        queue->size++;
    }

    queue->data[queue->head] = data;
}

void Queue_Print(Queue_t *queue)
{
	uint8_t str[7];
	UART0_SendChar('\n', 0);
	for (int i = 0; i < queue->size; i++)
	{
    	int index = (queue->head + i) % QUEUE_SIZE;
        sprintf(str, "%3d ", queue->data[index]);
        UART0_SendString(str, strlen(str), 0);
    }
    UART0_SendChar('\n', 0);
}

