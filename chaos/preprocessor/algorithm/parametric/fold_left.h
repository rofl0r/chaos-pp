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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_PARAMETRIC_FOLD_LEFT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_PARAMETRIC_FOLD_LEFT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/parametric.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FOLD_LEFT_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_LEFT_PARAMETRIC(size, op, g, ...) CHAOS_PP_FOLD_LEFT_PARAMETRIC_S(CHAOS_PP_STATE(), size, op, g, __VA_ARGS__)
#    define CHAOS_PP_FOLD_LEFT_PARAMETRIC_ID() CHAOS_PP_FOLD_LEFT_PARAMETRIC
#    define CHAOS_PP_FOLD_LEFT_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_LEFT_PARAMETRIC_ID)()
# endif
#
# /* CHAOS_PP_FOLD_LEFT_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_LEFT_PARAMETRIC_S(s, size, op, g, ...) \
        CHAOS_PP_PARAMETRIC_S(s, CHAOS_IP_FOLD_LEFT_PARAMETRIC_INDIRECT, size, op, CHAOS_PP_CALL(op), CHAOS_PP_TYPEOF(g), g, __VA_ARGS__) \
        /**/
#    define CHAOS_PP_FOLD_LEFT_PARAMETRIC_S_ID() CHAOS_PP_FOLD_LEFT_PARAMETRIC_S
#    define CHAOS_PP_FOLD_LEFT_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_LEFT_PARAMETRIC_S_ID)()
#    define CHAOS_IP_FOLD_LEFT_PARAMETRIC_INDIRECT() CHAOS_IP_FOLD_LEFT_PARAMETRIC_I
#    define CHAOS_IP_FOLD_LEFT_PARAMETRIC_I(s, id, para, op, _o, type, g, ...) \
        CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
            CHAOS_PP_EXPR_S(s) CHAOS_PP_OBSTRUCT(), \
            __VA_ARGS__ CHAOS_PP_TUPLE_EAT(?) \
        )(CHAOS_PP_DEFER(id)()( \
            s, CHAOS_IP_FOLD_LEFT_PARAMETRIC_INDIRECT, para, op, _o, type, CHAOS_PP_REST(g), \
            _o()(s, op, CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)), __VA_ARGS__) \
        )) \
        /**/
# endif
#
# endif
