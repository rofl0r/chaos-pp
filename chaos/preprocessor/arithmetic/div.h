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
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_DIV_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_DIV_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/comparison/less.h>
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/debug/failure.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/not.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/phase.h>
# include <chaos/preprocessor/seq/core.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_DIV */
#
# define CHAOS_PP_DIV(x, y) CHAOS_PP_DIV_BYPASS(CHAOS_PP_LIMIT_EXPR, x, y)
# define CHAOS_PP_DIV_ID() CHAOS_PP_DIV
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DIV_ CHAOS_PP_LAMBDA(CHAOS_PP_DIV)
# endif
#
# /* CHAOS_PP_DIV_BYPASS */
#
# define CHAOS_PP_DIV_BYPASS(s, x, y) \
    CHAOS_PP_INLINE_WHEN(CHAOS_PP_NOT(y))(CHAOS_PP_FAILURE()) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_DIV_I(CHAOS_PP_PREV(s), (CHAOS_PP_PREV(s)), 0, 0, x, y, 0, 0)) \
    /**/
# define CHAOS_PP_DIV_BYPASS_ID() CHAOS_PP_DIV_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DIV_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_DIV_BYPASS_ID)()
# endif
#
# define CHAOS_IP_DIV_INDIRECT() CHAOS_IP_DIV_I
# define CHAOS_IP_DIV_I(s, jump, mode, r, x, y, z, ex) \
    CHAOS_PP_IIF(CHAOS_PP_IS_VALID(CHAOS_PP_PREV(CHAOS_PP_PREV(s))))( \
        CHAOS_PP_IIF(CHAOS_PP_IS_VALID(CHAOS_PP_PREV(s)))( \
            CHAOS_IP_DIV_II, CHAOS_IP_DIV_ ## mode \
        ), \
        CHAOS_IP_DIV_III \
    )(CHAOS_PP_PHASE(0), s, jump, mode, r, x, y, z, ex) \
    /**/
# define CHAOS_IP_DIV_II(_, s, jump, mode, r, x, y, z, ex) \
    _(1, CHAOS_PP_EXPR_S)(s)( \
        CHAOS_IP_DIV_ ## mode(_, s, (CHAOS_PP_PREV(s)) jump, mode, r, x, y, z, ex) \
    ) \
    /**/
# define CHAOS_IP_DIV_III(_, s, jump, mode, r, x, y, z, ex) \
    CHAOS_IP_DIV_IV(CHAOS_PP_SEQ_HEAD(jump), CHAOS_PP_SEQ_TAIL(jump), mode, r, x, y, z, ex) \
    /**/
# define CHAOS_IP_DIV_IV(s, jump, mode, r, x, y, z, ex) \
    CHAOS_PP_IIF(CHAOS_PP_IS_VALID(CHAOS_PP_PREV(s)))( \
        CHAOS_IP_DIV_II, CHAOS_IP_DIV_ ## mode \
    )(CHAOS_PP_PHASE(1), s, CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_NIL(jump))((s), jump), mode, r, x, y, z, ex) \
    /**/
# define CHAOS_IP_DIV_0(_, s, jump, mode, r, x, y, z, ex) \
    CHAOS_PP_IIF(CHAOS_PP_LESS(x, y))( \
        CHAOS_PP_BINARY(ex)(r, x) CHAOS_PP_TUPLE_EAT(7), CHAOS_IP_DIV_1 \
    )(_, s, jump, mode, CHAOS_PP_INC(r), x, y, y, ex) \
    /**/
# define CHAOS_IP_DIV_1(_, s, jump, mode, r, x, y, z, ex) \
    _(1, CHAOS_PP_EXPR_S)(s)(_(1, CHAOS_IP_DIV_INDIRECT)()( \
        CHAOS_PP_PREV(s), jump, \
        CHAOS_PP_TUPLE_REM_CTOR(5, CHAOS_PP_IF(z)( \
            (1, r, CHAOS_PP_DEC(x), y, CHAOS_PP_DEC(z)), \
            (0, r, x, y, 0) \
        )), \
        ex \
    )) \
    /**/
#
# endif
