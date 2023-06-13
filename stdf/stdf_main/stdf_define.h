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
#ifndef __STDF_DEFINE_H__
#define __STDF_DEFINE_H__

#include "hal_trace.h"

// Definitions for debug
#define STDF_LOG(str, ...)             TRACE(0, "[STDF] "str, ##__VA_ARGS__)
#define STDF_DUMP8(str, buf, cnt)      DUMP8(str, buf, cnt)
#define STDF_ASSERT(cond)              ASSERT(cond, "[STDF][ASSERT] %s line %d", __func__, __LINE__)

//#define A_A2DP_LOG(str, ...)         TRACE(1, "[A_A2DP]%s "str, __func__,##__VA_ARGS__)
//#define	A_A2DP_DUMP8(str,buf,cnt)    DUMP8(str, buf, cnt)
//ASSERT(0, "ASSERT  %s %d", __func__, __LINE__);

#endif