/*  Title       : Header of Fake i2c module
 *  Filename    : fakei2c.h
 *  Author      : Antonin Mignot
 *  Date        : 02.05.2021
 *  Version     : 0.1
 *  Description : header of fakei2c.c
 */

#ifndef FAKEI2C_H
#define FAKEI2C_H



/**********************
 *  INCLUDES
 **********************/

#include <stdint.h>

/**********************
 *  CONSTANTS
 **********************/


/**********************
 *  MACROS
 **********************/


/**********************
 *  TYPEDEFS
 **********************/


/**********************
 *  VARIABLES
 **********************/


/**********************
 *  PROTOTYPES
 **********************/

#ifdef __cplusplus
extern "C"{
#endif

void I2C1_EV_IRQHandler();
void i2c_thread(void * arg);


#ifdef __cplusplus
} // extern "C"
#endif /* __cplusplus */

#endif /* TEMPLATE_H */

/* END */
