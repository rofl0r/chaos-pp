# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003-2004.                             *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_X_FOLD_RIGHT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_X_FOLD_RIGHT_H
#
# include <chaos/preprocessor/comparison/not_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/buffer.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/phase.h>
# include <chaos/preprocessor/seq/spec.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_FOLD_RIGHT_X */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_RIGHT_X(size, op, g, ...) CHAOS_PP_FOLD_RIGHT_X_S(CHAOS_PP_STATE(), size, op, g, __VA_ARGS__)
#    define CHAOS_PP_FOLD_RIGHT_X_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_RIGHT_X_ID)()
# else
#    define CHAOS_PP_FOLD_RIGHT_X(size, op, g, state) CHAOS_PP_FOLD_RIGHT_X_S(CHAOS_PP_STATE(), size, op, g, state)
# endif
#
# define CHAOS_PP_FOLD_RIGHT_X_ID() CHAOS_PP_FOLD_RIGHT_X
#
# /* CHAOS_PP_FOLD_RIGHT_X_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FOLD_RIGHT_X_S(s, size, op, g, ...) CHAOS_IP_FOLD_RIGHT_X_U(s, size, op, g, (__VA_ARGS__))
#    define CHAOS_PP_FOLD_RIGHT_X_S_ CHAOS_PP_LAMBDA(CHAOS_PP_FOLD_RIGHT_X_S_ID)()
# else
#    define CHAOS_PP_FOLD_RIGHT_X_S(s, size, op, g, state) CHAOS_IP_FOLD_RIGHT_X_U(s, size, op, g, (state))
# endif
#
# define CHAOS_PP_FOLD_RIGHT_X_S_ID() CHAOS_PP_FOLD_RIGHT_X_S
#
# define CHAOS_IP_FOLD_RIGHT_X_U(s, size, op, g, ps) \
    CHAOS_IP_FOLD_RIGHT_X_I( \
        CHAOS_PP_NEXT(s), (CHAOS_PP_NEXT(s)), CHAOS_PP_FIXED_S(s, size), \
        0, op, CHAOS_PP_CALL(op), CHAOS_PP_TYPEOF(g), g, CHAOS_PP_NIL(CHAOS_PP_TYPEOF(g)), ps \
    ) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_X_INDIRECT() CHAOS_IP_FOLD_RIGHT_X_I
# define CHAOS_IP_FOLD_RIGHT_X_I(s, jump, fix, mode, op, _o, type, g, res, ps) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, fix))( \
        CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, CHAOS_PP_PREV(fix)))( \
            CHAOS_IP_FOLD_RIGHT_X_II, CHAOS_IP_FOLD_RIGHT_X_III \
        ), \
        CHAOS_IP_FOLD_RIGHT_X_V \
    )(CHAOS_PP_PHASE(0), s, jump, fix, mode, op, _o, type, g, res, ps) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_X_II(_, s, jump, fix, mode, op, _o, type, g, res, ps) \
    _(1, CHAOS_PP_EXPR_S)(s)( \
        CHAOS_IP_FOLD_RIGHT_X_III(_, s, (CHAOS_PP_NEXT(s)) jump, fix, mode, op, _o, type, g, res, ps) \
    ) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_X_III(_, s, jump, fix, mode, op, _o, type, g, res, ps) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(g))( \
        CHAOS_IP_FOLD_RIGHT_X_ ## mode, \
        CHAOS_PP_IIF(mode)( \
            CHAOS_PP_UNPACK ps CHAOS_PP_TUPLE_EAT(11), \
            CHAOS_IP_FOLD_RIGHT_X_IV \
        ) \
    )(_, s, jump, fix, mode, op, _o, type, g, res, ps) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_X_IV(_, s, jump, fix, mode, op, _o, type, g, res, ps) \
    CHAOS_PP_IIF(CHAOS_PP_IS_CONS(res))( \
        CHAOS_IP_FOLD_RIGHT_X_1, CHAOS_PP_UNPACK ps CHAOS_PP_TUPLE_EAT(11) \
    )(_, s, jump, fix, 1, op, _o, type, res, g, ps) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_X_V(_, s, jump, fix, mode, op, _o, type, g, res, ps) \
    CHAOS_IP_FOLD_RIGHT_X_VI(CHAOS_PP_SEQ_FIRST(jump), CHAOS_PP_SEQ_REST(jump), fix, mode, op, _o, type, g, res, ps) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_X_VI(s, jump, fix, mode, op, _o, type, g, res, ps) \
    CHAOS_PP_IIF(CHAOS_PP_NOT_EQUAL(s, CHAOS_PP_PREV(fix)))( \
        CHAOS_IP_FOLD_RIGHT_X_II, CHAOS_IP_FOLD_RIGHT_X_III \
    )(CHAOS_PP_PHASE(1), s, CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_NIL(jump))((s), jump), fix, mode, op, _o, type, g, res, ps) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_X_0(_, s, jump, fix, mode, op, _o, type, g, res, ps) \
    _(1, CHAOS_PP_EXPR_S)(s)(_(1, CHAOS_IP_FOLD_RIGHT_X_INDIRECT)()( \
        CHAOS_PP_NEXT(s), jump, fix, mode, op, _o, type, CHAOS_PP_REST(g), CHAOS_PP_CONS(res, CHAOS_PP_FIRST(g)), ps \
    )) \
    /**/
# define CHAOS_IP_FOLD_RIGHT_X_1(_, s, jump, fix, mode, op, _o, type, g, res, ps) \
    _(1, CHAOS_PP_EXPR_S)(s)(_(1, CHAOS_IP_FOLD_RIGHT_X_INDIRECT)()( \
        CHAOS_PP_NEXT(s), jump, fix, mode, op, _o, type, CHAOS_PP_REST(g), res, (_(0, _o)()(s, op, CHAOS_PP_ITEM(type, CHAOS_PP_FIRST(g)) _(0, CHAOS_PP_COMMA)() CHAOS_PP_UNPACK ps)) \
    )) \
    /**/
#
# endif
