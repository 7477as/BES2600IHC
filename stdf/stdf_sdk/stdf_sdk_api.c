/*******************************************************************************
  Filename:       .

  Version         V1.0.

  Author          Yuping.Mo.

  Description:    .


  IMPORTANT:      .

*******************************************************************************/

/*******************************************************************************
 * INCLUDES
 */
#include "stdf_define.h"
#include "stdf_sdk.h"

#include "app_tws_if.h"
#include "factory_section.h"


/*******************************************************************************
 * MACROS
 */
// Only one define can be selected
//#define STDF_SDK_API_EARSIDE_USE_GPIO
#define STDF_SDK_API_EARSIDE_USE_BT_ADDR
//STDF_SDK_API_EARSIDE_USE_FLASH


#define STDF_SDK_API_LOG(str, ...)          STDF_LOG("[SDK][API] %s "str, __func__, ##__VA_ARGS__)
#define STDF_SDK_API_ASSERT(cond)           STDF_ASSERT(cond)

/*******************************************************************************
 * TYPEDEFS
 */

/*******************************************************************************
* GLOBAL VARIABLES
*/

/*******************************************************************************
 * EXTERNAL VARIABLES
 */

/*******************************************************************************
 * FUNCTIONS
 */

/*******************************************************************************
 * @fn      .
 * @brief   .
 * @param   .
 * @return  .
 * @notice  .
 */
void stdf_sdk_api_init_earside(void)
{
    uint8_t earside_old = !app_tws_is_unknown_side() + app_tws_is_right_side();
    
    // GPIO level is low means right side while high means left side
#if defined(STDF_SDK_API_EARSIDE_USE_GPIO)
    
    // BT addr last bit is Odd means right side while even means left side.
#elif defined(STDF_SDK_API_EARSIDE_USE_BT_ADDR)
    uint8_t *addr = factory_section_get_bt_address();
    app_tws_set_side_from_addr(addr);
    
    // Read the ear side flag form flash that the factory ATE whited.
#elif defined(STDF_SDK_API_EARSIDE_USE_FLASH)
    
#else
#error Please select a way to deside ear side!!!
#endif
    
    uint8_t earside_new = !app_tws_is_unknown_side() + app_tws_is_right_side();
    
    STDF_SDK_API_LOG("earside %d -> %d", earside_old, earside_new);
}

/*******************************************************************************
*******************************************************************************/
