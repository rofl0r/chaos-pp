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
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_MOD_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_MOD_H
#
# include <chaos/preprocessor/arithmetic/machine/sub.h>
# include <chaos/preprocessor/comparison/less.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/unless.h>
# include <chaos/preprocessor/debug/failure.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/machine.h>
#
# /* CHAOS_PP_MOD_MACHINE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MOD_MACHINE(x, y) \
        CHAOS_PP_UNLESS(y)(CHAOS_PP_FAILURE()) \
        CHAOS_PP_MACHINE((, x, (0xchaos)(0xmod), y, (0xchaos)(0xstop),)) \
        /**/
#    define CHAOS_PP_MOD_MACHINE_ID() CHAOS_PP_MOD_MACHINE
#    define CHAOS_PP_MOD_MACHINE_ CHAOS_PP_LAMBDA(CHAOS_PP_MOD_MACHINE)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xchaos_0xmod(p, x, y, ...) \
        CHAOS_PP_IIF(CHAOS_PP_LESS(x, y))( \
            (, x, p ## __VA_ARGS__), \
            (, x, (0xchaos)(0xsub), y, (0xchaos)(0xmod), y, p ## __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif
