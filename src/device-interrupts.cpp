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

#include <micro-os-plus/board.h>

#include <stddef.h>
#include <stdbool.h>

// ----------------------------------------------------------------------------

#if defined (BONFIRE_ARTY_BOARD)

extern "C"
{
  void
  bonfire_arty_interrupt_handle_unused (void);
}

namespace bonfire
{
  namespace arty
  {
    namespace interrupt
    {
      // ----------------------------------------------------------------------

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_unused (void);

      // ----------------------------------------------------------------------
    }
  }
}

// ----------------------------------------------------------------------------

// To provide the desired functionality, redefine any of these
// functions in the application.

#if defined(OS_USE_CPP_INTERRUPTS)

namespace bonfire
{
  namespace arty
  {
    namespace interrupt
    {
      // ----------------------------------------------------------------------


      // ----------------------------------------------------------------------
    }
  }
}

#else


#endif /* defined(OS_USE_CPP_INTERRUPTS) */

#if defined(RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER)

namespace riscv
{
  namespace core
  {
    // ------------------------------------------------------------------------

    // Array of pointers to interrupt handlers. See Table 3.6 from Volume II.
    riscv::core::trap_handler_ptr_t __attribute__ ((section(".interrupts_global_array")))
    global_interrupt_handlers[] =
      {
#if defined(OS_USE_CPP_INTERRUPTS)


#else /* defined(OS_USE_CPP_INTERRUPTS) */


#endif /* defined(OS_USE_CPP_INTERRUPTS) */
      };

    // ------------------------------------------------------------------------
  } /* namespace core */
} /* namespace riscv */

static_assert(
    sizeof(riscv::core::global_interrupt_handlers)/
      sizeof(riscv::core::global_interrupt_handlers[0]) ==
        (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER + 1),
    "riscv::core::global_interrupt_handlers[] size must match RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER");

// ----------------------------------------------------------------------------

#endif


#if defined(OS_USE_CPP_INTERRUPTS)

namespace riscv
{
  namespace interrupt
  {
    // ------------------------------------------------------------------------

    // Architecture interrupts.
    void
    __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
    handle_machine_software (void);

    void
    __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
    handle_machine_timer (void);

    #if defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER)

    extern void
    handle_machine_ext (void);

    #else

    // Defined in the architecture package.
    void
    __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
    handle_machine_ext (void);

    #endif /* defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER) */

    // ------------------------------------------------------------------------
  } /* namespace interrupt */
} /* namespace riscv */

namespace bonfire
{
  namespace arty
  {
    namespace interrupt
    {
      // ----------------------------------------------------------------------
      // Device local interrupts.

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device0 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device1 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device2 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device3 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device4 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device5 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device6 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device7 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device8 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device9 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device10 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device11 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device12 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device13 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device14 (void);

      void
      __attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
      handle_local_device15 (void);

      // ----------------------------------------------------------------------
    }
  }
}

#else /* defined(OS_USE_CPP_INTERRUPTS) */

