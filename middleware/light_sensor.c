/*
 * light_sensor.c
 *
 *  Created on: Mar 19, 2024
 *      Author: DELL
 */

#include "MKL46Z4.h"
#include "light_sensor.h"
#include "adc.h"
#include "queue.h"

#define LIGHT_ADC			(ADC0)

Queue_t queue;

static ADC_Config_Type light_adc_config = {
		.pin_config[0] = {PORTE, 22U, 3U},
		.resolution = ADC_MODE_DIFF0_8BIT_DIFF1_9BIT,
		.mode = ADC_DIFF_DISABLE,
};

void light_sensor_init()
{
	ADC_Init(ADC0, &light_adc_config);
	Queue_Init(&queue);
}

uint16_t light_get_data()
{
	uint16_t data = ADC_Read(LIGHT_ADC, light_adc_config.pin_config[0].channel);
	data = 5 * (3.3 - (data * 3.0 / 255)) * 10;
	return data;
}

void light_push_data(uint16_t data)
{
	Queue_Push(&queue, data);
}

void light_display_data()
{
	Queue_Print(&queue);
}
