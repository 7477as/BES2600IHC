/***************************************************************************
 *
 * Copyright 2015-2019 BES.
 * All rights reserved. All unpublished rights reserved.
 *
 * No part of this work may be used or reproduced in any form or by any
 * means, or stored in a database or retrieval system, without prior written
 * permission of BES.
 *
 * Use of this work is governed by a license granted by BES.
 * This work contains confidential and proprietary information of
 * BES. which is protected by copyright, trade secret,
 * trademark and other intellectual property rights.
 *
 ****************************************************************************/
#ifndef __STDF_OS_MESSGAE_H__
#define __STDF_OS_MESSGAE_H__

#include "plat_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define STDF_OS_MSG_ID_SYSTEM_BASE           0x8000
#define STDF_OS_MSG_ID_INVALID               0xFFFF

#define MessageSend(handler, id, payload)   stdf_os_msg_send(handler, id, payload)
#define MessageSendLater(handler, id, payload, delay) \
                                            stdf_os_msg_send_later(handler, id, payload, delay)
#define MessageGetCount(handler, id)        stdf_os_msg_get_count(handler, id)
#define MessageCancelAll(handler, id)       stdf_os_msg_cancel_all(handler, id)

//
typedef  uint16_t stdf_os_msg_id_t;

// The standard function style of the message handler
typedef  void (*stdf_os_msg_handler_t)(stdf_os_msg_id_t msg_id, void *payload);

// APIs, ALL the APIs must called after stdf_os_msg_init()
void     stdf_os_msg_send(stdf_os_msg_handler_t handler, stdf_os_msg_id_t msg_id, void *payload);
void     stdf_os_msg_send_later(stdf_os_msg_handler_t handler, stdf_os_msg_id_t msg_id, void *payload, uint32_t delay);
uint16_t stdf_os_msg_get_count(stdf_os_msg_handler_t handler, stdf_os_msg_id_t msg_id);
bool     stdf_os_msg_cancel_first(stdf_os_msg_handler_t handler, stdf_os_msg_id_t msg_id);
uint16_t stdf_os_msg_cancel_all(stdf_os_msg_handler_t handler, stdf_os_msg_id_t msg_id);

// Framework
void     stdf_os_msg_init(void);

#ifdef __cplusplus
}
#endif

#endif