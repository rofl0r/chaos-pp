# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_LAMBDA_OPS_H
# define CHAOS_PREPROCESSOR_LAMBDA_OPS_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/facilities/bind.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_FLAG */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FLAG(...) CHAOS_IP_FLAG_I(, __VA_ARGS__)
#    define CHAOS_PP_FLAG_ID() CHAOS_PP_FLAG
#    define CHAOS_PP_FLAG_ CHAOS_PP_LAMBDA(CHAOS_PP_FLAG_ID)()
#    define CHAOS_IP_FLAG_I(_, ...) \
        _(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(_(__VA_ARGS__)))))))))))))))))))))))))))))))))))))))))))))))))) \
        /**/
#    define CHAOS_IP_FLAG_O(...) CHAOS_PP_TUPLE_REM(?) __VA_ARGS__
#    define CHAOS_IP_FLAG_C(...) CHAOS_PP_IS_VARIADIC(CHAOS_IP_FLAG_I(CHAOS_IP_FLAG_O, (__VA_ARGS__)))
# endif
#
# /* CHAOS_PP_FLAG_NAME */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FLAG_NAME(x) \
        CHAOS_PP_EXPR_IIF(CHAOS_IP_FLAG_C(x))( \
            CHAOS_IP_FLAG_NAME_I(CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_PP_SPLIT)(0, CHAOS_IP_FLAG_I(CHAOS_IP_FLAG_O, x),))) \
        ) \
        /**/
#    define CHAOS_IP_FLAG_NAME_I(x) CHAOS_PP_EXPR_IIF(CHAOS_PP_COMPL(CHAOS_PP_IS_VARIADIC(x)))(x)
# endif
#
# /* CHAOS_PP_FLAG_DATA */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FLAG_DATA(x) \
        CHAOS_PP_EXPR_IIF(CHAOS_IP_FLAG_C(x))( \
            CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_PP_SPLIT)(1, CHAOS_IP_FLAG_I(CHAOS_IP_FLAG_O, x))) \
        ) \
        /**/
