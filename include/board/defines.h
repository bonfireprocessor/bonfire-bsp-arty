/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2017 Liviu Ionescu.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef BONFIRE_ARTY_BOARD_DEFINES_H_
#define BONFIRE_ARTY_BOARD_DEFINES_H_

// ----------------------------------------------------------------------------

#if defined(BONFIRE_ARTY_BOARD)
#else
#error "Only the BONFIRE_ARTY_BOARD is supported."
#endif /* _BOARD */

#define RISCV_BOARD_RTC_FREQUENCY_HZ		(83333333)


#define RISCV_MMIO_MTIME_ADDRESS 0x0FFFF0000
#define RISCV_MMIO_MTIMECMP_ADDRESS (RISCV_MMIO_MTIME_ADDRESS+8)

#define RISCV_INTERRUPTS_LOCAL_LAST_NUMBER (31)

//#define RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER 0


// ARTY_AXI Address Map
#define WISHBONE_IO_SPACE 0x40000000
#define AXI_IO_SPACE 0x80000000

//#define UART_BASE (WISHBONE_IO_SPACE)

// New:  2* ZPUINO_UART in AXI4 Space
#define UART0_BASE 0x80020000
#define UART1_BASE 0x80030000

#define UART_BASE UART0_BASE


#define SPIFLASH_BASE (WISHBONE_IO_SPACE+0x100)
#define GPIO_BASE (WISHBONE_IO_SPACE+0x200)
#define MTIME_BASE 0x0FFFF0000

#define DRAM_BASE 0x0

//#define DRAM_SIZE (32*1024) // "Fake" DRAM  32 KBytes

#define DRAM_TOP  0x0fffffff
#define DRAM_SIZE (DRAM_TOP-DRAM_BASE+1)
#define SRAM_BASE 0xC0000000
#define SRAM_SIZE (32*1024)
#define SRAM_TOP  (SRAM_BASE+SRAM_SIZE-1)

#define DCACHE_SIZE (8192*4)  // D Cache Size in Bytes


#define SYSCLK  83333333

// End Address MAP


#define CLK_PERIOD (1e+9 / SYSCLK)  // in ns...


// Parameters for SPI Flash

#define FLASHSIZE (16384*1024)
#define MAX_FLASH_IMAGESIZE (2024*1024) // Max 2MB of flash used for boot image
#define FLASH_IMAGEBASE (1024*3072)  // Boot Image starts at 3MB in Flash


// ----------------------------------------------------------------------------
// Definitions from SiFive bsp/env/hifive1.h

// TODO: possibly rework, to make them consistent with device definitions.

/****************************************************************************
 * GPIO Connections
 *****************************************************************************/

// These are the GPIO bit offsets for the RGB LED on HiFive1 Board.
// These are also mapped to RGB LEDs on the Freedom E300 Arty
// FPGA Dev Kit.
// The LEDs are active low.
#define RED_LED_OFFSET   22
#define GREEN_LED_OFFSET 19
#define BLUE_LED_OFFSET  21

// These are the GPIO bit offsets for the different digital pins
// on the headers for both the HiFive1 Board and the Freedom E300
// Arty FPGA Dev Kit.
#define PIN_0_OFFSET 16
#define PIN_1_OFFSET 17
#define PIN_2_OFFSET 18
#define PIN_3_OFFSET 19
#define PIN_4_OFFSET 20
#define PIN_5_OFFSET 21
#define PIN_6_OFFSET 22
#define PIN_7_OFFSET 23
#define PIN_8_OFFSET 0
#define PIN_9_OFFSET 1
#define PIN_10_OFFSET 2
#define PIN_11_OFFSET 3
#define PIN_12_OFFSET 4
#define PIN_13_OFFSET 5
//#define PIN_14_OFFSET 8 //This pin is not connected on either board.
#define PIN_15_OFFSET 9
#define PIN_16_OFFSET 10
#define PIN_17_OFFSET 11
#define PIN_18_OFFSET 12
#define PIN_19_OFFSET 13

// These are *PIN* numbers, not
// GPIO Offset Numbers.
#define PIN_SPI1_SCK    (13u)
#define PIN_SPI1_MISO   (12u)
#define PIN_SPI1_MOSI   (11u)
#define PIN_SPI1_SS0    (10u)
#define PIN_SPI1_SS1    (14u)
#define PIN_SPI1_SS2    (15u)
#define PIN_SPI1_SS3    (16u)

#define SS_PIN_TO_CS_ID(x) \
  ((x==PIN_SPI1_SS0 ? 0 :		 \
    (x==PIN_SPI1_SS1 ? 1 :		 \
     (x==PIN_SPI1_SS2 ? 2 :		 \
      (x==PIN_SPI1_SS3 ? 3 :		 \
       -1)))))

#define HAS_HFXOSC 0
#define HAS_LFROSC_BYPASS 0

// #define HAS_BOARD_BUTTONS
// The HiFive1 board does not have a dedicated user button,
// but the WAKE button can be connected with an external wire
// to GPIO18. The button is active low.
#define BUTTON_0_OFFSET  18

#define INT_DEVICE_BUTTON_0 (sifive_fe310_interrupt_global_gpio0 + BUTTON_0_OFFSET)

// ----------------------------------------------------------------------------

#endif /* BONFIRE_ARTY_BOARD_DEFINES_H_ */
