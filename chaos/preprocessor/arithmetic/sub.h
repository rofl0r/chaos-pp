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
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_SUB_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_SUB_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/and.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/phase.h>
# include <chaos/preprocessor/seq/core.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_SUB */
#
# define CHAOS_PP_SUB(x, y) CHAOS_PP_SUB_BYPASS(CHAOS_PP_LIMIT_EXPR, x, y)
# define CHAOS_PP_SUB_ID() CHAOS_PP_SUB
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SUB_ CHAOS_PP_LAMBDA(CHAOS_PP_SUB)
# endif
#
# /* CHAOS_PP_SUB_BYPASS */
#
# define CHAOS_PP_SUB_BYPASS(s, x, y) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_SUB_I(CHAOS_PP_PREV(s), (CHAOS_PP_PREV(s)), x, y)) \
    /**/
# define CHAOS_PP_SUB_BYPASS_ID() CHAOS_PP_SUB_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SUB_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_SUB_BYPASS)
# endif
#
# define CHAOS_IP_SUB_INDIRECT() CHAOS_IP_SUB_I
# define CHAOS_IP_SUB_I(s, jump, x, y) \
    CHAOS_PP_IIF(CHAOS_PP_IS_VALID(CHAOS_PP_PREV(CHAOS_PP_PREV(s))))( \
        CHAOS_PP_IIF(CHAOS_PP_IS_VALID(CHAOS_PP_PREV(s)))( \
            CHAOS_IP_SUB_II, CHAOS_IP_SUB_III \
        ), \
        CHAOS_IP_SUB_IV \
    )(CHAOS_PP_PHASE(0), s, jump, x, y) \
    /**/
# define CHAOS_IP_SUB_II(_, s, jump, x, y) \
    _(1, CHAOS_PP_EXPR_S)(s)( \
        CHAOS_IP_SUB_III(_, s, (CHAOS_PP_PREV(s)) jump, x, y) \
    ) \
    /**/
# define CHAOS_IP_SUB_III(_, s, jump, x, y) \
    _(1, CHAOS_PP_IIF)(CHAOS_PP_AND(x)(y))( \
        _(1, CHAOS_PP_EXPR_S)(s), x CHAOS_PP_EAT \
    )( \
        _(1, CHAOS_IP_SUB_INDIRECT)()( \
            CHAOS_PP_PREV(s), jump, CHAOS_PP_DEC(x), CHAOS_PP_DEC(y) \
        ) \
    ) \
    /**/
# define CHAOS_IP_SUB_IV(_, s, jump, x, y) CHAOS_IP_SUB_V(CHAOS_PP_SEQ_HEAD(jump), CHAOS_PP_SEQ_TAIL(jump), x, y)
# define CHAOS_IP_SUB_V(s, jump, x, y) \
    CHAOS_PP_IIF(CHAOS_PP_IS_VALID(CHAOS_PP_PREV(s)))( \
        CHAOS_IP_SUB_II, CHAOS_IP_SUB_III \
    )(CHAOS_PP_PHASE(1), s, CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_NIL(jump))((s), jump), x, y) \
    /**/
#
# endif
