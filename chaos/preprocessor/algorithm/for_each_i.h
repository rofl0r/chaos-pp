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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_FOR_EACH_I_H
# define CHAOS_PREPROCESSOR_ALGORITHM_FOR_EACH_I_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/generics/core.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_FOR_EACH_I */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_I(macro, ...) CHAOS_PP_FOR_EACH_I_S(CHAOS_PP_STATE(), macro, __VA_ARGS__)
#    define CHAOS_PP_FOR_EACH_I_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_I_ID)()
# else
#    define CHAOS_PP_FOR_EACH_I(macro, g, data) CHAOS_PP_FOR_EACH_I_S(CHAOS_PP_STATE(), macro, g, data)
# endif
#
# define CHAOS_PP_FOR_EACH_I_ID() CHAOS_PP_FOR_EACH_I
#
# /* CHAOS_PP_FOR_EACH_I_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOR_EACH_I_S(s, macro, ...) CHAOS_IP_FOR_EACH_I_U(s, macro, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__))
#    define CHAOS_PP_FOR_EACH_I_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOR_EACH_I_S_ID)()
# else
#    define CHAOS_PP_FOR_EACH_I_S(s, macro, g, data) CHAOS_IP_FOR_EACH_I_U(s, macro, g, (data))
# endif
#
# define CHAOS_PP_FOR_EACH_I_S_ID() CHAOS_PP_FOR_EACH_I_S
#
# define CHAOS_IP_FOR_EACH_I_U(s, macro, g, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_FOR_EACH_I_I( \
        CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), 0, macro, CHAOS_PP_TRAMPOLINE(macro), CHAOS_PP_TYPEOF(g), g, pd \
    )) \
    /**/
# define CHAOS_IP_FOR_EACH_I_INDIRECT() CHAOS_IP_FOR_EACH_I_I
# define CHAOS_IP_FOR_EACH_I_I(s, o, n, macro, _m, type, g, pd) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FOR_EACH_I_II, CHAOS_PP_TUPLE_EAT(9) \
    )(CHAOS_PP_OBSTRUCT(), s, o, n, macro, _m, type, g, pd) \
    /**/
# define CHAOS_IP_FOR_EACH_I_II(_, s, o, n, macro, _m, type, g, pd) \
    _m()(o, macro, n CHAOS_PP_COMMA() CHAOS_PP_ITEM(type, CHAOS_PP_HEAD(g)) CHAOS_PP_EXPOSE(pd)) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_FOR_EACH_I_INDIRECT _()( \
        CHAOS_PP_NEXT(s), o, CHAOS_PP_INC(n), macro, _m, type, CHAOS_PP_TAIL(g), pd \
    )) \
    /**/
#
# endif
