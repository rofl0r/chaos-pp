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
# ifndef CHAOS_PREPROCESSOR_SEQ_FOLD_RIGHT_H
# define CHAOS_PREPROCESSOR_SEQ_FOLD_RIGHT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/control/iif.h>
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
# /* CHAOS_PP_SEQ_FOLD_RIGHT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FOLD_RIGHT(op, seq, ...) CHAOS_PP_SEQ_FOLD_RIGHT_S(CHAOS_PP_STATE(), op, seq, __VA_ARGS__)
#    define CHAOS_PP_SEQ_FOLD_RIGHT_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FOLD_RIGHT_ID)()
# else
#    define CHAOS_PP_SEQ_FOLD_RIGHT(op, seq, state) CHAOS_PP_SEQ_FOLD_RIGHT_S(CHAOS_PP_STATE(), op, seq, state)
# endif
#
# define CHAOS_PP_SEQ_FOLD_RIGHT_ID() CHAOS_PP_SEQ_FOLD_RIGHT
#
# /* CHAOS_PP_SEQ_FOLD_RIGHT_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FOLD_RIGHT_S(s, op, seq, ...) \
        CHAOS_PP_EXPAND(CHAOS_IP_SEQ_FOLD_RIGHT_I( \
            CHAOS_PP_SEQ_INFUSE(seq, 1, CHAOS_PP_NEXT(s), op, CHAOS_PP_PLANAR(op))(0,), \
            (__VA_ARGS__) \
        )) \
        /**/
#    define CHAOS_PP_SEQ_FOLD_RIGHT_S_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FOLD_RIGHT_S_ID)()
#    define CHAOS_IP_SEQ_FOLD_RIGHT_A(i, ...) CHAOS_PP_IIF(i)(CHAOS_IP_SEQ_FOLD_RIGHT_A_I, CHAOS_PP_TUPLE_EAT(?))(__VA_ARGS__)
#    define CHAOS_IP_SEQ_FOLD_RIGHT_A_I(s, op, _o, ...) _o()(s, op) __VA_ARGS__, CHAOS_IP_SEQ_FOLD_RIGHT_A_INDIRECT
#    define CHAOS_IP_SEQ_FOLD_RIGHT_B(i, ...) CHAOS_PP_EXPR_IIF(i)(CHAOS_PP_PLANAR_CLOSE() CHAOS_IP_SEQ_FOLD_RIGHT_B_INDIRECT)
# else
#    define CHAOS_PP_SEQ_FOLD_RIGHT_S(s, op, seq, state) \
        CHAOS_PP_EXPAND(CHAOS_IP_SEQ_FOLD_RIGHT_I( \
            CHAOS_PP_SEQ_INFUSE(seq, (1, CHAOS_PP_NEXT(s), op, CHAOS_PP_PLANAR(op)))((0, ~, ~, ~), ~), \
            (state) \
        )) \
        /**/
#    define CHAOS_IP_SEQ_FOLD_RIGHT_A(aux, x) CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_SEQ_FOLD_RIGHT_A_I)(CHAOS_PP_TUPLE_REM(4) aux, x))
#    define CHAOS_IP_SEQ_FOLD_RIGHT_A_I(i, s, op, _o, x) CHAOS_PP_IIF(i)(CHAOS_IP_SEQ_FOLD_RIGHT_A_II, CHAOS_PP_TUPLE_EAT(4))(s, op, _o, x)
#    define CHAOS_IP_SEQ_FOLD_RIGHT_A_II(s, op, _o, x) _o()(s, op) x, CHAOS_IP_SEQ_FOLD_RIGHT_A_INDIRECT
#    define CHAOS_IP_SEQ_FOLD_RIGHT_B(aux, x) CHAOS_PP_EXPR_IIF(CHAOS_PP_TUPLE_ELEM(4, 0, aux))(CHAOS_PP_PLANAR_CLOSE() CHAOS_IP_SEQ_FOLD_RIGHT_B_INDIRECT)
# endif
#
# define CHAOS_PP_SEQ_FOLD_RIGHT_S_ID() CHAOS_PP_SEQ_FOLD_RIGHT_S
#
# define CHAOS_IP_SEQ_FOLD_RIGHT_I(seq, pd) CHAOS_IP_SEQ_FOLD_RIGHT_A seq CHAOS_PP_UNPACK pd CHAOS_IP_SEQ_FOLD_RIGHT_B seq
# define CHAOS_IP_SEQ_FOLD_RIGHT_A_INDIRECT() CHAOS_IP_SEQ_FOLD_RIGHT_A
# define CHAOS_IP_SEQ_FOLD_RIGHT_B_INDIRECT() CHAOS_IP_SEQ_FOLD_RIGHT_B
#
# endif
