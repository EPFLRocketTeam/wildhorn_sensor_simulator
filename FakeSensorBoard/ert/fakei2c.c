/*  Title		: Fake I2C module
 *  Filename	: fakei2c.c
 *	Author		: Antonin Mignot
 *	Date		: 02.05.2021
 *	Version		: 0.1
 *	Description	: this module mimicks a slave i2c module
 */

/**********************
 *	INCLUDES
 **********************/

#include <cmsis_os.h>
#include <main.h>
#include <fakei2c.h>

/**********************
 *	CONSTANTS
 **********************/


/**********************
 *	MACROS
 **********************/


/**********************
 *	TYPEDEFS
 **********************/


/**********************
 *	VARIABLES
 **********************/

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

/**********************
 *	PROTOTYPES
 **********************/


/**********************
 *	DECLARATIONS
 **********************/
void I2C1_EV_IRQHandler()
{
    HAL_I2C_EV_IRQHandler(&hi2c1);
    return;
}

//void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c)
//{
//    static int t = 0;
//    t++;
//    return;
//}

void i2c_thread(void * arg){
	NVIC_EnableIRQ(I2C1_EV_IRQn);
	uint8_t buffer[8] = {1,2,3,4,5,6,7,8};



	for(;;){
		HAL_I2C_Slave_Transmit_IT(&hi2c1, buffer, sizeof(buffer));

	}
}

/* END */
