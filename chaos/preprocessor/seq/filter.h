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
# ifndef CHAOS_PREPROCESSOR_SEQ_FILTER_H
# define CHAOS_PREPROCESSOR_SEQ_FILTER_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/expand.h>
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
# /* CHAOS_PP_SEQ_FILTER */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FILTER(pred, ...) CHAOS_PP_SEQ_FILTER_S(CHAOS_PP_STATE(), pred, __VA_ARGS__)
#    define CHAOS_PP_SEQ_FILTER_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FILTER_ID)()
# else
#    define CHAOS_PP_SEQ_FILTER(pred, seq, data) CHAOS_PP_SEQ_FILTER_S(CHAOS_PP_STATE(), pred, seq, data)
# endif
#
# define CHAOS_PP_SEQ_FILTER_ID() CHAOS_PP_SEQ_FILTER
#
# /* CHAOS_PP_SEQ_FILTER_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FILTER_S(s, pred, ...) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_SEQ_FILTER_I \
            CHAOS_PP_SEQ_INFUSE(CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), 1, CHAOS_PP_NEXT(s), pred, CHAOS_PP_CALL(pred), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
            (0,) \
        ) \
        /**/
#    define CHAOS_PP_SEQ_FILTER_S_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FILTER_S_ID)()
#    define CHAOS_IP_SEQ_FILTER_I(i, ...) \
        CHAOS_PP_IIF(i)(CHAOS_IP_SEQ_FILTER_II, CHAOS_PP_TUPLE_EAT(?))(CHAOS_PP_OBSTRUCT(), __VA_ARGS__) \
        /**/
#    define CHAOS_IP_SEQ_FILTER_II(_, s, pred, _p, pd, ...) \
        CHAOS_PP_EXPR_IIF _(_p()(s, pred, __VA_ARGS__ CHAOS_PP_EXPOSE(pd)))( \
            (__VA_ARGS__) \
        ) CHAOS_IP_SEQ_FILTER_INDIRECT \
        /**/
# else
#    define CHAOS_PP_SEQ_FILTER_S(s, pred, seq, data) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_SEQ_FILTER_I \
            CHAOS_PP_SEQ_INFUSE(seq, (1, CHAOS_PP_NEXT(s), pred, CHAOS_PP_CALL(pred), data)) \
            ((0, ~, ~, ~, ~), ~) \
        ) \
        /**/
#    define CHAOS_IP_SEQ_FILTER_I(aux, x) \
        CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_SEQ_FILTER_II)(CHAOS_PP_TUPLE_REM(5) aux, x)) \
        /**/
#    define CHAOS_IP_SEQ_FILTER_II(i, s, pred, _p, data, x) \
        CHAOS_PP_IIF(i)(CHAOS_IP_SEQ_FILTER_III, CHAOS_PP_TUPLE_EAT(6))(CHAOS_PP_OBSTRUCT(), s, pred, _p, data, x) \
        /**/
#    define CHAOS_IP_SEQ_FILTER_III(_, s, pred, _p, data, x) \
        CHAOS_PP_EXPR_IIF _(_p()(s, pred, x CHAOS_PP_COMMA() data))( \
            (x) \
        ) CHAOS_IP_SEQ_FILTER_INDIRECT \
        /**/
# endif
#
# define CHAOS_PP_SEQ_FILTER_S_ID() CHAOS_PP_SEQ_FILTER_S
#
# define CHAOS_IP_SEQ_FILTER_INDIRECT() CHAOS_IP_SEQ_FILTER_I
#
# endif
