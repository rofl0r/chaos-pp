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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_PARAMETRIC_FOR_EACH_PRODUCT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_PARAMETRIC_FOR_EACH_PRODUCT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/parametric.h>
# include <chaos/preprocessor/seq/spec.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC(size, macro, seq, ...) CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S(CHAOS_PP_STATE(), size, macro, seq, __VA_ARGS__)
#    define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_ID() CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC
#    define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_ID)()
# endif
#
# /* CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S(s, size, macro, seq, ...) \
        CHAOS_PP_EXPR_S(s)(CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_CONS(seq))( \
            CHAOS_PP_PARAMETRIC_S, CHAOS_PP_TUPLE_EAT(?) \
        )(s, CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_INDIRECT, size, CHAOS_PP_NEXT(s), macro, CHAOS_PP_TRAMPOLINE(macro), CHAOS_PP_SEQ_FIRST(seq), CHAOS_PP_SEQ_REST(seq),, __VA_ARGS__)) \
        /**/
#    define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S_ID() CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S
#    define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S_ID)()
#    define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_INDIRECT() CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_I
#    define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_I(s, id, para, o, macro, _m, g, ...) \
        CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
            CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_II, CHAOS_PP_TUPLE_EAT(?) \
        )(CHAOS_PP_OBSTRUCT(), s, id, para, o, macro, _m, g, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_II(_, s, id, para, o, macro, _m, g, seq, bind, ...) \
        CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_CONS(seq))( \
            CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_III, CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_IV \
        )(CHAOS_PP_OBSTRUCT(), s, id, para, o, macro, _m, g, seq, bind, __VA_ARGS__) \
        CHAOS_PP_EXPR_S(s) _(id _()( \
            s, CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_INDIRECT, para, o, macro, _m, CHAOS_PP_REST(g), seq, bind, __VA_ARGS__ \
        )) \
        /**/
#    define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_III(_, s, id, para, o, macro, _m, g, seq, bind, ...) \
        CHAOS_PP_EXPR_S(s) _(id _()( \
            s, CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_INDIRECT, para, o, macro, _m, CHAOS_PP_SEQ_FIRST(seq), CHAOS_PP_SEQ_REST(seq), bind(CHAOS_PP_FIRST(g)), __VA_ARGS__ \
        )) \
        /**/
#    define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_IV(_, s, id, para, o, macro, _m, g, seq, bind, ...) \
        _m()(s, o, macro, bind(CHAOS_PP_FIRST(g)), __VA_ARGS__) \
        /**/
# endif
#
# endif
