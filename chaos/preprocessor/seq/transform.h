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
# ifndef CHAOS_PREPROCESSOR_SEQ_TRANSFORM_H
# define CHAOS_PREPROCESSOR_SEQ_TRANSFORM_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/infuse.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_SEQ_TRANSFORM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_TRANSFORM(op, ...) CHAOS_PP_SEQ_TRANSFORM_S(CHAOS_PP_STATE(), op, __VA_ARGS__)
#    define CHAOS_PP_SEQ_TRANSFORM_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_TRANSFORM_ID)()
# else
#    define CHAOS_PP_SEQ_TRANSFORM(op, seq, data) CHAOS_PP_SEQ_TRANSFORM_S(CHAOS_PP_STATE(), op, seq, data)
# endif
#
# define CHAOS_PP_SEQ_TRANSFORM_ID() CHAOS_PP_SEQ_TRANSFORM
#
# /* CHAOS_PP_SEQ_TRANSFORM_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_TRANSFORM_S(s, op, ...) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_SEQ_TRANSFORM_I \
            CHAOS_PP_SEQ_INFUSE(CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), 1, CHAOS_PP_NEXT(s), op, CHAOS_PP_CALL(op), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
            (0,) \
        ) \
        /**/
#    define CHAOS_PP_SEQ_TRANSFORM_S_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_TRANSFORM_S_ID)()
#    define CHAOS_IP_SEQ_TRANSFORM_I(i, ...) \
        CHAOS_PP_IIF(i)(CHAOS_IP_SEQ_TRANSFORM_II, CHAOS_PP_TUPLE_EAT(?))(__VA_ARGS__) \
        /**/
#    define CHAOS_IP_SEQ_TRANSFORM_II(s, op, _o, pd, ...) (_o()(s, op, __VA_ARGS__ CHAOS_PP_EXPOSE(pd))) CHAOS_IP_SEQ_TRANSFORM_INDIRECT
# else
#    define CHAOS_PP_SEQ_TRANSFORM_S(s, op, seq, data) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_SEQ_TRANSFORM_I \
            CHAOS_PP_SEQ_INFUSE(seq, (1, CHAOS_PP_NEXT(s), op, CHAOS_PP_CALL(op), data)) \
            ((0, ~, ~, ~, ~), ~) \
        ) \
        /**/
#    define CHAOS_IP_SEQ_TRANSFORM_I(aux, x) \
        CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_SEQ_TRANSFORM_II)(CHAOS_PP_TUPLE_REM(5) aux, x)) \
        /**/
#    define CHAOS_IP_SEQ_TRANSFORM_II(i, s, op, _o, data, x) \
        CHAOS_PP_IIF(i)(CHAOS_IP_SEQ_TRANSFORM_III, CHAOS_PP_TUPLE_EAT(5))(s, op, _o, data, x) \
        /**/
#    define CHAOS_IP_SEQ_TRANSFORM_III(s, op, _o, data, x) (_o()(s, op, x CHAOS_PP_COMMA() data)) CHAOS_IP_SEQ_TRANSFORM_INDIRECT
# endif
#
# define CHAOS_PP_SEQ_TRANSFORM_S_ID() CHAOS_PP_SEQ_TRANSFORM
#
# define CHAOS_IP_SEQ_TRANSFORM_INDIRECT() CHAOS_IP_SEQ_TRANSFORM_I
#
# endif
