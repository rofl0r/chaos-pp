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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_IS_SHORTER_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_IS_SHORTER_H
#
# include <chaos/preprocessor/arbitrary/detail/namespace.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/recursion/machine.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xIS_SHORTER */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_0xIS_SHORTER(s, p, x, y, k, ...) \
        CHAOS_PP_IIF(CHAOS_PP_IS_VARIADIC(p ## x))( \
            CHAOS_PP_IIF(CHAOS_PP_IS_VARIADIC(p ## y))( \
                (, 0xCHAOS(0xARBITRARY(0xIS_SHORTER)), CHAOS_PP_TUPLE_EAT(?) p ## x, CHAOS_PP_TUPLE_EAT(?) p ## y, k, p ## __VA_ARGS__), \
                (, k, 0, p ## __VA_ARGS__) \
            ), \
            (, k, CHAOS_PP_IS_VARIADIC(p ## y), p ## __VA_ARGS__) \
        ) \
        /**/
# endif
#
# endif
