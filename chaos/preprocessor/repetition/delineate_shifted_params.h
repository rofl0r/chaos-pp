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
# ifndef CHAOS_PREPROCESSOR_DELINEATE_SHIFTED_PARAMS_H
# define CHAOS_PREPROCESSOR_DELINEATE_SHIFTED_PARAMS_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/when.h>
# include <chaos/preprocessor/detection/is_binary.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_DELINEATE_SHIFTED_PARAMS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_SHIFTED_PARAMS(count, sep, ...) CHAOS_PP_DELINEATE_SHIFTED_PARAMS_BYPASS(CHAOS_PP_LIMIT_EXPR, count, sep, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_SHIFTED_PARAMS_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_SHIFTED_PARAMS_ID)()
# else
#    define CHAOS_PP_DELINEATE_SHIFTED_PARAMS(count, sep, param) CHAOS_PP_DELINEATE_SHIFTED_PARAMS_BYPASS(CHAOS_PP_LIMIT_EXPR, count, sep, param)
# endif
#
# define CHAOS_PP_DELINEATE_SHIFTED_PARAMS_ID() CHAOS_PP_DELINEATE_SHIFTED_PARAMS
#
# /* CHAOS_PP_DELINEATE_SHIFTED_PARAMS_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_SHIFTED_PARAMS_BYPASS(s, count, sep, ...) CHAOS_IP_DELINEATE_SHIFTED_PARAMS_U(s, CHAOS_PP_IS_VARIADIC(__VA_ARGS__), count, sep, (__VA_ARGS__))
#    define CHAOS_PP_DELINEATE_SHIFTED_PARAMS_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_SHIFTED_PARAMS_BYPASS_ID)()
# else
#    define CHAOS_PP_DELINEATE_SHIFTED_PARAMS_BYPASS(s, count, sep, param) CHAOS_IP_DELINEATE_SHIFTED_PARAMS_U(s, CHAOS_PP_IS_BINARY(param), count, sep, (param))
# endif
#
# define CHAOS_PP_DELINEATE_SHIFTED_PARAMS_BYPASS_ID() CHAOS_PP_DELINEATE_SHIFTED_PARAMS_BYPASS
#
# define CHAOS_IP_DELINEATE_SHIFTED_PARAMS_U(s, id, count, sep, pp) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_DELINEATE_SHIFTED_PARAMS_I( \
        CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), id, CHAOS_PP_DEC(count), CHAOS_PP_EMPTY, sep, pp \
    )) \
    /**/
# define CHAOS_IP_DELINEATE_SHIFTED_PARAMS_INDIRECT() CHAOS_IP_DELINEATE_SHIFTED_PARAMS_I
# define CHAOS_IP_DELINEATE_SHIFTED_PARAMS_I(_, s, id, count, sep, ss, pp) \
    CHAOS_PP_WHEN _(count)( \
        CHAOS_PP_EXPR_S(s) _(CHAOS_IP_DELINEATE_SHIFTED_PARAMS_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), id, CHAOS_PP_DEC(count), ss, ss, pp \
        )) \
        CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_DELINEATE_SHIFTED_PARAMS_, id) _(count, CHAOS_PP_REM pp) sep _() \
    ) \
    /**/
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_DELINEATE_SHIFTED_PARAMS_0(c, ...) __VA_ARGS__ ## c
#    define CHAOS_IP_DELINEATE_SHIFTED_PARAMS_1(c, ...) CHAOS_PP_DEFER(CHAOS_IP_DELINEATE_SHIFTED_PARAMS_2)(c, CHAOS_PP_REM __VA_ARGS__)
#    define CHAOS_IP_DELINEATE_SHIFTED_PARAMS_2(c, a, ...) a ## c __VA_ARGS__ ## c
# else
#    define CHAOS_IP_DELINEATE_SHIFTED_PARAMS_0(c, param) param ## c
#    define CHAOS_IP_DELINEATE_SHIFTED_PARAMS_1(c, param) CHAOS_PP_DEFER(CHAOS_IP_DELINEATE_SHIFTED_PARAMS_2)(c, CHAOS_PP_TUPLE_REM(2) param)
#    define CHAOS_IP_DELINEATE_SHIFTED_PARAMS_2(c, a, b) a ## c b ## c
# endif
#
# endif
