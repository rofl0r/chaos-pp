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
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_SUB_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_MACHINE_SUB_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/machine.h>
#
# /* CHAOS_PP_SUB_MACHINE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SUB_MACHINE(x, y) \
        CHAOS_PP_MACHINE((, x, (0xchaos)(0xsub), y, (0xchaos)(0xstop),)) \
        /**/
#    define CHAOS_PP_SUB_MACHINE_ID() CHAOS_PP_SUB_MACHINE
#    define CHAOS_PP_SUB_MACHINE_ CHAOS_PP_LAMBDA(CHAOS_PP_SUB_MACHINE)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xchaos_0xsub(p, x, y, ...) \
        CHAOS_PP_IF(y)( \
            (, CHAOS_PP_DEC(x), (0xchaos)(0xsub), CHAOS_PP_DEC(y), p ## __VA_ARGS__), \
            (, x, p ## __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif
