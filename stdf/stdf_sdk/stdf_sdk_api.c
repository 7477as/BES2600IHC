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
#include "heap_api.h"

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
    ibrt_box_state box_state = app_ibrt_ui_get_ctx()->box_state;
    ibrt_box_state box_state_future = app_ibrt_ui_get_ctx()->box_state_future;

    STDF_SDK_API_LOG("box_state (%d %d) -> %d", box_state, box_state_future, IBRT_IN_BOX_CLOSED);
    if(box_state == IBRT_BOX_UNKNOWN)
    {
        STDF_SDK_API_LOG("init!!!");
        app_ibrt_ui_event_entry(IBRT_CLOSE_BOX_EVENT);    
    }
    else if((box_state_future == IBRT_IN_BOX_OPEN) || 
        ((box_state_future != IBRT_IN_BOX_OPEN) && (box_state == IBRT_IN_BOX_OPEN)))
    {
        app_ibrt_ui_event_entry(IBRT_CLOSE_BOX_EVENT);    
    }
    else
    {
        STDF_SDK_API_LOG("fail!!!");
    }
}

/*******************************************************************************
 * @brief   .
 */
void stdf_sdk_api_phy_set_state_in_case_open(void)
{
    ibrt_box_state box_state = app_ibrt_ui_get_ctx()->box_state;
    ibrt_box_state box_state_future = app_ibrt_ui_get_ctx()->box_state_future;

    STDF_SDK_API_LOG("box_state (%d %d) -> %d", box_state, box_state_future, IBRT_IN_BOX_OPEN);
    if(box_state == IBRT_BOX_UNKNOWN)
    {
        STDF_SDK_API_LOG("init!!!");
        app_ibrt_ui_event_entry(IBRT_OPEN_BOX_EVENT);    
    }     
    else if((box_state_future == IBRT_IN_BOX_CLOSED) || 
        ((box_state_future != IBRT_IN_BOX_CLOSED) && (box_state == IBRT_IN_BOX_CLOSED)))
    {
        app_ibrt_ui_event_entry(IBRT_OPEN_BOX_EVENT);    
    }
    else if((box_state_future == IBRT_OUT_BOX) || 
        ((box_state_future != IBRT_OUT_BOX) && (box_state == IBRT_OUT_BOX)))
    {
        app_ibrt_ui_event_entry(IBRT_PUT_IN_EVENT);
    }
    else
    {
        STDF_SDK_API_LOG("fail!!!");
    }
}

/*******************************************************************************
 * @brief   .
 */
void stdf_sdk_api_phy_set_state_out_case_ear(void)
{
    ibrt_box_state box_state = app_ibrt_ui_get_ctx()->box_state;
    ibrt_box_state box_state_future = app_ibrt_ui_get_ctx()->box_state_future;

    STDF_SDK_API_LOG("box_state (%d %d) -> %d", box_state, box_state_future, IBRT_OUT_BOX);
    if(box_state == IBRT_BOX_UNKNOWN)
    {
        STDF_SDK_API_LOG("init!!!");
        app_ibrt_ui_event_entry(IBRT_FETCH_OUT_EVENT);   
    }    
    else if((box_state_future == IBRT_IN_BOX_OPEN) || 
        ((box_state_future == IBRT_BOX_UNKNOWN) && (box_state == IBRT_IN_BOX_OPEN)))
    {
        app_ibrt_ui_event_entry(IBRT_FETCH_OUT_EVENT);    
    }
    else if((box_state_future == IBRT_OUT_BOX_WEARED) || 
        ((box_state_future != IBRT_OUT_BOX_WEARED) && (box_state == IBRT_OUT_BOX_WEARED)))
    {
        app_ibrt_ui_event_entry(IBRT_WEAR_DOWN_EVENT);
    }
    else
    {
        STDF_SDK_API_LOG("fail!!!");
    }    
}

/*******************************************************************************
 * @brief   .
 */
void stdf_sdk_api_phy_set_state_in_ear(void)
{
    ibrt_box_state box_state = app_ibrt_ui_get_ctx()->box_state;
    ibrt_box_state box_state_future = app_ibrt_ui_get_ctx()->box_state_future;

    STDF_SDK_API_LOG("box_state (%d %d) -> %d", box_state, box_state_future, IBRT_OUT_BOX_WEARED);
    if(box_state == IBRT_BOX_UNKNOWN)
    {
        STDF_SDK_API_LOG("init!!!");
        app_ibrt_ui_event_entry(IBRT_WEAR_UP_EVENT);    
    }
    else if((box_state_future == IBRT_OUT_BOX) || 
        ((box_state_future != IBRT_OUT_BOX) && (box_state == IBRT_OUT_BOX)))
    {
        app_ibrt_ui_event_entry(IBRT_WEAR_UP_EVENT);
    }
    else
    {
        STDF_SDK_API_LOG("fail!!!");
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
void stdf_sdk_api_enter_tws_pairing(void)
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

/*******************************************************************************
 * @fn      .
 * @brief   .
 * @param   .
 * @return  .
 * @notice  .
 */
void stdf_sdk_api_enter_freeman_pairing(void)
{
    //app_ibrt_ui_event_entry(IBRT_NONE_EVENT);
    app_ibrt_if_enter_freeman_pairing();
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
    stdf_sdk_api_earside_t earside_old = stdf_sdk_api_get_earside();
    
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
    
    stdf_sdk_api_earside_t earside_new = stdf_sdk_api_get_earside();
    
    STDF_SDK_API_LOG("earside %d -> %d", earside_old, earside_new);
}

/*******************************************************************************
 * @fn      .
 * @brief   .
 * @param   .
 * @return  .
 * @notice  .
 */
stdf_sdk_api_earside_t stdf_sdk_api_get_earside(void)
{
    return !app_tws_is_unknown_side() + app_tws_is_right_side();
}

/*******************************************************************************
 * @fn      .
 * @brief   .
 * @param   .
 * @return  .
 * @notice  .
 */
void stdf_sdk_api_log_info(void)
{
    size_t total = 8, used = 8, max_used = 8;
    med_memory_info(&total, &used, &max_used);
    STDF_SDK_API_LOG("total %d used %d max_used %d", total, used, max_used);
}

/*******************************************************************************
*******************************************************************************/