# endif
#
# /* CHAOS_PP_LAMBDA */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LAMBDA(...) CHAOS_PP_FLAG(0xLAMBDA, __VA_ARGS__)
#    define CHAOS_PP_LAMBDA_ID() CHAOS_PP_LAMBDA
#    define CHAOS_PP_LAMBDA_ CHAOS_PP_LAMBDA(CHAOS_PP_LAMBDA_ID)()
# endif
#
# /* CHAOS_PP_ESCAPE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ESCAPE(...) CHAOS_PP_FLAG(0xESCAPE, __VA_ARGS__)
#    define CHAOS_PP_ESCAPE_ID() CHAOS_PP_ESCAPE
#    define CHAOS_PP_ESCAPE_ CHAOS_PP_LAMBDA(CHAOS_PP_ESCAPE_ID)()
# endif
#
# /* CHAOS_PP_OPEN */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_OPEN(...) CHAOS_PP_FLAG(0xOPEN, __VA_ARGS__)
#    define CHAOS_PP_OPEN_ID() CHAOS_PP_OPEN
#    define CHAOS_PP_OPEN_ CHAOS_PP_LAMBDA(CHAOS_PP_OPEN_ID)()
# endif
#
# /* CHAOS_PP_SELF */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SELF() CHAOS_PP_FLAG(0xSELF)
#    define CHAOS_PP_SELF_ID() CHAOS_PP_SELF
#    define CHAOS_PP_SELF_ CHAOS_PP_LAMBDA(CHAOS_PP_SELF_ID)()
# endif
#
# /* CHAOS_PP_PARAM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PARAM(n) CHAOS_PP_FLAG(0xPARAM, n)
#    define CHAOS_PP_PARAM_ID() CHAOS_PP_PARAMS
#    define CHAOS_PP_PARAM_ CHAOS_PP_LAMBDA(CHAOS_PP_PARAM)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_0 CHAOS_PP_PARAM(0)
#    define CHAOS_PP_1 CHAOS_PP_PARAM(1)
#    define CHAOS_PP_2 CHAOS_PP_PARAM(2)
#    define CHAOS_PP_3 CHAOS_PP_PARAM(3)
#    define CHAOS_PP_4 CHAOS_PP_PARAM(4)
#    define CHAOS_PP_5 CHAOS_PP_PARAM(5)
#    define CHAOS_PP_6 CHAOS_PP_PARAM(6)
#    define CHAOS_PP_7 CHAOS_PP_PARAM(7)
#    define CHAOS_PP_8 CHAOS_PP_PARAM(8)
#    define CHAOS_PP_9 CHAOS_PP_PARAM(9)
#    define CHAOS_PP_10 CHAOS_PP_PARAM(10)
#    define CHAOS_PP_11 CHAOS_PP_PARAM(11)
#    define CHAOS_PP_12 CHAOS_PP_PARAM(12)
#    define CHAOS_PP_13 CHAOS_PP_PARAM(13)
#    define CHAOS_PP_14 CHAOS_PP_PARAM(14)
#    define CHAOS_PP_15 CHAOS_PP_PARAM(15)
#    define CHAOS_PP_16 CHAOS_PP_PARAM(16)
#    define CHAOS_PP_17 CHAOS_PP_PARAM(17)
#    define CHAOS_PP_18 CHAOS_PP_PARAM(18)
#    define CHAOS_PP_19 CHAOS_PP_PARAM(19)
#    define CHAOS_PP_20 CHAOS_PP_PARAM(20)
#    define CHAOS_PP_21 CHAOS_PP_PARAM(21)
#    define CHAOS_PP_22 CHAOS_PP_PARAM(22)
#    define CHAOS_PP_23 CHAOS_PP_PARAM(23)
#    define CHAOS_PP_24 CHAOS_PP_PARAM(24)
# endif
#
# if CHAOS_PP_VARIADICS && CHAOS_PP_NO_PREFIX
#    define _0 CHAOS_PP_ALTERNATE(_0, CHAOS_PP)
#    define _1 CHAOS_PP_ALTERNATE(_1, CHAOS_PP)
#    define _2 CHAOS_PP_ALTERNATE(_2, CHAOS_PP)
#    define _3 CHAOS_PP_ALTERNATE(_3, CHAOS_PP)
#    define _4 CHAOS_PP_ALTERNATE(_4, CHAOS_PP)
#    define _5 CHAOS_PP_ALTERNATE(_5, CHAOS_PP)
#    define _6 CHAOS_PP_ALTERNATE(_6, CHAOS_PP)
#    define _7 CHAOS_PP_ALTERNATE(_7, CHAOS_PP)
#    define _8 CHAOS_PP_ALTERNATE(_8, CHAOS_PP)
#    define _9 CHAOS_PP_ALTERNATE(_9, CHAOS_PP)
#    define _10 CHAOS_PP_ALTERNATE(_10, CHAOS_PP)
#    define _11 CHAOS_PP_ALTERNATE(_11, CHAOS_PP)
#    define _12 CHAOS_PP_ALTERNATE(_12, CHAOS_PP)
#    define _13 CHAOS_PP_ALTERNATE(_13, CHAOS_PP)
#    define _14 CHAOS_PP_ALTERNATE(_14, CHAOS_PP)
#    define _15 CHAOS_PP_ALTERNATE(_15, CHAOS_PP)
#    define _16 CHAOS_PP_ALTERNATE(_16, CHAOS_PP)
#    define _17 CHAOS_PP_ALTERNATE(_17, CHAOS_PP)
#    define _18 CHAOS_PP_ALTERNATE(_18, CHAOS_PP)
#    define _19 CHAOS_PP_ALTERNATE(_19, CHAOS_PP)
#    define _20 CHAOS_PP_ALTERNATE(_20, CHAOS_PP)
#    define _21 CHAOS_PP_ALTERNATE(_21, CHAOS_PP)
#    define _22 CHAOS_PP_ALTERNATE(_22, CHAOS_PP)
#    define _23 CHAOS_PP_ALTERNATE(_23, CHAOS_PP)
#    define _24 CHAOS_PP_ALTERNATE(_24, CHAOS_PP)
# endif
#
# endif
