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
# ifndef CHAOS_PREPROCESSOR_SEQ_DUPLEX_H
# define CHAOS_PREPROCESSOR_SEQ_DUPLEX_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/extended/reverse_cat.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_SEQ_DUPLEX */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_DUPLEX(seq) CHAOS_PP_SEQ_DUPLEX_BYPASS(CHAOS_PP_LIMIT_EXPR, seq)
#    define CHAOS_PP_SEQ_DUPLEX_ID() CHAOS_PP_SEQ_DUPLEX
#    define CHAOS_PP_SEQ_DUPLEX_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_DUPLEX_ID)()
# endif
#
# /* CHAOS_PP_SEQ_DUPLEX_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_DUPLEX_BYPASS(s, seq) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_SEQ_DUPLEX_I( \
            CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), 1, CHAOS_PP_REVERSE_CAT(0, CHAOS_IP_SEQ_DUPLEX_A seq) \
        )) \
        /**/
#    define CHAOS_PP_SEQ_DUPLEX_BYPASS_ID() CHAOS_PP_SEQ_DUPLEX_BYPASS
#    define CHAOS_PP_SEQ_DUPLEX_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_DUPLEX_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_DUPLEX_INDIRECT() CHAOS_IP_SEQ_DUPLEX_I
#    define CHAOS_IP_SEQ_DUPLEX_I(_, s, n, seq) \
        CHAOS_PP_IIF _(CHAOS_PP_IS_VARIADIC(CHAOS_PP_EAT seq))( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_SEQ_DUPLEX_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_INC(n), CHAOS_PP_REVERSE_CAT(0, CHAOS_IP_SEQ_DUPLEX_A seq) \
            )), \
            (n, seq) \
        ) \
        /**/
#    define CHAOS_IP_SEQ_DUPLEX_A(...) CHAOS_PP_DEFER(CHAOS_PP_LPAREN)(), (__VA_ARGS__) CHAOS_IP_SEQ_DUPLEX_B
#    define CHAOS_IP_SEQ_DUPLEX_B(...) , (__VA_ARGS__) CHAOS_PP_DEFER(CHAOS_PP_RPAREN)() CHAOS_IP_SEQ_DUPLEX_A
#    define CHAOS_IP_SEQ_DUPLEX_A0
#    define CHAOS_IP_SEQ_DUPLEX_B0 ,)
# endif
#
# endif
