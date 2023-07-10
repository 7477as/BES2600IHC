/*******************************************************************************
  Filename:       .

  Version         V1.0.

  Author          Yuping.Mo.

  Description:    .


  IMPORTANT:      .

*******************************************************************************/

#ifndef __STDF_OS_CONFIG_H__
#define __STDF_OS_CONFIG_H__

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
#define STDF_OS_MSG_ID_INVALID              0x0000
#define STDF_OS_MSG_ID_BASE_INTERNAL        0x0001 // internal message from 0x0000 to 0x7FFF
#define STDF_OS_MSG_ID_BASE_GLOABLE         0x8000 // global message from 0x8000 to 0xFFFF

/*******************************************************************************
 * TYPEDEFS
 */
//
typedef  uint16_t stdf_os_msg_id_t;

// The standard function style of the message handler
typedef  void (*stdf_os_handler_t)(stdf_os_msg_id_t msg_id, void *payload);

//
typedef struct
{
    stdf_os_handler_t  handler;             // the handler to recieved the message
    stdf_os_msg_id_t   msg_id;
    void              *payload;             //
}stdf_os_msg_t;


/*******************************************************************************
 * EXTERNAL VARIABLES
 */

/*******************************************************************************
 * FUNCTIONS
 */

/*******************************************************************************
*******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __STDF_OS_CONFIG_H__ */

