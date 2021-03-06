/*
 * Copyright (C) 2016 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __INIT_BOARD_DEVICE_H__
#define __INIT_BOARD_DEVICE_H__

#include "init_board_common.h"
#include "init_prototypes.h"

// Constants: device LEDs
#include "sony_lights.h"

// Constants: devices controls
#define DEV_BLOCK_FOTA_NUM 32
#define DEV_BLOCK_FOTA_MAJOR 259
#define DEV_BLOCK_FOTA_MINOR 0

// Constants: init configurations
#define FOTA_RAMDISK_CHECK 0

// Class: init_board_device
class init_board_device : public init_board_common
{
public:
    // Board: introduction for keycheck
    virtual void introduce_keycheck()
    {
        // LED boot selection colors
        led_color(255, 0, 255);
    }

    // Board: introduction for Android
    virtual void introduce_android()
    {
        // Power off LED
        led_color(0, 0, 0);
    }

    // Board: introduction for Recovery
    virtual void introduce_recovery()
    {
        // LED Recovery colors
        led_color(255, 100, 0);
    }

    // Board: set led colors
    void led_color(uint8_t r, uint8_t g, uint8_t b)
    {
        write_int(LED_RED_PATH "brightness", r);
        write_int(LED_GREEN_PATH "brightness", g);
        write_int(LED_BLUE_PATH "brightness", b);
    }
     // Board: Finish init
    virtual void finish_init()
    {
        // Rename init
        unlink("/init");
        rename("/init.real", "/init");
    }
};

#endif //__INIT_BOARD_DEVICE_H__
