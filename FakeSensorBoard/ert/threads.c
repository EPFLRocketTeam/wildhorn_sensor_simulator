/*  Title		: Threads
 *  Filename	: threads.c
 *	Author		: iacopo sprenger
 *	Date		: 20.02.2022
 *	Version		: 0.1
 *	Description	: template for code files
 */

/**********************
 *	INCLUDES
 **********************/


#include <cmsis_os.h>
#include <threads.h>
#include <fakei2c.h>


/**********************
 *	CONSTANTS
 **********************/

#define DEFAULT_SZ	(1024)

#define I2C_SZ		DEFAULT_SZ
#define I2C_PRIO		(0)


/**********************
 *	MACROS
 **********************/

#define CREATE_THREAD(handle, name, func, cont, sz, prio) \
	static StaticTask_t name##_buffer; \
	static StackType_t name##_stack[ sz ]; \
	handle = xTaskCreateStatic( \
			func, \
	        #name, \
			sz, \
			( void * ) cont, \
			prio, \
			name##_stack, \
			&name##_buffer)

/**********************
 *	TYPEDEFS
 **********************/


/**********************
 *	VARIABLES
 **********************/

static TaskHandle_t i2c_handle = NULL;

/**********************
 *	PROTOTYPES
 **********************/


/**********************
 *	DECLARATIONS
 **********************/


void threads_init(void) {
	CREATE_THREAD(i2c_handle, i2c, i2c_thread, I2C_PRIO, I2C_SZ, 0);
}


/* END */
