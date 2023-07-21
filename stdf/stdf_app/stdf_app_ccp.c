/*******************************************************************************
  Filename:       .

  Version         V1.0.

  Author          Yuping.Mo.

  Description:    CCP(The Charging Case Protocal).


  IMPORTANT:      .

*******************************************************************************/

/*******************************************************************************
 * INCLUDES
 */
#include "stdf_app_ccp.h"
#include "stdf_app_protocal.h"
#include "stdf_define.h" 
#include "stdf_sdk_api.h"

/*******************************************************************************
 * MACROS
 */
#define STDF_APP_CCP_LOG(str, ...)          STDF_LOG("[CCP] %s "str, __func__, ##__VA_ARGS__)
#define STDF_APP_CCP_ASSERT(cond)           STDF_ASSERT(cond)

/*******************************************************************************
 * TYPEDEFS
 */
typedef void (*stdf_app_ccp_callback_t)(uint8_t *data, uint16_t length);

typedef struct
{
    stdf_app_protocal_cmd_t cmd;
    stdf_app_ccp_callback_t callback;
} stdf_app_ccp_config_t;

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
 * @brief   .
 */
static void stdf_app_ccp_case_open(uint8_t *data, uint16_t length)
{
    stdf_sdk_api_phy_set_state_in_case_open();
    stdf_app_protocal_response(NULL, 0, STDF_APP_PROTOCAL_ACK_SUCCESS);
}

/*******************************************************************************
 * @brief   .
 */
static void stdf_app_ccp_case_close(uint8_t *data, uint16_t length)
{
    stdf_sdk_api_phy_set_state_in_case_close();
    stdf_app_protocal_response(NULL, 0, STDF_APP_PROTOCAL_ACK_SUCCESS);
}

/*******************************************************************************
 * @brief   .
 */
static void stdf_app_ccp_1wire_download(uint8_t *data, uint16_t length)
{
    stdf_app_protocal_response(NULL, 0, STDF_APP_PROTOCAL_ACK_SUCCESS);
}

/*******************************************************************************
 * @brief   .
 */
static void stdf_app_ccp_tws_pairing(uint8_t *data, uint16_t length)
{
    stdf_app_protocal_response(NULL, 0, STDF_APP_PROTOCAL_ACK_SUCCESS);
}

/*******************************************************************************
 * @brief   .
 */
static void stdf_app_ccp_bt_pairing(uint8_t *data, uint16_t length)
{
    stdf_app_protocal_response(NULL, 0, STDF_APP_PROTOCAL_ACK_SUCCESS);
}

/*******************************************************************************
 * @brief   .
 */
static void stdf_app_ccp_freeman_pairing(uint8_t *data, uint16_t length)
{
    stdf_sdk_api_enter_freeman_pairing();
    stdf_app_protocal_response(NULL, 0, STDF_APP_PROTOCAL_ACK_SUCCESS);
}

/*******************************************************************************
 * @brief   .
 */
static void stdf_app_ccp_reset_factory_settings(uint8_t *data, uint16_t length)
{
    stdf_app_protocal_response(NULL, 0, STDF_APP_PROTOCAL_ACK_SUCCESS);
}

/*******************************************************************************
 * @brief   .
 */
static void stdf_app_ccp_read_bt_addr(uint8_t *data, uint16_t length)
{
    stdf_app_protocal_response(NULL, 0, STDF_APP_PROTOCAL_ACK_SUCCESS);
}

/*******************************************************************************
 * @brief   .
 */
static void stdf_app_ccp_write_tws_addr(uint8_t *data, uint16_t length)
{
    stdf_app_protocal_response(NULL, 0, STDF_APP_PROTOCAL_ACK_SUCCESS);
}

/*******************************************************************************
 * @fn      .
 * @brief   .
 * @param   .
 * @return  .
 * @notice  .
 */
stdf_app_ccp_config_t stdf_app_ccp_config_table[] = 
{
    {STDF_APP_PROTOCAL_CMD_CASE_OPEN,              stdf_app_ccp_case_open},
    {STDF_APP_PROTOCAL_CMD_CASE_CLOSE,             stdf_app_ccp_case_close},
    {STDF_APP_PROTOCAL_CMD_1WIRE_DOWNLOAD,         stdf_app_ccp_1wire_download},
    {STDF_APP_PROTOCAL_CMD_TWS_PAIRING,            stdf_app_ccp_tws_pairing},
    {STDF_APP_PROTOCAL_CMD_BT_PAIRING,             stdf_app_ccp_bt_pairing},
    {STDF_APP_PROTOCAL_CMD_FREEMAN_PAIRING,        stdf_app_ccp_freeman_pairing},
    {STDF_APP_PROTOCAL_CMD_RESET_FACTORY_SETTINGS, stdf_app_ccp_reset_factory_settings},
    {STDF_APP_PROTOCAL_CMD_READ_BT_ADDR,           stdf_app_ccp_read_bt_addr},
    {STDF_APP_PROTOCAL_CMD_WRITE_TWS_BDADDR,       stdf_app_ccp_write_tws_addr},
};

/*******************************************************************************
 * @fn      .
 * @brief   .
 * @param   .
 * @return  .
 * @notice  .
 */
static void stdf_app_ccp_protocal_callback(stdf_app_protocal_cmd_t cmd, uint8_t *data, uint16_t length)
{
    uint16_t table_length = sizeof(stdf_app_ccp_config_table) / sizeof(stdf_app_ccp_config_t);

    for(uint8_t index = 0; index <  table_length; index++)
    {
        if(cmd == stdf_app_ccp_config_table[index].cmd)
        {
            stdf_app_ccp_config_table[index].callback(data, length);
        }
    }
}

/*******************************************************************************
 * @fn      .
 * @brief   .
 * @param   .
 * @return  .
 * @notice  .
 */
void stdf_app_ccp_init(void)
{
    stdf_app_protocal_register_callback(stdf_app_ccp_protocal_callback);
}

/*******************************************************************************
*******************************************************************************/


