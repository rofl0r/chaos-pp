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
# ifndef CHAOS_PREPROCESSOR_REPETITION_DELINEATE_H
# define CHAOS_PREPROCESSOR_REPETITION_DELINEATE_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_DELINEATE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE(count, sep, macro, ...) CHAOS_PP_DELINEATE_S(CHAOS_PP_STATE(), count, sep, macro, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_ID)()
# else
#    define CHAOS_PP_DELINEATE(count, sep, macro, data) CHAOS_PP_DELINEATE_S(CHAOS_PP_STATE(), count, sep, macro, data)
# endif
#
# define CHAOS_PP_DELINEATE_ID() CHAOS_PP_DELINEATE
#
# /* CHAOS_PP_DELINEATE_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_S(s, count, sep, macro, ...) CHAOS_IP_DELINEATE_U(s, count, sep, macro, (__VA_ARGS__))
#    define CHAOS_PP_DELINEATE_S_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_S_ID)()
# else
#    define CHAOS_PP_DELINEATE_S(s, count, sep, macro, data) CHAOS_IP_DELINEATE_U(s, count, sep, macro, (data))
# endif
#
# define CHAOS_PP_DELINEATE_S_ID() CHAOS_PP_DELINEATE_S
#
# define CHAOS_IP_DELINEATE_U(s, count, sep, macro, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_DELINEATE_I( \
        s, CHAOS_PP_NEXT(s), count, CHAOS_PP_EMPTY, sep, macro, CHAOS_PP_TRAMPOLINE(macro), pd \
    )) \
    /**/
# define CHAOS_IP_DELINEATE_INDIRECT() CHAOS_IP_DELINEATE_I
# define CHAOS_IP_DELINEATE_I(s, o, count, sep, ss, macro, _m, pd) \
    CHAOS_PP_IF(count)( \
        CHAOS_IP_DELINEATE_II, CHAOS_PP_TUPLE_EAT(9) \
    )(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), o, CHAOS_PP_DEC(count), sep, ss, macro, _m, pd) \
    /**/
# define CHAOS_IP_DELINEATE_II(_, s, o, count, sep, ss, macro, _m, pd) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_DELINEATE_INDIRECT _()( \
        s, o, count, ss, ss, macro, _m, pd \
    )) \
    _m()(o, macro, count CHAOS_PP_COMMA() CHAOS_PP_UNPACK pd) sep() \
    /**/
#
# endif
