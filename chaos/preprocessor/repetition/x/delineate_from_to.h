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
# ifndef CHAOS_PREPROCESSOR_REPETITION_X_DELINEATE_FROM_TO_H
# define CHAOS_PREPROCESSOR_REPETITION_X_DELINEATE_FROM_TO_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/buffer.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/phase.h>
# include <chaos/preprocessor/seq/core.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_DELINEATE_FROM_TO_X */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_FROM_TO_X(size, from, to, sep, ...) CHAOS_PP_DELINEATE_FROM_TO_X_S(CHAOS_PP_STATE(), size, from, to, sep, __VA_ARGS__)
#    define CHAOS_PP_DELINEATE_FROM_TO_X_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_FROM_TO_X_ID)()
# else
#    define CHAOS_PP_DELINEATE_FROM_TO_X(size, from, to, sep, macro, data) CHAOS_PP_DELINEATE_FROM_TO_X_S(CHAOS_PP_STATE(), size, from, to, sep, macro, data)
# endif
#
# define CHAOS_PP_DELINEATE_FROM_TO_X_ID() CHAOS_PP_DELINEATE_FROM_TO_X
#
# /* CHAOS_PP_DELINEATE_FROM_TO_X_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELINEATE_FROM_TO_X_S(s, size, from, to, sep, ...) \
        CHAOS_IP_DELINEATE_FROM_TO_X_U(s, size, from, to, sep, CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
        /**/
#    define CHAOS_PP_DELINEATE_FROM_TO_X_S_ CHAOS_PP_LAMBDA(CHAOS_PP_DELINEATE_FROM_TO_X_S_ID)()
# else
#    define CHAOS_PP_DELINEATE_FROM_TO_X_S(s, size, from, to, sep, macro, data) CHAOS_IP_DELINEATE_FROM_TO_X_U(s, size, from, to, sep, macro, (data))
# endif
#
# define CHAOS_PP_DELINEATE_FROM_TO_X_S_ID() CHAOS_PP_DELINEATE_FROM_TO_X_S
#
# define CHAOS_IP_DELINEATE_FROM_TO_X_U(s, size, from, to, sep, macro, pd) \
    CHAOS_IP_DELINEATE_FROM_TO_X_I( \
        CHAOS_PP_NEXT(s), (CHAOS_PP_NEXT(s)), CHAOS_PP_FIXED_S(s, size), \
        from, to, CHAOS_PP_EMPTY, sep, macro, CHAOS_PP_CALL(macro), pd \
    ) \
    /**/
# define CHAOS_IP_DELINEATE_FROM_TO_X_INDIRECT() CHAOS_IP_DELINEATE_FROM_TO_X_I
# define CHAOS_IP_DELINEATE_FROM_TO_X_I(s, jump, fix, from, to, s1, s2, macro, _m, pd) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, fix))( \
        CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, CHAOS_PP_PREV(fix)))( \
            CHAOS_IP_DELINEATE_FROM_TO_X_II, CHAOS_IP_DELINEATE_FROM_TO_X_III \
        ), \
        CHAOS_IP_DELINEATE_FROM_TO_X_V \
    )(CHAOS_PP_PHASE(0), s, jump, fix, from, to, s1, s2, macro, _m, pd) \
    /**/
# define CHAOS_IP_DELINEATE_FROM_TO_X_II(_, s, jump, fix, from, to, s1, s2, macro, _m, pd) \
    _(1, CHAOS_PP_EXPR_S)(s)( \
        CHAOS_IP_DELINEATE_FROM_TO_X_III(_, s, (CHAOS_PP_NEXT(s)) jump, fix, from, to, s1, s2, macro, _m, pd) \
    ) \
    /**/
# define CHAOS_IP_DELINEATE_FROM_TO_X_III(_, s, jump, fix, from, to, s1, s2, macro, _m, pd) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(from, to))( \
        CHAOS_IP_DELINEATE_FROM_TO_X_IV, CHAOS_PP_TUPLE_EAT(11) CHAOS_PP_OBSTRUCT() \
    )(_, s, jump, fix, from, to, s1, s2, macro, _m, pd) \
    /**/
# define CHAOS_IP_DELINEATE_FROM_TO_X_IV(_, s, jump, fix, from, to, s1, s2, macro, _m, pd) \
    _(1, s1)() _(0, _m)()(s, macro, from _(0, CHAOS_PP_EXPOSE)(pd)) \
    _(1, CHAOS_PP_EXPR_S)(s)(_(1, CHAOS_IP_DELINEATE_FROM_TO_X_INDIRECT)()( \
        CHAOS_PP_NEXT(s), jump, fix, CHAOS_PP_INC(from), to, s2, s2, macro, _m, pd \
    )) \
    /**/
# define CHAOS_IP_DELINEATE_FROM_TO_X_V(_, s, jump, fix, from, to, s1, s2, macro, _m, pd) \
    CHAOS_IP_DELINEATE_FROM_TO_X_VI(CHAOS_PP_SEQ_HEAD(jump), CHAOS_PP_SEQ_TAIL(jump), fix, from, to, s1, s2, macro, _m, pd) \
    /**/
# define CHAOS_IP_DELINEATE_FROM_TO_X_VI(s, jump, fix, from, to, s1, s2, macro, _m, pd) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, CHAOS_PP_PREV(fix)))( \
        CHAOS_IP_DELINEATE_FROM_TO_X_II, CHAOS_IP_DELINEATE_FROM_TO_X_III \
    )(CHAOS_PP_PHASE(1), s, CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_NIL(jump))((s), jump), fix, from, to, s1, s2, macro, _m, pd) \
    /**/
#
# endif
