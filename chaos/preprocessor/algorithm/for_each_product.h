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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_FOR_EACH_PRODUCT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_FOR_EACH_PRODUCT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/spec.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FOR_EACH_PRODUCT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_PRODUCT(macro, seq, ...) CHAOS_PP_FOR_EACH_PRODUCT_S(CHAOS_PP_STATE(), macro, seq, __VA_ARGS__)
#    define CHAOS_PP_FOR_EACH_PRODUCT_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_PRODUCT_ID)()
# else
#    define CHAOS_PP_FOR_EACH_PRODUCT(macro, seq, data) CHAOS_PP_FOR_EACH_PRODUCT_S(CHAOS_PP_STATE(), macro, seq, data)
# endif
#
# define CHAOS_PP_FOR_EACH_PRODUCT_ID() CHAOS_PP_FOR_EACH_PRODUCT
#
# /* CHAOS_PP_FOR_EACH_PRODUCT_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_PRODUCT_S(s, macro, seq, ...) CHAOS_IP_FOR_EACH_PRODUCT_U(s, macro, seq,, (__VA_ARGS__))
#    define CHAOS_PP_FOR_EACH_PRODUCT_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_PRODUCT_S_ID)()
# else
#    define CHAOS_PP_FOR_EACH_PRODUCT_S(s, macro, seq, data) CHAOS_IP_FOR_EACH_PRODUCT_U(s, macro, seq, CHAOS_IP_FOR_EACH_PRODUCT_N, (data))
#    define CHAOS_IP_FOR_EACH_PRODUCT_N(x) (x)
# endif
#
# define CHAOS_PP_FOR_EACH_PRODUCT_S_ID() CHAOS_PP_FOR_EACH_PRODUCT_S
#
# define CHAOS_IP_FOR_EACH_PRODUCT_U(s, macro, seq, bind, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_CONS(seq))( \
        CHAOS_IP_FOR_EACH_PRODUCT_I, CHAOS_PP_TUPLE_EAT(8) \
    )(CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), macro, CHAOS_PP_TRAMPOLINE(macro), CHAOS_PP_SEQ_FIRST(seq), CHAOS_PP_SEQ_REST(seq), bind, pd)) \
    /**/
# define CHAOS_IP_FOR_EACH_PRODUCT_INDIRECT() CHAOS_IP_FOR_EACH_PRODUCT_I
# define CHAOS_IP_FOR_EACH_PRODUCT_I(s, o, macro, _m, g, seq, bind, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FOR_EACH_PRODUCT_II, CHAOS_PP_TUPLE_EAT(9) \
    )(CHAOS_PP_OBSTRUCT(), s, o, macro, _m, g, seq, bind, pd) \
    /**/
# define CHAOS_IP_FOR_EACH_PRODUCT_II(_, s, o, macro, _m, g, seq, bind, pd) \
    CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_CONS(seq))( \
        CHAOS_IP_FOR_EACH_PRODUCT_III, CHAOS_IP_FOR_EACH_PRODUCT_IV \
    )(CHAOS_PP_OBSTRUCT(), s, o, macro, _m, g, seq, bind, pd) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOR_EACH_PRODUCT_INDIRECT _()( \
        CHAOS_PP_NEXT(s), o, macro, _m, CHAOS_PP_REST(g), seq, bind, pd \
    )) \
    /**/
# define CHAOS_IP_FOR_EACH_PRODUCT_III(_, s, o, macro, _m, g, seq, bind, pd) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOR_EACH_PRODUCT_INDIRECT _()( \
        CHAOS_PP_NEXT(s), o, macro, _m, CHAOS_PP_SEQ_FIRST(seq), CHAOS_PP_SEQ_REST(seq), bind(CHAOS_PP_FIRST(g)), pd \
    )) \
    /**/
# define CHAOS_IP_FOR_EACH_PRODUCT_IV(_, s, o, macro, _m, g, seq, bind, pd) \
    _m()(o, macro, bind(CHAOS_PP_FIRST(g)) CHAOS_PP_COMMA() CHAOS_PP_UNPACK pd) \
    /**/
#
# endif
