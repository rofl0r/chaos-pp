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
# ifndef CHAOS_PREPROCESSOR_SEQ_SIZE_H
# define CHAOS_PREPROCESSOR_SEQ_SIZE_H
#
# include <chaos/preprocessor/arbitrary/demote.h>
# include <chaos/preprocessor/arbitrary/greater.h>
# include <chaos/preprocessor/arbitrary/promote.h>
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/binary_transform.h>
# include <chaos/preprocessor/seq/core.h>
# include <chaos/preprocessor/seq/detail/close.h>
#
# /* CHAOS_PP_SEQ_SIZE */
#
# define CHAOS_PP_SEQ_SIZE(seq) CHAOS_PP_EXPAND(CHAOS_IP_SEQ_SIZE_I(CHAOS_PP_SEQ_BINARY_TRANSFORM(seq, ~)))
# define CHAOS_PP_SEQ_SIZE_ID() CHAOS_PP_SEQ_SIZE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_SIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_SIZE)
# endif
#
# define CHAOS_IP_SEQ_SIZE_I(bin) CHAOS_IP_SEQ_SIZE_II bin 0 CHAOS_PP_SEQ_CLOSE(bin)
# define CHAOS_IP_SEQ_SIZE_INDIRECT() CHAOS_IP_SEQ_SIZE_II
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_SIZE_II(m, ...) m(?)(CHAOS_PP_INC CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() CHAOS_IP_SEQ_SIZE_INDIRECT)
# else
#    define CHAOS_IP_SEQ_SIZE_II(m, x) m(1)(CHAOS_PP_INC CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() CHAOS_IP_SEQ_SIZE_INDIRECT)
# endif
#
# /* CHAOS_PP_SEQ_SIZE_ALT */
#
# define CHAOS_PP_SEQ_SIZE_ALT(seq) CHAOS_PP_SEQ_SIZE_ALT_BYPASS(CHAOS_PP_LIMIT_EXPR, seq)
# define CHAOS_PP_SEQ_SIZE_ALT_ID() CHAOS_PP_SEQ_SIZE_ALT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_SIZE_ALT_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_SIZE_ALT)
# endif
#
# /* CHAOS_PP_SEQ_SIZE_ALT_BYPASS */
#
# define CHAOS_PP_SEQ_SIZE_ALT_BYPASS(s, seq) \
    CHAOS_IP_SEQ_SIZE_ALT_II( \
        CHAOS_PP_EXPR_S(s)(CHAOS_PP_EXPR_S(s)( \
            CHAOS_PP_DEFER(CHAOS_IP_SEQ_SIZE_ALT_I)( \
                CHAOS_PP_DEFER(CHAOS_PP_OBSTRUCT)(), CHAOS_PP_PREV(CHAOS_PP_PREV(s)), CHAOS_PP_CAT(CHAOS_IP_SEQ_SIZE_ALT_0 seq, 0) CHAOS_PP_EMPTY \
            ) \
        )) \
    ) \
    /**/
# define CHAOS_PP_SEQ_SIZE_ALT_BYPASS_ID() CHAOS_PP_SEQ_SIZE_ALT_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_SIZE_ALT_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_SIZE_ALT_BYPASS)
# endif
#
# define CHAOS_IP_SEQ_SIZE_ALT_INDIRECT() CHAOS_IP_SEQ_SIZE_ALT_I
# define CHAOS_IP_SEQ_SIZE_ALT_I(_, s, seq, r) \
    CHAOS_PP_IIF _(CHAOS_PP_SEQ_IS_CONS(seq()~))( \
        CHAOS_PP_EXPR_S _(s)(CHAOS_IP_SEQ_SIZE_ALT_INDIRECT _()( \
            CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_CAT(CHAOS_IP_SEQ_SIZE_ALT_0 seq(), 0) r \
        )), \
        r() \
    ) \
    /**/
