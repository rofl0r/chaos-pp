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
# ifndef CHAOS_PREPROCESSOR_SEQ_FOLD_RIGHT_AUX_H
# define CHAOS_PREPROCESSOR_SEQ_FOLD_RIGHT_AUX_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/lambda/planar.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/infuse.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/elem.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_SEQ_FOLD_RIGHT_AUX */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FOLD_RIGHT_AUX(op, seq, data, ...) CHAOS_PP_SEQ_FOLD_RIGHT_AUX_S(CHAOS_PP_STATE(), op, seq, data, __VA_ARGS__)
#    define CHAOS_PP_SEQ_FOLD_RIGHT_AUX_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FOLD_RIGHT_AUX_ID)()
# else
#    define CHAOS_PP_SEQ_FOLD_RIGHT_AUX(op, seq, data, state) CHAOS_PP_SEQ_FOLD_RIGHT_AUX_S(CHAOS_PP_STATE(), op, seq, data, state)
# endif
#
# define CHAOS_PP_SEQ_FOLD_RIGHT_AUX_ID() CHAOS_PP_SEQ_FOLD_RIGHT_AUX
#
# /* CHAOS_PP_SEQ_FOLD_RIGHT_AUX_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FOLD_RIGHT_AUX_S(s, op, seq, data, ...) \
        CHAOS_PP_EXPAND(CHAOS_IP_SEQ_FOLD_RIGHT_AUX_I( \
            CHAOS_PP_SEQ_INFUSE(seq, 1, CHAOS_PP_NEXT(s), op, CHAOS_PP_PLANAR(op), CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_VARIADIC(data))(CHAOS_PP_REM)(data))(0,), \
            (__VA_ARGS__) \
        )) \
        /**/
#    define CHAOS_PP_SEQ_FOLD_RIGHT_AUX_S_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FOLD_RIGHT_AUX_S_ID)()
# else
#    define CHAOS_PP_SEQ_FOLD_RIGHT_AUX_S(s, op, seq, data, state) \
        CHAOS_PP_EXPAND(CHAOS_IP_SEQ_FOLD_RIGHT_AUX_I( \
            CHAOS_PP_SEQ_INFUSE(seq, (1, CHAOS_PP_NEXT(s), op, CHAOS_PP_PLANAR(op), CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_UNARY(data))(CHAOS_PP_REM)(data)))((0, ~, ~, ~, ~), ~), \
            (state) \
        )) \
        /**/
# endif
#
# define CHAOS_PP_SEQ_FOLD_RIGHT_AUX_S_ID() CHAOS_PP_SEQ_FOLD_RIGHT_AUX_S
#
# define CHAOS_IP_SEQ_FOLD_RIGHT_AUX_I(seq, ps) CHAOS_IP_SEQ_FOLD_RIGHT_AUX_A seq CHAOS_PP_REM ps CHAOS_IP_SEQ_FOLD_RIGHT_AUX_B seq
# define CHAOS_IP_SEQ_FOLD_RIGHT_AUX_A_INDIRECT() CHAOS_IP_SEQ_FOLD_RIGHT_AUX_A
# define CHAOS_IP_SEQ_FOLD_RIGHT_AUX_B_INDIRECT() CHAOS_IP_SEQ_FOLD_RIGHT_AUX_B
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_FOLD_RIGHT_AUX_A(i, ...) CHAOS_PP_IIF(i)(CHAOS_IP_SEQ_FOLD_RIGHT_AUX_A_I, CHAOS_PP_EAT)(__VA_ARGS__)
#    define CHAOS_IP_SEQ_FOLD_RIGHT_AUX_A_I(s, op, _o, data, ...) _o()(s, op) CHAOS_PP_REM data, __VA_ARGS__, CHAOS_IP_SEQ_FOLD_RIGHT_AUX_A_INDIRECT
#    define CHAOS_IP_SEQ_FOLD_RIGHT_AUX_B(i, ...) CHAOS_PP_INLINE_WHEN(i)(CHAOS_PP_PLANAR_CLOSE() CHAOS_IP_SEQ_FOLD_RIGHT_AUX_B_INDIRECT)
# else
#    define CHAOS_IP_SEQ_FOLD_RIGHT_AUX_A(aux, x) CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_SEQ_FOLD_RIGHT_AUX_A_I)(CHAOS_PP_TUPLE_REM(5) aux, x))
#    define CHAOS_IP_SEQ_FOLD_RIGHT_AUX_A_I(i, s, op, _o, data, x) CHAOS_PP_IIF(i)(CHAOS_IP_SEQ_FOLD_RIGHT_AUX_A_II, CHAOS_PP_TUPLE_EAT(5))(s, op, _o, data, x)
#    define CHAOS_IP_SEQ_FOLD_RIGHT_AUX_A_II(s, op, _o, data, x) _o()(s, op) x, CHAOS_PP_REM data, CHAOS_IP_SEQ_FOLD_RIGHT_AUX_A_INDIRECT
#    define CHAOS_IP_SEQ_FOLD_RIGHT_AUX_B(aux, x) CHAOS_PP_INLINE_WHEN(CHAOS_PP_TUPLE_ELEM(5, 0, aux))(CHAOS_PP_PLANAR_CLOSE() CHAOS_IP_SEQ_FOLD_RIGHT_AUX_B_INDIRECT)
# endif
#
# endif
