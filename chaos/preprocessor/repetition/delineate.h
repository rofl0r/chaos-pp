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
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/trampoline.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/logical/bitand.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/buffer.h>
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
#    define CHAOS_PP_DELINEATE_S(s, count, sep, macro, ...) CHAOS_IP_DELINEATE_I(s, count, sep, macro, (__VA_ARGS__))
#    define CHAOS_PP_DELINEATE_S_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_S_ID)()
# else
#    define CHAOS_PP_DELINEATE_S(s, count, sep, macro, data) CHAOS_IP_DELINEATE_I(s, count, sep, macro, (data))
# endif
#
# define CHAOS_PP_DELINEATE_S_ID() CHAOS_PP_DELINEATE_S
#
# define CHAOS_IP_DELINEATE_I(s, count, sep, macro, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_DELINEATE_II( \
        s, CHAOS_PP_NEXT(s), count, CHAOS_PP_EMPTY, sep, macro, CHAOS_PP_TRAMPOLINE(macro), pd \
    )) \
    /**/
# define CHAOS_IP_DELINEATE_INDIRECT() CHAOS_IP_DELINEATE_II
# define CHAOS_IP_DELINEATE_II(s, o, count, sep, ss, macro, _m, pd) \
    CHAOS_PP_IF(count)( \
        CHAOS_IP_DELINEATE_III, CHAOS_PP_TUPLE_EAT(9) \
    )(CHAOS_PP_OBSTRUCT(), CHAOS_PP_NEXT(s), o, CHAOS_PP_DEC(count), sep, ss, macro, _m, pd) \
    /**/
# define CHAOS_IP_DELINEATE_III(_, s, o, count, sep, ss, macro, _m, pd) \
    CHAOS_PP_EXPR_S(s) _(CHAOS_IP_DELINEATE_INDIRECT _()( \
        s, o, count, ss, ss, macro, _m, pd \
    )) \
    _m()(s, o, macro, count CHAOS_PP_COMMA() CHAOS_PP_UNPACK pd) sep() \
    /**/
#
# /* CHAOS_PP_DELINEATE_PARAMETRIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_PARAMETRIC(size, count, sep, macro, ...) CHAOS_PP_DELINEATE_PARAMETRIC_S(CHAOS_PP_STATE(), size, count, sep, macro, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_PARAMETRIC_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_PARAMETRIC_ID)()
# else
#    define CHAOS_PP_DELINEATE_PARAMETRIC(size, count, sep, macro, data) CHAOS_PP_DELINEATE_PARAMETRIC_S(CHAOS_PP_STATE(), size, count, sep, macro, data)
# endif
#
# define CHAOS_PP_DELINEATE_PARAMETRIC_ID() CHAOS_PP_DELINEATE_PARAMETRIC
#
# /* CHAOS_PP_DELINEATE_PARAMETRIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_PARAMETRIC_S(s, size, count, sep, macro, ...) CHAOS_IP_DELINEATE_PARAMETRIC_A(s, size, count, sep, macro, (__VA_ARGS__))
#    define CHAOS_PP_DELINEATE_PARAMETRIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_PARAMETRIC_S_ID)()
# else
#    define CHAOS_PP_DELINEATE_PARAMETRIC_S(s, size, count, sep, macro, data) CHAOS_IP_DELINEATE_PARAMETRIC_A(s, size, count, sep, macro, (data))
# endif
#
# define CHAOS_PP_DELINEATE_PARAMETRIC_S_ID() CHAOS_PP_DELINEATE_PARAMETRIC_S
#
# define CHAOS_IP_DELINEATE_PARAMETRIC_A(s, size, count, sep, macro, pd) \
    CHAOS_PP_EXPR_S(s)(CHAOS_IP_DELINEATE_PARAMETRIC_B( \
        CHAOS_PP_NEXT(s), CHAOS_PP_BUFFER(s, size), count, sep, macro, pd \
    )) \
    /**/
# define CHAOS_IP_DELINEATE_PARAMETRIC_B(s, buffer, count, sep, macro, pd) \
    CHAOS_IP_DELINEATE_PARAMETRIC_C(s, s, buffer, buffer, count, CHAOS_PP_EMPTY, sep, macro, CHAOS_PP_TRAMPOLINE(macro), pd) \
    /**/
# define CHAOS_IP_DELINEATE_PARAMETRIC_INDIRECT() CHAOS_IP_DELINEATE_PARAMETRIC_C
# define CHAOS_IP_DELINEATE_PARAMETRIC_C(s, o, buffer, shelf, count, sep, ss, macro, _m, pd) \
    CHAOS_PP_IIF(CHAOS_PP_BITAND(CHAOS_PP_IS_VALID(buffer))(CHAOS_PP_NOT_EQUAL(buffer, CHAOS_PP_LIMIT_EXPR)))( \
        CHAOS_PP_IF(count)( \
            CHAOS_IP_DELINEATE_PARAMETRIC_D, CHAOS_PP_TUPLE_EAT(10) \
        ), \
        CHAOS_IP_DELINEATE_PARAMETRIC_E \
    )(s, o, buffer, shelf, count, sep, ss, macro, _m, pd) \
    /**/
# define CHAOS_IP_DELINEATE_PARAMETRIC_D(s, o, buffer, shelf, count, sep, ss, macro, _m, pd) \
    CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_IP_DELINEATE_PARAMETRIC_INDIRECT)()( \
        CHAOS_PP_NEXT(s), o, CHAOS_PP_NEXT(buffer), shelf, CHAOS_PP_DEC(count), ss, ss, macro, _m, pd \
    )) \
    _m()(s, o, macro, CHAOS_PP_DEC(count) CHAOS_PP_COMMA() CHAOS_PP_UNPACK pd) sep() \
    /**/
# define CHAOS_IP_DELINEATE_PARAMETRIC_E(s, o, buffer, shelf, count, sep, ss, macro, _m, pd) \
    CHAOS_PP_EXPR_S CHAOS_PP_OBSTRUCT()(o)(CHAOS_IP_DELINEATE_PARAMETRIC_INDIRECT CHAOS_PP_OBSTRUCT()()( \
        CHAOS_PP_NEXT(o), o, CHAOS_PP_NEXT(shelf), shelf, count, sep, ss, macro, _m, pd \
    )) \
    /**/
#
# endif
