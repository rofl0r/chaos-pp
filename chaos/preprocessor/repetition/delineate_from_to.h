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
# ifndef CHAOS_PREPROCESSOR_REPETITION_DELINEATE_FROM_TO_H
# define CHAOS_PREPROCESSOR_REPETITION_DELINEATE_FROM_TO_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_DELINEATE_FROM_TO */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_FROM_TO(from, to, sep, ...) CHAOS_PP_DELINEATE_FROM_TO_S(CHAOS_PP_STATE(), from, to, sep, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_FROM_TO_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_FROM_TO_ID)()
# else
#    define CHAOS_PP_DELINEATE_FROM_TO(from, to, sep, macro, data) CHAOS_PP_DELINEATE_FROM_TO_S(CHAOS_PP_STATE(), from, to, sep, macro, data)
# endif
#
# define CHAOS_PP_DELINEATE_FROM_TO_ID() CHAOS_PP_DELINEATE_FROM_TO
#
# /* CHAOS_PP_DELINEATE_FROM_TO_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_FROM_TO_S(s, from, to, sep, ...) \
        CHAOS_IP_DELINEATE_FROM_TO_U(s, from, to, sep, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_DELINEATE_FROM_TO_S_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_FROM_TO_S_ID)()
# else
#    define CHAOS_PP_DELINEATE_FROM_TO_S(s, from, to, sep, macro, data) CHAOS_IP_DELINEATE_FROM_TO_U(s, from, to, sep, macro, (data))
# endif
#
# define CHAOS_PP_DELINEATE_FROM_TO_S_ID() CHAOS_PP_DELINEATE_FROM_TO_S
#
# define CHAOS_IP_DELINEATE_FROM_TO_U(s, from, to, sep, macro, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_DELINEATE_FROM_TO_I(CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), from, to, CHAOS_PP_EMPTY, sep, macro, CHAOS_PP_TRAMPOLINE(macro), pd)) \
    /**/
# define CHAOS_IP_DELINEATE_FROM_TO_INDIRECT() CHAOS_IP_DELINEATE_FROM_TO_I
# define CHAOS_IP_DELINEATE_FROM_TO_I(s, o, from, to, s1, s2, macro, _m, pd) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(from, to))( \
        CHAOS_IP_DELINEATE_FROM_TO_II, CHAOS_PP_TUPLE_EAT(9) \
    )(s, o, from, CHAOS_PP_DEC(to), s1, s2, macro, _m, pd) \
    /**/
# define CHAOS_IP_DELINEATE_FROM_TO_II(s, o, from, to, s1, s2, macro, _m, pd) \
    CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_IP_DELINEATE_FROM_TO_INDIRECT)()( \
        CHAOS_PP_NEXT(s), o, from, to, s2, s2, macro, _m, pd \
    )) \
    _m()(o, macro, to CHAOS_PP_EXPOSE(pd)) s1()
    /**/
#
# endif
