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
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_MUL_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_MUL_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/phase.h>
# include <chaos/preprocessor/seq/spec.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_MUL */
#
# define CHAOS_PP_MUL(x, y) CHAOS_PP_MUL_BYPASS(CHAOS_PP_LIMIT_EXPR, x, y)
# define CHAOS_PP_MUL_ID() CHAOS_PP_MUL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MUL_ CHAOS_PP_LAMBDA(CHAOS_PP_MUL)
# endif
#
# /* CHAOS_PP_MUL_BYPASS */
#
# define CHAOS_PP_MUL_BYPASS(s, x, y) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_MUL_I(CHAOS_PP_PREV(s), (CHAOS_PP_PREV(s)), 0, 0, x, y, 0)) \
    /**/
# define CHAOS_PP_MUL_BYPASS_ID() CHAOS_PP_MUL_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MUL_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_MUL_BYPASS)
# endif
#
# define CHAOS_IP_MUL_INDIRECT() CHAOS_IP_MUL_I
# define CHAOS_IP_MUL_I(s, jump, mode, r, x, y, z) \
    CHAOS_PP_IIF(CHAOS_PP_IS_VALID(CHAOS_PP_PREV(CHAOS_PP_PREV(s))))( \
        CHAOS_PP_IIF(CHAOS_PP_IS_VALID(CHAOS_PP_PREV(s)))( \
            CHAOS_IP_MUL_II, CHAOS_IP_MUL_ ## mode \
        ), \
        CHAOS_IP_MUL_III \
    )(CHAOS_PP_PHASE(0), s, jump, mode, r, x, y, z) \
    /**/
# define CHAOS_IP_MUL_II(_, s, jump, mode, r, x, y, z) \
    _(1, CHAOS_PP_EXPR_S)(s)( \
        CHAOS_IP_MUL_ ## mode(_, s, (CHAOS_PP_PREV(s)) jump, mode, r, x, y, z) \
    ) \
    /**/
# define CHAOS_IP_MUL_III(_, s, jump, mode, r, x, y, z) \
    CHAOS_IP_MUL_IV(CHAOS_PP_SEQ_FIRST(jump), CHAOS_PP_SEQ_REST(jump), mode, r, x, y, z) \
    /**/
# define CHAOS_IP_MUL_IV(s, jump, mode, r, x, y, z) \
    CHAOS_PP_IIF(CHAOS_PP_IS_VALID(CHAOS_PP_PREV(s)))( \
        CHAOS_IP_MUL_II, CHAOS_IP_MUL_ ## mode \
    )(CHAOS_PP_PHASE(1), s, CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_NIL(jump))((s), jump), mode, r, x, y, z) \
    /**/
# define CHAOS_IP_MUL_0(_, s, jump, mode, r, x, y, z) \
    CHAOS_PP_IF(y)( \
        CHAOS_IP_MUL_1, r CHAOS_PP_TUPLE_EAT(6) \
    )(_, s, jump, mode, r, x, CHAOS_PP_DEC(y), x) \
    /**/
# define CHAOS_IP_MUL_1(_, s, jump, mode, r, x, y, z) \
    _(1, CHAOS_PP_EXPR_S)(s)(_(1, CHAOS_IP_MUL_INDIRECT)()( \
        CHAOS_PP_PREV(s), jump, \
        CHAOS_PP_TUPLE_REM_CTOR(5, CHAOS_PP_IF(z)( \
            (1, CHAOS_PP_INC(r), x, y, CHAOS_PP_DEC(z)), \
            (0, r, x, y, 0) \
        )) \
    )) \
    /**/
#
# endif