// Architecture interrupts.
void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
riscv_interrupt_handle_machine_software (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
riscv_interrupt_handle_machine_timer (void);

#if defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER)

extern void
riscv_interrupt_handle_machine_ext (void);

#else

// Defined in the architecture package.
void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
riscv_interrupt_handle_machine_ext (void);

#endif /* defined (RISCV_INTERRUPTS_GLOBAL_LAST_NUMBER) */

// Device local interrupts.
void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device0 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device1 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device2 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device3 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device4 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device5 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device6 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device7 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device8 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device9 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device10 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device11 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device12 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device13 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device14 (void);

void
__attribute__ ((weak, alias ("bonfire_arty_interrupt_handle_unused")))
bonfire_arty_interrupt_handle_local_device15 (void);

#endif /* defined(OS_USE_CPP_INTERRUPTS) */

namespace riscv
{
  namespace core
  {
    // ------------------------------------------------------------------------

    // Array of pointers to interrupt handlers. See Table 3.6 from Volume II.
    riscv::core::trap_handler_ptr_t __attribute__ ((section(".interrupts_local_array")))
    local_interrupt_handlers[] =
      {
#if defined(OS_USE_CPP_INTERRUPTS)

        // Architecture interrupts.
        bonfire::arty::interrupt::handle_unused, /* 0 */
        bonfire::arty::interrupt::handle_unused, /* 1 */
        bonfire::arty::interrupt::handle_unused, /* 2 */
        riscv::interrupt::handle_machine_software, /* 3 */
        bonfire::arty::interrupt::handle_unused, /* 4 */
        bonfire::arty::interrupt::handle_unused, /* 5 */
        bonfire::arty::interrupt::handle_unused, /* 6 */
        riscv::interrupt::handle_machine_timer, /* 7 */
        bonfire::arty::interrupt::handle_unused, /* 8 */
        bonfire::arty::interrupt::handle_unused, /* 9 */
        bonfire::arty::interrupt::handle_unused, /* 10 */
        riscv::interrupt::handle_machine_ext, /* 11 */
        bonfire::arty::interrupt::handle_unused, /* 12 */
        bonfire::arty::interrupt::handle_unused, /* 13 */
        bonfire::arty::interrupt::handle_unused, /* 14 */
        bonfire::arty::interrupt::handle_unused, /* 15 */

        // Device local interrupts.
        bonfire::arty::interrupt::handle_local_device0, /* 16 */
        bonfire::arty::interrupt::handle_local_device1, /* 17 */
        bonfire::arty::interrupt::handle_local_device2, /* 18 */
        bonfire::arty::interrupt::handle_local_device3, /* 19 */
        bonfire::arty::interrupt::handle_local_device4, /* 20 */
        bonfire::arty::interrupt::handle_local_device5, /* 21 */
        bonfire::arty::interrupt::handle_local_device6, /* 22 */
        bonfire::arty::interrupt::handle_local_device7, /* 23 */
        bonfire::arty::interrupt::handle_local_device8, /* 24 */
        bonfire::arty::interrupt::handle_local_device9, /* 25 */
        bonfire::arty::interrupt::handle_local_device10, /* 26 */
        bonfire::arty::interrupt::handle_local_device11, /* 27 */
        bonfire::arty::interrupt::handle_local_device12, /* 28 */
        bonfire::arty::interrupt::handle_local_device13, /* 29 */
        bonfire::arty::interrupt::handle_local_device14, /* 30 */
        bonfire::arty::interrupt::handle_local_device15 /* 31 */

#else /* defined(OS_USE_CPP_INTERRUPTS) */

        // Architecture interrupts.
        bonfire_arty_interrupt_handle_unused, /* 0 */
        bonfire_arty_interrupt_handle_unused, /* 1 */
        bonfire_arty_interrupt_handle_unused, /* 2 */
        riscv_interrupt_handle_machine_software, /* 3 */
        bonfire_arty_interrupt_handle_unused, /* 4 */
        bonfire_arty_interrupt_handle_unused, /* 5 */
        bonfire_arty_interrupt_handle_unused, /* 6 */
        riscv_interrupt_handle_machine_timer, /* 7 */
        bonfire_arty_interrupt_handle_unused, /* 8 */
        bonfire_arty_interrupt_handle_unused, /* 9 */
        bonfire_arty_interrupt_handle_unused, /* 10 */
        riscv_interrupt_handle_machine_ext, /* 11 */
        bonfire_arty_interrupt_handle_unused, /* 12 */
        bonfire_arty_interrupt_handle_unused, /* 13 */
        bonfire_arty_interrupt_handle_unused, /* 14 */
        bonfire_arty_interrupt_handle_unused, /* 15 */

        // Device local interrupts.
        bonfire_arty_interrupt_handle_local_device0, /* 16 */
        bonfire_arty_interrupt_handle_local_device1, /* 17 */
        bonfire_arty_interrupt_handle_local_device2, /* 18 */
        bonfire_arty_interrupt_handle_local_device3, /* 19 */
        bonfire_arty_interrupt_handle_local_device4, /* 20 */
        bonfire_arty_interrupt_handle_local_device5, /* 21 */
        bonfire_arty_interrupt_handle_local_device6, /* 22 */
        bonfire_arty_interrupt_handle_local_device7, /* 23 */
        bonfire_arty_interrupt_handle_local_device8, /* 24 */
        bonfire_arty_interrupt_handle_local_device9, /* 25 */
        bonfire_arty_interrupt_handle_local_device10, /* 26 */
        bonfire_arty_interrupt_handle_local_device11, /* 27 */
        bonfire_arty_interrupt_handle_local_device12, /* 28 */
        bonfire_arty_interrupt_handle_local_device13, /* 29 */
        bonfire_arty_interrupt_handle_local_device14, /* 30 */
        bonfire_arty_interrupt_handle_local_device15 /* 31 */

#endif /* defined(OS_USE_CPP_INTERRUPTS) */
      };

    // ------------------------------------------------------------------------
  } /* namespace core */
} /* namespace riscv */

static_assert(
    sizeof(riscv::core::local_interrupt_handlers)/
      sizeof(riscv::core::local_interrupt_handlers[0]) ==
        (RISCV_INTERRUPTS_LOCAL_LAST_NUMBER + 1),
    "riscv::core::local_interrupt_handlers[] size must match RISCV_INTERRUPTS_LOCAL_LAST_NUMBER");

// ----------------------------------------------------------------------------

void
__attribute__ ((section(".traps_handlers"),weak))
bonfire_arty_interrupt_handle_unused (void)
{
#if defined(DEBUG)
  //riscv::arch::ebreak ();
#endif /* defined(DEBUG) */

  while (true)
    {
   //   riscv::arch::wfi ();
    }
}

#endif /* DEVICE */

// ----------------------------------------------------------------------------
