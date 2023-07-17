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
#include "stdf_sdk_api.h"

#include "app_ibrt_if.h"
#include "app_ibrt_ui.h"
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

/* -----------------------------------------------------------------------------
 *                                   PHY
 * ---------------------------------------------------------------------------*/

/*******************************************************************************
 * @brief   .
 */
bool stdf_sdk_api_phy_is_state_in_case_close(bool local)
{
    if(local)
    {
        return (app_ibrt_ui_get_ctx()->box_state == IBRT_IN_BOX_CLOSED);
    }
    else
    {
        return (app_ibrt_ui_get_ctx()->peer_tws_info.box_state == IBRT_IN_BOX_CLOSED);
    }
}

/*******************************************************************************
 * @brief   .
 */
bool stdf_sdk_api_phy_is_state_in_case_open(bool local)
{
    if(local)
    {
        return (app_ibrt_ui_get_ctx()->box_state == IBRT_IN_BOX_OPEN);
    }
    else
    {
        return (app_ibrt_ui_get_ctx()->peer_tws_info.box_state == IBRT_IN_BOX_OPEN);
    }
}

/*******************************************************************************
 * @brief   .
 */
bool stdf_sdk_api_phy_is_state_out_case_ear(bool local)
{
    if(local)
    {
        return (app_ibrt_ui_get_ctx()->box_state == IBRT_OUT_BOX);
    }
    else
    {
        return (app_ibrt_ui_get_ctx()->peer_tws_info.box_state == IBRT_OUT_BOX);
    }
}

/*******************************************************************************
 * @brief   .
 */
bool stdf_sdk_api_phy_is_state_in_ear(bool local)
{
    if(local)
    {
        return (app_ibrt_ui_get_ctx()->box_state == IBRT_OUT_BOX_WEARED);
    }
    else
    {
        return (app_ibrt_ui_get_ctx()->peer_tws_info.box_state == IBRT_OUT_BOX_WEARED);
    }
}

/*******************************************************************************
 * @brief   .
 */
void stdf_sdk_api_phy_set_state_in_case_close(void)
{
    bool in_case_open = stdf_sdk_api_phy_is_state_in_case_open(true);
    
    STDF_SDK_API_LOG("%s", in_case_open ? "success" : "fail!!!");
    if(in_case_open)
    {
        app_ibrt_ui_event_entry(IBRT_CLOSE_BOX_EVENT);    
    }
}

/*******************************************************************************
 * @brief   .
 */
void stdf_sdk_api_phy_set_state_in_case_open(void)
{
    bool in_case_close = stdf_sdk_api_phy_is_state_in_case_close(true);
    bool out_case_ear = stdf_sdk_api_phy_is_state_out_case_ear(true);
    
    STDF_SDK_API_LOG("%s", (in_case_close || out_case_ear) ? "success" : "fail!!!");
    if(in_case_close)
    {
        app_ibrt_ui_event_entry(IBRT_OPEN_BOX_EVENT);    
    }
    else if(out_case_ear)
    {
        app_ibrt_ui_event_entry(IBRT_PUT_IN_EVENT);
    }
}

/*******************************************************************************
 * @brief   .
 */
void stdf_sdk_api_phy_set_state_out_case_ear(void)
{
    bool in_case_open = stdf_sdk_api_phy_is_state_in_case_open(true);
    bool in_ear = stdf_sdk_api_phy_is_state_in_ear(true);
    
    STDF_SDK_API_LOG("%s", (in_case_open || in_ear) ? "success" : "fail!!!");
    if(in_case_open)
    {
        app_ibrt_ui_event_entry(IBRT_FETCH_OUT_EVENT);    
    }
    else if(in_ear)
    {
        app_ibrt_ui_event_entry(IBRT_WEAR_DOWN_EVENT);
    }
}

/*******************************************************************************
 * @brief   .
 */
void stdf_sdk_api_phy_set_state_in_ear(void)
{
    bool in_ear = stdf_sdk_api_phy_is_state_in_ear(true);
    
    STDF_SDK_API_LOG("%s", !in_ear ? "success" : "fail!!!");
    if(!in_ear)
    {
        app_ibrt_ui_event_entry(IBRT_WEAR_UP_EVENT);    
    }    
}

/* -----------------------------------------------------------------------------
 *                                   BT
 * ---------------------------------------------------------------------------*/

/*******************************************************************************
 * @fn      .
 * @brief   .
 * @param   .
 * @return  .
 * @notice  .
 */
void stdf_sdk_api_tws_enter_pairing(void)
{
    STDF_SDK_API_LOG("");
    
    if(app_tws_is_left_side())
    {
        app_ibrt_enter_limited_mode();
    }
    else if(app_tws_is_right_side())
    {
        app_ibrt_enter_limited_mode();
        app_start_tws_serching_direactly();
    }
    else
    {
        STDF_SDK_API_LOG("unknown earside exit tws pairing!!!");
    }
}

/* -----------------------------------------------------------------------------
 *                                   misc
 * ---------------------------------------------------------------------------*/

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
