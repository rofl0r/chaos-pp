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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_X_FOR_EACH_H
# define CHAOS_PREPROCESSOR_ALGORITHM_X_FOR_EACH_H
#
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/buffer.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/phase.h>
# include <chaos/preprocessor/seq/spec.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FOR_EACH_X */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_X(size, macro, ...) CHAOS_PP_FOR_EACH_X_S(CHAOS_PP_STATE(), size, macro, __VA_ARGS__)
#    define CHAOS_PP_FOR_EACH_X_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_X_ID)()
# else
#    define CHAOS_PP_FOR_EACH_X(size, macro, g, data) CHAOS_PP_FOR_EACH_X_S(CHAOS_PP_STATE(), size, macro, g, data)
# endif
#
# define CHAOS_PP_FOR_EACH_X_ID() CHAOS_PP_FOR_EACH_X
#
# /* CHAOS_PP_FOR_EACH_X_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_X_S(s, size, macro, ...) \
        CHAOS_IP_FOR_EACH_X_U(s, size, macro, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_FOR_EACH_X_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_X_S_ID)()
# else
#    define CHAOS_PP_FOR_EACH_X_S(s, size, macro, g, data) CHAOS_IP_FOR_EACH_X_U(s, size, macro, g, (data))
# endif
#
# define CHAOS_PP_FOR_EACH_X_S_ID() CHAOS_PP_FOR_EACH_X_S
#
# define CHAOS_IP_FOR_EACH_X_U(s, size, macro, g, pd) \
    CHAOS_IP_FOR_EACH_X_I( \
        CHAOS_PP_NEXT(s), (CHAOS_PP_NEXT(s)), CHAOS_PP_FIXED_S(s, size), \
        macro, CHAOS_PP_CALL(macro), CHAOS_PP_TYPEOF(g), g, pd \
    ) \
    /**/
# define CHAOS_IP_FOR_EACH_X_INDIRECT() CHAOS_IP_FOR_EACH_X_I
# define CHAOS_IP_FOR_EACH_X_I(s, jump, fix, macro, _m, type, g, pd) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, fix))( \
        CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, CHAOS_PP_PREV(fix)))( \
            CHAOS_IP_FOR_EACH_X_II, CHAOS_IP_FOR_EACH_X_III \
        ), \
        CHAOS_IP_FOR_EACH_X_V \
    )(CHAOS_PP_PHASE(0), s, jump, fix, macro, _m, type, g, pd) \
    /**/
# define CHAOS_IP_FOR_EACH_X_II(_, s, jump, fix, macro, _m, type, g, pd) \
    _(1, CHAOS_PP_EXPR_S)(s)( \
        CHAOS_IP_FOR_EACH_X_III(_, s, (CHAOS_PP_NEXT(s)) jump, fix, macro, _m, type, g, pd) \
    ) \
    /**/
# define CHAOS_IP_FOR_EACH_X_III(_, s, jump, fix, macro, _m, type, g, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FOR_EACH_X_IV, CHAOS_PP_TUPLE_EAT CHAOS_PP_OBSTRUCT()(9) \
    )(_, s, jump, fix, macro, _m, type, g, pd) \
    /**/
# define CHAOS_IP_FOR_EACH_X_IV(_, s, jump, fix, macro, _m, type, g, pd) \
    _(0, _m)()(s, macro, CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)) _(0, CHAOS_PP_EXPOSE)(pd)) \
    _(1, CHAOS_PP_EXPR_S)(s)(_(1, CHAOS_IP_FOR_EACH_X_INDIRECT)()( \
        CHAOS_PP_NEXT(s), jump, fix, macro, _m, type, CHAOS_PP_REST(g), pd \
    )) \
    /**/
# define CHAOS_IP_FOR_EACH_X_V(_, s, jump, fix, macro, _m, type, g, pd) \
    CHAOS_IP_FOR_EACH_X_VI(CHAOS_PP_SEQ_FIRST(jump), CHAOS_PP_SEQ_REST(jump), fix, macro, _m, type, g, pd) \
    /**/
# define CHAOS_IP_FOR_EACH_X_VI(s, jump, fix, macro, _m, type, g, pd) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, CHAOS_PP_PREV(fix)))( \
        CHAOS_IP_FOR_EACH_X_II, CHAOS_IP_FOR_EACH_X_III \
    )(CHAOS_PP_PHASE(1), s, CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_NIL(jump))((s), jump), fix, macro, _m, type, g, pd) \
    /**/
#
# endif
