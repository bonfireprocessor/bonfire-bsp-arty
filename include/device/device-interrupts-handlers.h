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
 *
 * Adaptions to bonfire project (c) 2018 Thomas Hornschuh
 *
 */

#ifndef BONFIRE_ARTY_DEVICE_INTERRUPTS_HANDLERS_H_
#define BONFIRE_ARTY_DEVICE_INTERRUPTS_HANDLERS_H_

/*
 * Bonfire ARTY Device Interrupt Handlers
 */

#if defined(__cplusplus) && defined(OS_USE_CPP_INTERRUPTS)


namespace riscv
{
  namespace interrupt
  {
    // ------------------------------------------------------------------------
    // Local interrupt handlers.

    // Architecture common handlers.
    void
    handle_machine_software (void);

    void
    handle_machine_timer (void);

    void
    handle_machine_ext (void);

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
      // Device specific handlers.

      void
      handle_local_device0 (void);

      void
      handle_local_device1 (void);

      void
      handle_local_device2 (void);

      void
      handle_local_device3 (void);

      void
      handle_local_device4 (void);

      void
      handle_local_device5 (void);

      void
      handle_local_device6 (void);

      void
      handle_local_device7 (void);

      void
      handle_local_device8 (void);

      void
      handle_local_device9 (void);

      void
      handle_local_device10 (void);

      void
      handle_local_device11 (void);

      void
      handle_local_device12 (void);

      void
      handle_local_device13 (void);

      void
      handle_local_device14 (void);

      void
      handle_local_device15 (void);

      // ----------------------------------------------------------------------
    } /* namespace interrupt */
  } /* namespace e51arty */
} /* namespace sifive */

#else /* defined(__cplusplus) && defined(OS_USE_CPP_INTERRUPTS) */

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
extern "C"
{
#endif /* defined(__cplusplus) */

  // --------------------------------------------------------------------------
  // Global interrupt handlers. 


  // --------------------------------------------------------------------------
  // Local interrupt handlers.

  // Architecture common handlers.
  void
  riscv_interrupt_handle_machine_software (void);

  void
  riscv_interrupt_handle_machine_timer (void);

  void
  riscv_interrupt_handle_machine_ext (void);

  // Device specific handlers.
  void
  bonfire_arty_interrupt_handle_local_device0 (void);

  void
  bonfire_arty_interrupt_handle_local_device1 (void);

  void
  bonfire_arty_interrupt_handle_local_device2 (void);

  void
  bonfire_arty_interrupt_handle_local_device3 (void);

  void
  bonfire_arty_interrupt_handle_local_device4 (void);

  void
  bonfire_arty_interrupt_handle_local_device5 (void);

  void
  bonfire_arty_interrupt_handle_local_device6 (void);

  void
  bonfire_arty_interrupt_handle_local_device7 (void);

  void
  bonfire_arty_interrupt_handle_local_device8 (void);

  void
  bonfire_arty_interrupt_handle_local_device9 (void);

  void
  bonfire_arty_interrupt_handle_local_device10 (void);

  void
  bonfire_arty_interrupt_handle_local_device11 (void);

  void
  bonfire_arty_interrupt_handle_local_device12 (void);

  void
  bonfire_arty_interrupt_handle_local_device13 (void);

  void
  bonfire_arty_interrupt_handle_local_device14 (void);

  void
  bonfire_arty_interrupt_handle_local_device15 (void);

// ----------------------------------------------------------------------------

#if defined(__cplusplus)
}
#endif /* defined(__cplusplus) */

#endif /* defined(__cplusplus) && defined(OS_USE_CPP_INTERRUPTS) */

// ----------------------------------------------------------------------------

#endif /* SIFIVE_DEVICES_ARTY_E51_DEVICE_INTERRUPTS_HANDLERS_H_ */
