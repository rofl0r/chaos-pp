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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_PARAMETRIC_FOR_EACH_PRODUCT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_PARAMETRIC_FOR_EACH_PRODUCT_H
#
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/phase.h>
# include <chaos/preprocessor/seq/core.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC(macro, ...) CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S(CHAOS_PP_STATE(), macro, __VA_ARGS__)
#    define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_ID)()
# else
#    define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC(macro, seq, data) CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S(CHAOS_PP_STATE(), macro, seq, data)
# endif
#
# define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_ID() CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC
#
# /* CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S(s, macro, ...) \
        CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_U(s, macro, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__),, CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S_ID)()
# else
#    define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S(s, macro, seq, data) CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_U(s, macro, seq, CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_N, (data))
# endif
#
# define CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S_ID() CHAOS_PP_FOR_EACH_PRODUCT_PARAMETRIC_S
#
# if !CHAOS_PP_VARIADICS
#    define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_N(x) (x)
# endif
#
# define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_U(s, macro, seq, bind, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_I( \
        CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), macro, CHAOS_PP_TRAMPOLINE(macro), CHAOS_PP_SEQ_FIRST(seq), CHAOS_PP_SEQ_REST(seq), bind, pd \
    )) \
    /**/
# define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_INDIRECT() CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_I
# define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_I(s, o, macro, _m, g, seq, bind, pd) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, CHAOS_PP_LIMIT_EXPR))( \
        CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_II, CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_VI \
    )(CHAOS_PP_PHASE(0), s, o, macro, _m, g, seq, bind, pd) \
    /**/
# define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_II(_, s, o, macro, _m, g, seq, bind, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_III, CHAOS_PP_TUPLE_EAT(9) \
    )(_, s, o, macro, _m, g, seq, bind, pd) \
    /**/
# define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_III(_, s, o, macro, _m, g, seq, bind, pd) \
    CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_CONS(seq))( \
        CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_IV, CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_V \
    )(_, s, o, macro, _m, g, seq, bind, pd) \
    _(1, CHAOS_PP_EXPR_S)(s)(_(1, CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_INDIRECT)()( \
        CHAOS_PP_NEXT(s), o, macro, _m, CHAOS_PP_REST(g), seq, bind, pd \
    )) \
    /**/
# define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_IV(_, s, o, macro, _m, g, seq, bind, pd) \
    _(1, CHAOS_PP_EXPR_S)(s)(_(1, CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_INDIRECT)()( \
        CHAOS_PP_NEXT(s), o, macro, _m, CHAOS_PP_SEQ_FIRST(seq), CHAOS_PP_SEQ_REST(seq), bind (CHAOS_PP_FIRST(g)), pd \
    )) \
    /**/
# define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_V(_, s, o, macro, _m, g, seq, bind, pd) \
    _(0, _m)()(o, macro, bind (CHAOS_PP_FIRST(g)) _(0, CHAOS_PP_EXPOSE)(pd)) \
    /**/
# define CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_VI(_, s, o, macro, _m, g, seq, bind, pd) \
    CHAOS_IP_FOR_EACH_PRODUCT_PARAMETRIC_II(CHAOS_PP_PHASE(1), o, o, macro, _m, g, seq, bind, pd) \
    /**/
#
# endif
