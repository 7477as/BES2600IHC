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

/*******************************************************************************
 * EXTERNAL VARIABLES
 */

/*******************************************************************************
 * FUNCTIONS
 */
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

void stdf_sdk_api_tws_enter_pairing(void);

/* -----------------------------------------------------------------------------
 *                                   misc
 * ---------------------------------------------------------------------------*/

void stdf_sdk_api_init_earside(void);

/*******************************************************************************
*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __STDF_SDK_API_H__ */