# define CHAOS_IP_SEQ_SIZE_ALT_II(x) \
    CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_GREATER(x, CHAOS_PP_ARBITRARY_PROMOTE(CHAOS_PP_LIMIT_MAG)))( \
        CHAOS_PP_LIMIT_MAG, CHAOS_PP_ARBITRARY_DEMOTE(x) \
    ) \
    /**/
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_SIZE_ALT_0(...) CHAOS_IP_SEQ_SIZE_ALT_1
#    define CHAOS_IP_SEQ_SIZE_ALT_1(...) CHAOS_IP_SEQ_SIZE_ALT_2
#    define CHAOS_IP_SEQ_SIZE_ALT_2(...) CHAOS_IP_SEQ_SIZE_ALT_3
#    define CHAOS_IP_SEQ_SIZE_ALT_3(...) CHAOS_IP_SEQ_SIZE_ALT_4
#    define CHAOS_IP_SEQ_SIZE_ALT_4(...) CHAOS_IP_SEQ_SIZE_ALT_5
#    define CHAOS_IP_SEQ_SIZE_ALT_5(...) CHAOS_IP_SEQ_SIZE_ALT_6
#    define CHAOS_IP_SEQ_SIZE_ALT_6(...) CHAOS_IP_SEQ_SIZE_ALT_7
#    define CHAOS_IP_SEQ_SIZE_ALT_7(...) CHAOS_IP_SEQ_SIZE_ALT_8
#    define CHAOS_IP_SEQ_SIZE_ALT_8(...) CHAOS_IP_SEQ_SIZE_ALT_9
#    define CHAOS_IP_SEQ_SIZE_ALT_9(...) () CHAOS_IP_SEQ_SIZE_ALT_0
# else
#    define CHAOS_IP_SEQ_SIZE_ALT_0(x) CHAOS_IP_SEQ_SIZE_ALT_1
#    define CHAOS_IP_SEQ_SIZE_ALT_1(x) CHAOS_IP_SEQ_SIZE_ALT_2
#    define CHAOS_IP_SEQ_SIZE_ALT_2(x) CHAOS_IP_SEQ_SIZE_ALT_3
#    define CHAOS_IP_SEQ_SIZE_ALT_3(x) CHAOS_IP_SEQ_SIZE_ALT_4
#    define CHAOS_IP_SEQ_SIZE_ALT_4(x) CHAOS_IP_SEQ_SIZE_ALT_5
#    define CHAOS_IP_SEQ_SIZE_ALT_5(x) CHAOS_IP_SEQ_SIZE_ALT_6
#    define CHAOS_IP_SEQ_SIZE_ALT_6(x) CHAOS_IP_SEQ_SIZE_ALT_7
#    define CHAOS_IP_SEQ_SIZE_ALT_7(x) CHAOS_IP_SEQ_SIZE_ALT_8
#    define CHAOS_IP_SEQ_SIZE_ALT_8(x) CHAOS_IP_SEQ_SIZE_ALT_9
#    define CHAOS_IP_SEQ_SIZE_ALT_9(x) (~) CHAOS_IP_SEQ_SIZE_ALT_0
# endif
#
# define CHAOS_IP_SEQ_SIZE_ALT_00 CHAOS_PP_EMPTY, (0)
# define CHAOS_IP_SEQ_SIZE_ALT_10 CHAOS_PP_EMPTY, (1)
# define CHAOS_IP_SEQ_SIZE_ALT_20 CHAOS_PP_EMPTY, (2)
# define CHAOS_IP_SEQ_SIZE_ALT_30 CHAOS_PP_EMPTY, (3)
# define CHAOS_IP_SEQ_SIZE_ALT_40 CHAOS_PP_EMPTY, (4)
# define CHAOS_IP_SEQ_SIZE_ALT_50 CHAOS_PP_EMPTY, (5)
# define CHAOS_IP_SEQ_SIZE_ALT_60 CHAOS_PP_EMPTY, (6)
# define CHAOS_IP_SEQ_SIZE_ALT_70 CHAOS_PP_EMPTY, (7)
# define CHAOS_IP_SEQ_SIZE_ALT_80 CHAOS_PP_EMPTY, (8)
# define CHAOS_IP_SEQ_SIZE_ALT_90 CHAOS_PP_EMPTY, (9)
#
# endif
