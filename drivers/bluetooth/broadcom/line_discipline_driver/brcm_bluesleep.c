/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.


 *  Copyright (C) 2009-2014 Broadcom Corporation
 */


/******************************************************************************
*
*  Filename:      brcm_bluesleep.c
*
*  Description:   Interface Module for sleep control.Sleep control is board dependant.
*                 Based on the config entry different sleep controls are selected for
*                 different platforms
*
*******************************************************************************/
#include "../include/brcm_ldisc_sh.h"


/**
 * Handles proper timer action when outgoing data is delivered to the
 * HCI line discipline and wake the chip from sleep.
 **/
void brcm_btsleep_wake( enum sleep_type type)
{
#ifdef LPM_BLUESLEEP
//BT_S : fix wrong lpm_param issue, [START]
    //printk("%s - %d\n", __func__, type);
    if(type == SLEEP_BLUESLEEP)
         bluesleep_outgoing_data();
//         bluetooth_pm_outgoing_data();
//BT_E : fix wrong lpm_param issue, [END]
#endif
}

/**
 * Starts the Sleep-Mode Protocol on the Host.
**/
void brcm_btsleep_start(enum sleep_type type)
{
#ifdef LPM_BLUESLEEP
//BT_S : fix wrong lpm_param issue, [START]
    //printk("%s - %d\n", __func__, type);
    if(type == SLEEP_BLUESLEEP)
//        bluesleep_start();
    {
//        if(bluetooth_pm_sleep_start() != 0)
        if(bluesleep_start() != 0)

        {
      // if ret is not 0. fail to start bluetooth_pm sleep
        }
    }
//BT_E : fix wrong lpm_param issue, [END]
#endif
}
/**
 * Stops the Sleep-Mode Protocol on the Host.
 */
void brcm_btsleep_stop(enum sleep_type type)
{
#ifdef LPM_BLUESLEEP
//BT_S : fix wrong lpm_param issue, [START]
    //printk("%s - %d\n", __func__, type);
    if(type == SLEEP_BLUESLEEP)
        bluesleep_stop(0);

//        bluesleep_stop();
//        bluetooth_pm_sleep_stop();
//BT_E : fix wrong lpm_param issue, [END]
#endif
}











