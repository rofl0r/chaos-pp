# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2004.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_ADD_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_ADD_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/bitand.h>
# include <chaos/preprocessor/logical/bool.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/phase.h>
# include <chaos/preprocessor/seq/spec.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_ADD */
#
# define CHAOS_PP_ADD(x, y) CHAOS_PP_ADD_BYPASS(CHAOS_PP_LIMIT_EXPR, x, y)
# define CHAOS_PP_ADD_ID() CHAOS_PP_ADD
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ADD_ CHAOS_PP_LAMBDA(CHAOS_PP_ADD)
# endif
#
# /* CHAOS_PP_ADD_BYPASS */
#
# define CHAOS_PP_ADD_BYPASS(s, x, y) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_ADD_I(CHAOS_PP_PREV(s), (CHAOS_PP_PREV(s)), x, y)) \
    /**/
# define CHAOS_PP_ADD_BYPASS_ID() CHAOS_PP_ADD_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ADD_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_ADD_BYPASS)
# endif
#
# define CHAOS_IP_ADD_INDIRECT() CHAOS_IP_ADD_I
# define CHAOS_IP_ADD_I(s, jump, x, y) \
    CHAOS_PP_IIF(CHAOS_PP_IS_VALID(CHAOS_PP_PREV(CHAOS_PP_PREV(s))))( \
        CHAOS_PP_IIF(CHAOS_PP_IS_VALID(CHAOS_PP_PREV(s)))( \
            CHAOS_IP_ADD_II, CHAOS_IP_ADD_III \
        ), \
        CHAOS_IP_ADD_IV \
    )(CHAOS_PP_PHASE(0), s, jump, x, y) \
    /**/
# define CHAOS_IP_ADD_II(_, s, jump, x, y) \
    _(1, CHAOS_PP_EXPR_S)(s)( \
        CHAOS_IP_ADD_III(_, s, (CHAOS_PP_PREV(s)) jump, x, y) \
    ) \
    /**/
# define CHAOS_IP_ADD_III(_, s, jump, x, y) \
    _(1, CHAOS_PP_IIF)( \
        CHAOS_PP_BITAND(CHAOS_PP_NOT_EQUAL(x, CHAOS_PP_LIMIT_MAG))(CHAOS_PP_BOOL(y)) \
    )( \
        _(1, CHAOS_PP_EXPR_S)(s), x CHAOS_PP_TUPLE_EAT(1) \
    )( \
        _(1, CHAOS_IP_ADD_INDIRECT)()( \
            CHAOS_PP_PREV(s), jump, CHAOS_PP_INC(x), CHAOS_PP_DEC(y) \
        ) \
    ) \
    /**/
# define CHAOS_IP_ADD_IV(_, s, jump, x, y) CHAOS_IP_ADD_V(CHAOS_PP_SEQ_FIRST(jump), CHAOS_PP_SEQ_REST(jump), x, y)
# define CHAOS_IP_ADD_V(s, jump, x, y) \
    CHAOS_PP_IIF(CHAOS_PP_IS_VALID(CHAOS_PP_PREV(s)))( \
        CHAOS_IP_ADD_II, CHAOS_IP_ADD_III \
    )(CHAOS_PP_PHASE(1), s, CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_NIL(jump))((s), jump), x, y) \
    /**/
#
# endif
