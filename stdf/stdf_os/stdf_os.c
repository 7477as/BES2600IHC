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
 
#include "stdf_os.h"
#include "stdf_os_message.h"

#include "stdf_define.h"


#define STDF_OS_LOG(str, ...)               STDF_LOG("[OS] %s "str, __func__, ##__VA_ARGS__)
#define STDF_OS_ASSERT(cond)                STDF_ASSERT(cond)

void stdf_os_init(void)
{
    STDF_OS_LOG("");

    stdf_os_msg_init();   
}

