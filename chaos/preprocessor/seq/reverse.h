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
# ifndef CHAOS_PREPROCESSOR_SEQ_REVERSE_H
# define CHAOS_PREPROCESSOR_SEQ_REVERSE_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/binary_transform.h>
# include <chaos/preprocessor/seq/detail/close.h>
# include <chaos/preprocessor/seq/duplex.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_SEQ_REVERSE */
#
# define CHAOS_PP_SEQ_REVERSE(seq) CHAOS_PP_EXPAND(CHAOS_IP_SEQ_REVERSE_I(CHAOS_PP_SEQ_BINARY_TRANSFORM(seq, ~)))
# define CHAOS_PP_SEQ_REVERSE_ID() CHAOS_PP_SEQ_REVERSE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_REVERSE_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_REVERSE_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_REVERSE_I(bin) CHAOS_IP_SEQ_REVERSE_II bin CHAOS_PP_SEQ_CLOSE(bin)
#    define CHAOS_IP_SEQ_REVERSE_II(m, ...) m(?)(CHAOS_IP_SEQ_REVERSE_III CHAOS_PP_DEFER(CHAOS_PP_LPAREN)()(__VA_ARGS__), CHAOS_IP_SEQ_REVERSE_INDIRECT)
# else
#    define CHAOS_IP_SEQ_REVERSE_I(bin) CHAOS_IP_SEQ_REVERSE_II bin CHAOS_IP_SEQ_REVERSE_ID CHAOS_PP_SEQ_CLOSE(bin)
#    define CHAOS_IP_SEQ_REVERSE_II(m, x) m(2)(CHAOS_IP_SEQ_REVERSE_III CHAOS_PP_DEFER(CHAOS_PP_LPAREN)()(x), CHAOS_IP_SEQ_REVERSE_INDIRECT)
#    define CHAOS_IP_SEQ_REVERSE_ID(x) (x)
# endif
#
# define CHAOS_IP_SEQ_REVERSE_INDIRECT() CHAOS_IP_SEQ_REVERSE_II
# define CHAOS_IP_SEQ_REVERSE_III(x, res) res x
#
# /* CHAOS_PP_SEQ_REVERSE_DUPLEX */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_REVERSE_DUPLEX(seq) CHAOS_PP_SEQ_REVERSE_DUPLEX_BYPASS(CHAOS_PP_LIMIT_EXPR, seq)
#    define CHAOS_PP_SEQ_REVERSE_DUPLEX_ID() CHAOS_PP_SEQ_REVERSE_DUPLEX
#    define CHAOS_PP_SEQ_REVERSE_DUPLEX_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_REVERSE_DUPLEX_ID)()
# endif
#
# /* CHAOS_PP_SEQ_REVERSE_DUPLEX_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_REVERSE_DUPLEX_BYPASS(s, seq) \
        CHAOS_PP_EXPR_S(s)(CHAOS_PP_EXPR_S(s)(CHAOS_PP_DEFER(CHAOS_IP_SEQ_REVERSE_DUPLEX_I)( \
            CHAOS_PP_DEFER(CHAOS_PP_OBSTRUCT)(), CHAOS_PP_PREV(CHAOS_PP_PREV(s)), CHAOS_PP_TUPLE_REM_CTOR(?, CHAOS_PP_SEQ_DUPLEX_BYPASS(s, seq)) \
        ))) \
        /**/
#    define CHAOS_PP_SEQ_REVERSE_DUPLEX_BYPASS_ID() CHAOS_PP_SEQ_REVERSE_DUPLEX_BYPASS
#    define CHAOS_PP_SEQ_REVERSE_DUPLEX_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_REVERSE_DUPLEX_BYPASS_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_REVERSE_DUPLEX_INDIRECT() CHAOS_IP_SEQ_REVERSE_DUPLEX_I
#    define CHAOS_IP_SEQ_REVERSE_DUPLEX_I(_, s, n, seq) \
        CHAOS_PP_IF _(n)( \
            CHAOS_PP_EXPR_S _(s)(CHAOS_IP_SEQ_REVERSE_DUPLEX_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_DEC(n), CHAOS_IP_SEQ_REVERSE_DUPLEX_A _ seq(0,,) \
            )), \
            seq \
        ) \
        /**/
#    define CHAOS_IP_SEQ_REVERSE_DUPLEX_A(bit, a, b) CHAOS_PP_INLINE_WHEN(bit)(b a CHAOS_IP_SEQ_REVERSE_DUPLEX_B)
#    define CHAOS_IP_SEQ_REVERSE_DUPLEX_B(bit, a, b) CHAOS_PP_INLINE_WHEN(bit)(b a CHAOS_IP_SEQ_REVERSE_DUPLEX_A)
# endif
#
# endif
