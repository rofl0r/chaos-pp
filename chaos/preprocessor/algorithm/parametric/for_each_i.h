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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_PARAMETRIC_FOR_EACH_I_H
# define CHAOS_PREPROCESSOR_ALGORITHM_PARAMETRIC_FOR_EACH_I_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/phase.h>
#
# /* CHAOS_PP_FOR_EACH_I_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_I_PARAMETRIC(macro, ...) CHAOS_PP_FOR_EACH_I_PARAMETRIC_S(CHAOS_PP_STATE(), macro, __VA_ARGS__)
#    define CHAOS_PP_FOR_EACH_I_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_I_PARAMETRIC_ID)()
# else
#    define CHAOS_PP_FOR_EACH_I_PARAMETRIC(macro, g, data) CHAOS_PP_FOR_EACH_I_PARAMETRIC_S(CHAOS_PP_STATE(), macro, g, data)
# endif
#
# define CHAOS_PP_FOR_EACH_I_PARAMETRIC_ID() CHAOS_PP_FOR_EACH_I_PARAMETRIC
#
# /* CHAOS_PP_FOR_EACH_I_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_I_PARAMETRIC_S(s, macro, ...) \
        CHAOS_IP_FOR_EACH_I_PARAMETRIC_U(s, macro, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_FOR_EACH_I_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_I_PARAMETRIC_S_ID)()
# else
#    define CHAOS_PP_FOR_EACH_I_PARAMETRIC_S(s, macro, g, data) CHAOS_IP_FOR_EACH_I_PARAMETRIC_U(s, macro, g, (data))
# endif
#
# define CHAOS_PP_FOR_EACH_I_PARAMETRIC_S_ID() CHAOS_PP_FOR_EACH_I_PARAMETRIC_S
#
# define CHAOS_IP_FOR_EACH_I_PARAMETRIC_U(s, macro, g, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_FOR_EACH_I_PARAMETRIC_I( \
        CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), 0, macro, CHAOS_PP_TRAMPOLINE(macro), CHAOS_PP_TYPEOF(g), g, pd \
    )) \
    /**/
# define CHAOS_IP_FOR_EACH_I_PARAMETRIC_INDIRECT() CHAOS_IP_FOR_EACH_I_PARAMETRIC_I
# define CHAOS_IP_FOR_EACH_I_PARAMETRIC_I(s, o, n, macro, _m, type, g, pd) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, CHAOS_PP_LIMIT_EXPR))( \
        CHAOS_IP_FOR_EACH_I_PARAMETRIC_II, CHAOS_IP_FOR_EACH_I_PARAMETRIC_IV \
    )(CHAOS_PP_PHASE(0), s, o, n, macro, _m, type, g, pd) \
    /**/
# define CHAOS_IP_FOR_EACH_I_PARAMETRIC_II(_, s, o, n, macro, _m, type, g, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FOR_EACH_I_PARAMETRIC_III, CHAOS_PP_TUPLE_EAT(9) \
    )(_, s, o, n, macro, _m, type, g, pd) \
    /**/
# define CHAOS_IP_FOR_EACH_I_PARAMETRIC_III(_, s, o, n, macro, _m, type, g, pd) \
    _(0, _m)()(o, macro, n _(0, CHAOS_PP_COMMA)() CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)) _(0, CHAOS_PP_EXPOSE)(pd)) \
    _(1, CHAOS_PP_EXPR_S)(s)(_(1, CHAOS_IP_FOR_EACH_I_PARAMETRIC_INDIRECT)()( \
        CHAOS_PP_NEXT(s), o, CHAOS_PP_INC(n), macro, _m, type, CHAOS_PP_REST(g), pd \
    )) \
    /**/
# define CHAOS_IP_FOR_EACH_I_PARAMETRIC_IV(_, s, o, n, macro, _m, type, g, pd) \
    CHAOS_IP_FOR_EACH_I_PARAMETRIC_II(CHAOS_PP_PHASE(1), o, o, n, macro, _m, type, g, pd) \
    /**/
#
# endif
