# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2004.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_MUL_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_MUL_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/arithmetic/machine/add.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/machine.h>
#
# /* CHAOS_PP_MUL_MACHINE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MUL_MACHINE(x, y) \
        CHAOS_PP_MACHINE((, x, (0xchaos)(0xmul), y, (0xchaos)(0xstop),)) \
        /**/
#    define CHAOS_PP_MUL_MACHINE_ID() CHAOS_PP_MUL_MACHINE
#    define CHAOS_PP_MUL_MACHINE_ CHAOS_PP_LAMBDA(CHAOS_PP_MUL_MACHINE)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xchaos_0xmul(p, x, y, ...) \
        CHAOS_PP_INSTRUCTION(0xchaos)(0xdetail)(0xmul)(, 0, x, y, p ## __VA_ARGS__) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xchaos_0xdetail_0xmul(p, r, x, y, ...) \
        CHAOS_PP_IF(y)( \
            (, r, (0xchaos)(0xadd), x, (0xchaos)(0xdetail)(0xmul), x, CHAOS_PP_DEC(y), p ## __VA_ARGS__), \
            (, r, p ## __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif
