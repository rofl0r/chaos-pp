# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_DIV_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_DIV_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/arithmetic/machine/sub.h>
# include <chaos/preprocessor/comparison/less.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/unless.h>
# include <chaos/preprocessor/debug/failure.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/machine.h>
#
# /* CHAOS_PP_DIV_MACHINE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DIV_MACHINE(x, y) \
        CHAOS_PP_UNLESS(y)(CHAOS_PP_FAILURE()) \
        CHAOS_PP_MACHINE((, x, (0xchaos)(0xdiv), y, (0xchaos)(0xstop),)) \
        /**/
#    define CHAOS_PP_DIV_MACHINE_ID() CHAOS_PP_DIV_MACHINE
#    define CHAOS_PP_DIV_MACHINE_ CHAOS_PP_LAMBDA(CHAOS_PP_DIV_MACHINE)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xchaos_0xdiv(p, x, y, ...) \
        CHAOS_PP_INSTRUCTION(0xchaos)(0xdetail)(0xdiv)(, x, y, 0, p ## __VA_ARGS__) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xchaos_0xdetail_0xdiv(p, x, y, r, ...) \
        CHAOS_PP_IIF(CHAOS_PP_LESS(x, y))( \
            (, r, p ## __VA_ARGS__), \
            (, x, (0xchaos)(0xsub), y, (0xchaos)(0xdetail)(0xdiv), y, CHAOS_PP_INC(r), p ## __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif
