/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <project.h>

/* Set LED RED color */
#define STR_ON  \
                do{     \
                    STR_Write   (0u); \
                    STG_Write   (1u); \
                    STB_Write   (1u); \
                }while(0)

/* Set LED GREEN color */
#define STG_ON \
                do{      \
                    STR_Write   (1u); \
                    STG_Write   (0u); \
                    STB_Write   (1u); \
                }while(0)

/* Set LED BLUE color */
#define STB_ON \
                do{     \
                    STR_Write   (1u); \
                    STG_Write   (1u); \
                    STB_Write   (0u); \
                }while(0)

/* Set LED TURN OFF */
#define ST_OFF \
                do{ \
                    STR_Write   (1u); \
                    STG_Write   (1u); \
                    STB_Write   (1u); \
                }while(0)

/* [] END OF FILE */
