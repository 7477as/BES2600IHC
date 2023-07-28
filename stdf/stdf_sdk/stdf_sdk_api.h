/*******************************************************************************
  Filename:       .

  Version         V1.0.

  Author          Yuping.Mo.

  Description:    .


  IMPORTANT:      .

*******************************************************************************/

#ifndef __STDF_SDK_API_H__
#define __STDF_SDK_API_H__

/*******************************************************************************
 * INCLUDES
 */
#include "plat_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
 * MACROS
 */

/*******************************************************************************
 * TYPEDEFS
 */
typedef enum
{
    STDF_SDK_API_EAR_SIDE_UNKOWN,
    STDF_SDK_API_EAR_SIDE_LEFT,
    STDF_SDK_API_EAR_SIDE_RIGHT
} stdf_sdk_api_earside_t;

/*******************************************************************************
 * EXTERNAL VARIABLES
 */

/*******************************************************************************
 * FUNCTIONS
 */

/* -----------------------------------------------------------------------------
 *                                   System
 * ---------------------------------------------------------------------------*/

void stdf_sdk_api_sys_delay_ms(uint32_t ms);
void stdf_sdk_api_sys_power_off(void);
void stdf_sdk_api_sys_reset(void);

/* -----------------------------------------------------------------------------
 *                                   PHY
 * ---------------------------------------------------------------------------*/
bool stdf_sdk_api_phy_is_state_in_case_close(bool local);
bool stdf_sdk_api_phy_is_state_in_case_open(bool local);
bool stdf_sdk_api_phy_is_state_out_case_ear(bool local);
bool stdf_sdk_api_phy_is_state_in_ear(bool local);

void stdf_sdk_api_phy_set_state_in_case_close(void);
void stdf_sdk_api_phy_set_state_in_case_open(void);
void stdf_sdk_api_phy_set_state_out_case_ear(void);
void stdf_sdk_api_phy_set_state_in_ear(void);

/* -----------------------------------------------------------------------------
 *                                   BT
 * ---------------------------------------------------------------------------*/

void stdf_sdk_api_enter_tws_pairing(void);
void stdf_sdk_api_enter_freeman_pairing(void);

bool stdf_sdk_api_is_tws_pairing(void);
bool stdf_sdk_api_is_bt_pairing(void);
bool stdf_sdk_api_is_tws_connected(void);
bool stdf_sdk_api_is_bt_connected(void);

bool stdf_sdk_api_is_role_unkouwn(void);
bool stdf_sdk_api_is_role_master(void);

uint8_t* stdf_sdk_api_read_bt_addr(void);

/* -----------------------------------------------------------------------------
 *                                   misc
 * ---------------------------------------------------------------------------*/

void stdf_sdk_api_init_earside(void);
stdf_sdk_api_earside_t stdf_sdk_api_get_earside(void);
void stdf_sdk_api_log_info(void);

/*******************************************************************************
*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __STDF_SDK_API_H__ */
