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
# ifndef CHAOS_PREPROCESSOR_SEQ_FOR_EACH_H
# define CHAOS_PREPROCESSOR_SEQ_FOR_EACH_H
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
# /* CHAOS_PP_SEQ_FOR_EACH */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FOR_EACH(macro, ...) CHAOS_PP_SEQ_FOR_EACH_S(CHAOS_PP_STATE(), macro, __VA_ARGS__)
#    define CHAOS_PP_SEQ_FOR_EACH_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FOR_EACH_ID)()
# else
#    define CHAOS_PP_SEQ_FOR_EACH(macro, seq, data) CHAOS_PP_SEQ_FOR_EACH_S(CHAOS_PP_STATE(), macro, seq, data)
# endif
#
# define CHAOS_PP_SEQ_FOR_EACH_ID() CHAOS_PP_SEQ_FOR_EACH
#
# /* CHAOS_PP_SEQ_FOR_EACH_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FOR_EACH_S(s, macro, ...) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_SEQ_FOR_EACH_I \
            CHAOS_PP_SEQ_INFUSE(CHAOS_PP_NON_OPTIONAL(__VA_ARGS__), 1, CHAOS_PP_NEXT(s), macro, CHAOS_PP_CALL(macro), CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
            (0,) \
        ) \
        /**/
#    define CHAOS_PP_SEQ_FOR_EACH_S_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FOR_EACH_S_ID)()
#    define CHAOS_IP_SEQ_FOR_EACH_I(i, ...) \
        CHAOS_PP_IIF(i)(CHAOS_IP_SEQ_FOR_EACH_II, CHAOS_PP_TUPLE_EAT(?))(__VA_ARGS__) \
        /**/
#    define CHAOS_IP_SEQ_FOR_EACH_II(s, macro, _m, pd, ...) _m()(s, macro, __VA_ARGS__ CHAOS_PP_EXPOSE(pd)) CHAOS_IP_SEQ_FOR_EACH_INDIRECT
# else
#    define CHAOS_PP_SEQ_FOR_EACH_S(s, macro, seq, data) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_SEQ_FOR_EACH_I \
            CHAOS_PP_SEQ_INFUSE(seq, (1, CHAOS_PP_NEXT(s), macro, CHAOS_PP_CALL(macro), data)) \
            ((0, ~, ~, ~, ~), ~) \
        ) \
        /**/
#    define CHAOS_IP_SEQ_FOR_EACH_I(aux, x) \
        CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_SEQ_FOR_EACH_II)(CHAOS_PP_TUPLE_REM(5) aux, x)) \
        /**/
#    define CHAOS_IP_SEQ_FOR_EACH_II(i, s, macro, _m, data, x) \
        CHAOS_PP_IIF(i)(CHAOS_IP_SEQ_FOR_EACH_III, CHAOS_PP_TUPLE_EAT(5))(s, macro, _m, data, x) \
        /**/
#    define CHAOS_IP_SEQ_FOR_EACH_III(s, macro, _m, data, x) _m()(s, macro, x CHAOS_PP_COMMA() data) CHAOS_IP_SEQ_FOR_EACH_INDIRECT
# endif
#
# define CHAOS_PP_SEQ_FOR_EACH_S_ID() CHAOS_PP_SEQ_FOR_EACH_S
#
# define CHAOS_IP_SEQ_FOR_EACH_INDIRECT() CHAOS_IP_SEQ_FOR_EACH_I
#
# endif
