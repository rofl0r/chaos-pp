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
# /* CHAOS_PP_PLACEHOLDERS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PLACEHOLDERS(bit) CHAOS_PP_PRIMITIVE_CAT_SHADOW(CHAOS_IP_PLACEHOLDERS_, bit)
#    define CHAOS_PP_PLACEHOLDERS_ID() CHAOS_PP_PLACEHOLDERS
#    define CHAOS_PP_PLACEHOLDERS_ CHAOS_PP_LAMBDA(CHAOS_PP_PLACEHOLDERS)
#    define CHAOS_IP_PLACEHOLDERS_0 "chaos/preprocessor/lambda/detail/placeholders_0.h"
#    define CHAOS_IP_PLACEHOLDERS_1 "chaos/preprocessor/lambda/detail/placeholders_1.h"
# endif
#
# endif
