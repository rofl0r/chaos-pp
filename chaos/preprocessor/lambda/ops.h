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
# ifndef CHAOS_PREPROCESSOR_LAMBDA_OPS_H
# define CHAOS_PREPROCESSOR_LAMBDA_OPS_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/null.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_FLAG */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FLAG(...) (,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,, __VA_ARGS__)
#    define CHAOS_PP_FLAG_ID() CHAOS_PP_FLAG
#    define CHAOS_PP_FLAG_ CHAOS_PP_LAMBDA(CHAOS_PP_FLAG_ID)()
# endif
#
# /* CHAOS_PP_FLAG_NAME */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FLAG_NAME(x)  \
        CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_FLAG_NAME_I)(CHAOS_PP_REM x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,)) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_FLAG_NAME_I(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, id, ...) id
# endif
#
# /* CHAOS_PP_FLAG_DATA */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FLAG_DATA(x) \
        CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_FLAG_DATA_I)(CHAOS_PP_REM x,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,)) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_FLAG_DATA_I(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, id, data, ...) CHAOS_PP_REM data
# endif
#
# /* CHAOS_PP_LAMBDA */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LAMBDA(...) CHAOS_PP_FLAG(0xLAMBDA, (__VA_ARGS__))
#    define CHAOS_PP_LAMBDA_ID() CHAOS_PP_LAMBDA
#    define CHAOS_PP_LAMBDA_ CHAOS_PP_LAMBDA(CHAOS_PP_LAMBDA_ID)()
# endif
#
# /* CHAOS_PP_ESCAPE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ESCAPE(...) CHAOS_PP_FLAG(0xESCAPE, (__VA_ARGS__))
#    define CHAOS_PP_ESCAPE_ID() CHAOS_PP_ESCAPE
#    define CHAOS_PP_ESCAPE_ CHAOS_PP_LAMBDA(CHAOS_PP_ESCAPE_ID)()
# endif
#
# /* CHAOS_PP_OVERRIDE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_OVERRIDE(...) (CHAOS_PP_LAMBDA(__VA_ARGS__))
#    define CHAOS_PP_OVERRIDE_ID() CHAOS_PP_OVERRIDE
#    define CHAOS_PP_OVERRIDE_ CHAOS_PP_LAMBDA(CHAOS_PP_OVERRIDE_ID)()
# endif
#
# /* CHAOS_PP_SELF */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SELF() CHAOS_PP_FLAG(0xSELF)
#    define CHAOS_PP_SELF_ID() CHAOS_PP_SELF
#    define CHAOS_PP_SELF_ CHAOS_PP_LAMBDA(CHAOS_PP_SELF)
# endif
#
# /* CHAOS_PP_ARG */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARG(n) CHAOS_PP_FLAG(0xARG, (n))
#    define CHAOS_PP_ARG_ID() CHAOS_PP_ARGS
#    define CHAOS_PP_ARG_ CHAOS_PP_LAMBDA(CHAOS_PP_ARG)
# endif
#
# /* CHAOS_PP_PLACEHOLDERS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PLACEHOLDERS(bit) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_PLACEHOLDERS_, bit)
#    define CHAOS_PP_PLACEHOLDERS_ID() CHAOS_PP_PLACEHOLDERS
#    define CHAOS_PP_PLACEHOLDERS_ CHAOS_PP_LAMBDA(CHAOS_PP_PLACEHOLDERS)
# else
#    define CHAOS_PP_PLACEHOLDERS(bit) CHAOS_PP_NULL()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_PLACEHOLDERS_0 "chaos/preprocessor/lambda/detail/placeholders_0.h"
#    define CHAOS_IP_PLACEHOLDERS_1 "chaos/preprocessor/lambda/detail/placeholders_1.h"
# endif
#
# /* CHAOS_PP_WITH_PLACEHOLDERS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WITH_PLACEHOLDERS() "chaos/preprocessor/lambda/detail/with_placeholders.h"
#    define CHAOS_PP_WITH_PLACEHOLDERS_ID() CHAOS_PP_WITH_PLACEHOLDERS
#    define CHAOS_PP_WITH_PLACEHOLDERS_ CHAOS_PP_LAMBDA(CHAOS_PP_WITH_PLACEHOLDERS)
# endif
#
# endif
