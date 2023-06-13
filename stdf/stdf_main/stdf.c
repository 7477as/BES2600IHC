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

#include "stdf_config.h"
#include "stdf_define.h"

#include "stdf.h"
#include "stdf_app.h"
#include "stdf_bsp.h"
#include "stdf_hal.h"
#include "stdf_os.h"
#include "stdf_sdk.h"

void stdf_init(void)
{
    STDF_LOG("stdf_init");

    //uint8_t testbuf[8] = {1,2,3,4,5,6,7,8};
    //STDF_DUMP8("testbuf is ", testbuf, 8);
    //STDF_ASSERT(0);

    stdf_os_init();

    stdf_sdk_init();
    
    stdf_hal_init();

    stdf_bsp_init();

    stdf_app_init();
}

