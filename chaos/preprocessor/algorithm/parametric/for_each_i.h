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
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/parametric.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FOR_EACH_I_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_I_PARAMETRIC(size, macro, ...) CHAOS_PP_FOR_EACH_I_PARAMETRIC_S(CHAOS_PP_STATE(), size, macro, __VA_ARGS__)
#    define CHAOS_PP_FOR_EACH_I_PARAMETRIC_ID() CHAOS_PP_FOR_EACH_I_PARAMETRIC
#    define CHAOS_PP_FOR_EACH_I_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_I_PARAMETRIC_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_I_PARAMETRIC_S(s, size, macro, ...) \
        CHAOS_IP_FOR_EACH_I_PARAMETRIC_I(s, size, macro, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_EXPOSE(CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__))) \
        /**/
#    define CHAOS_PP_FOR_EACH_I_PARAMETRIC_S_ID() CHAOS_PP_FOR_EACH_I_PARAMETRIC_S
#    define CHAOS_PP_FOR_EACH_I_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_I_PARAMETRIC_S_ID)()
#    define CHAOS_IP_FOR_EACH_I_PARAMETRIC_I(s, size, macro, g, im) \
        CHAOS_PP_EXPR_S(s)(CHAOS_PP_PARAMETRIC_S( \
            s, CHAOS_IP_FOR_EACH_I_PARAMETRIC_INDIRECT, size, \
            CHAOS_PP_NEXT(s), 0, macro, CHAOS_PP_TRAMPOLINE(macro), CHAOS_PP_TYPEOF(g), g, im \
        )) \
        /**/
#    define CHAOS_IP_FOR_EACH_I_PARAMETRIC_INDIRECT() CHAOS_IP_FOR_EACH_I_PARAMETRIC_II
#    define CHAOS_IP_FOR_EACH_I_PARAMETRIC_II(s, id, para, o, n, macro, _m, type, g, ...) \
        CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
            CHAOS_IP_FOR_EACH_I_PARAMETRIC_III, CHAOS_PP_TUPLE_EAT(?) \
        )(CHAOS_PP_OBSTRUCT(), s, id, para, o, n, macro, _m, type, g, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_FOR_EACH_I_PARAMETRIC_III(_, s, id, para, o, n, macro, _m, type, g, ...) \
        _m()(o, macro, n, CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)) __VA_ARGS__) \
        CHAOS_PP_EXPR_S(s) _(id _()( \
            s, CHAOS_IP_FOR_EACH_I_PARAMETRIC_INDIRECT, para, o, CHAOS_PP_INC(n), macro, _m, type, CHAOS_PP_REST(g), __VA_ARGS__ \
        )) \
        /**/
# endif
#
# endif
