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
# ifndef CHAOS_PREPROCESSOR_SEQ_FOR_EACH_I_H
# define CHAOS_PREPROCESSOR_SEQ_FOR_EACH_I_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/binary_transform.h>
# include <chaos/preprocessor/seq/detail/close.h>
# include <chaos/preprocessor/seq/reverse.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/elem.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_SEQ_FOR_EACH_I */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FOR_EACH_I(macro, ...) CHAOS_PP_SEQ_FOR_EACH_I_S(CHAOS_PP_STATE(), macro, __VA_ARGS__)
#    define CHAOS_PP_SEQ_FOR_EACH_I_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FOR_EACH_I_ID)()
# else
#    define CHAOS_PP_SEQ_FOR_EACH_I(macro, seq, data) CHAOS_PP_SEQ_FOR_EACH_I_S(CHAOS_PP_STATE(), macro, seq, data)
# endif
#
# define CHAOS_PP_SEQ_FOR_EACH_I_ID() CHAOS_PP_SEQ_FOR_EACH_I
#
# /* CHAOS_PP_SEQ_FOR_EACH_I_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_FOR_EACH_I_S(s, macro, ...) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_SEQ_FOR_EACH_I_B_I \
            CHAOS_IP_SEQ_FOR_EACH_I_A_I( \
                s, macro, CHAOS_PP_SEQ_BINARY_TRANSFORM(CHAOS_PP_SEQ_REVERSE(CHAOS_PP_NON_OPTIONAL(__VA_ARGS__)),), CHAOS_PP_EXPOSE(CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__)) \
            )(0,) \
        ) \
        /**/
#    define CHAOS_PP_SEQ_FOR_EACH_I_S_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_FOR_EACH_I_S_ID)()
#    define CHAOS_IP_SEQ_FOR_EACH_I_A_I(s, macro, bin, ...) \
        CHAOS_PP_SPLIT(0, CHAOS_PP_EXPR_S(s)( \
            CHAOS_IP_SEQ_FOR_EACH_I_A_II bin, 0, CHAOS_PP_NEXT(s), macro, CHAOS_PP_CALL(macro), __VA_ARGS__ CHAOS_PP_SEQ_CLOSE(bin) \
        )) \
        /**/
#    define CHAOS_IP_SEQ_FOR_EACH_I_A_II(id, ...) \
        id(?)(CHAOS_IP_SEQ_FOR_EACH_I_A_III CHAOS_PP_OBSTRUCT() CHAOS_PP_LPAREN()(__VA_ARGS__) CHAOS_PP_COMMA() CHAOS_IP_SEQ_FOR_EACH_I_A_INDIRECT) \
        /**/
#    define CHAOS_IP_SEQ_FOR_EACH_I_A_III(...) CHAOS_IP_SEQ_FOR_EACH_I_A_IV(__VA_ARGS__)
#    define CHAOS_IP_SEQ_FOR_EACH_I_A_IV(px, r, n, s, macro, _m, ...) \
        r(1, px, n, s, macro, _m, __VA_ARGS__)(), CHAOS_PP_INC(n), s, macro, _m, __VA_ARGS__ \
        /**/
#    define CHAOS_IP_SEQ_FOR_EACH_I_B_I(i, ...) \
        CHAOS_PP_IIF(i)(CHAOS_IP_SEQ_FOR_EACH_I_B_II, CHAOS_PP_TUPLE_EAT(?))(__VA_ARGS__) \
        /**/
#    define CHAOS_IP_SEQ_FOR_EACH_I_B_II(px, n, s, macro, _m, ...) \
        _m()(s, macro, n, CHAOS_PP_UNPACK px __VA_ARGS__) CHAOS_IP_SEQ_FOR_EACH_I_B_INDIRECT \
        /**/
# else
#    define CHAOS_PP_SEQ_FOR_EACH_I_S(s, macro, seq, data) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_SEQ_FOR_EACH_I_B_I \
            CHAOS_IP_SEQ_FOR_EACH_I_A_I( \
                s, macro, CHAOS_PP_SEQ_BINARY_TRANSFORM(CHAOS_PP_SEQ_REVERSE(seq), ~), data \
            )(0, ~, ~, ~, ~, ~, ~) \
        ) \
        /**/
#    define CHAOS_IP_SEQ_FOR_EACH_I_A_I(s, macro, bin, data) \
        CHAOS_PP_TUPLE_ELEM(6, 0, CHAOS_PP_EXPR_S(s)( \
            CHAOS_IP_SEQ_FOR_EACH_I_A_II bin (CHAOS_IP_SEQ_FOR_EACH_I_A_V, 0, CHAOS_PP_NEXT(s), macro, CHAOS_PP_CALL(macro), data) CHAOS_PP_SEQ_CLOSE(bin) \
        )) \
        /**/
#    define CHAOS_IP_SEQ_FOR_EACH_I_A_II(id, x) \
        id(1)(CHAOS_IP_SEQ_FOR_EACH_I_A_III CHAOS_PP_OBSTRUCT() CHAOS_PP_LPAREN() x CHAOS_PP_COMMA() CHAOS_IP_SEQ_FOR_EACH_I_A_INDIRECT) \
        /**/
#    define CHAOS_IP_SEQ_FOR_EACH_I_A_III(x, aux) CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_SEQ_FOR_EACH_I_A_IV)(x, CHAOS_PP_TUPLE_REM(6) aux))
#    define CHAOS_IP_SEQ_FOR_EACH_I_A_IV(x, r, n, s, macro, _m, data) \
        (r(1, x, n, s, macro, _m, data)(), CHAOS_PP_INC(n), s, macro, _m, data) \
        /**/
#    define CHAOS_IP_SEQ_FOR_EACH_I_A_V(i, x, n, s, macro, _m, data) (i, x, n, s, macro, _m, data)
#    define CHAOS_IP_SEQ_FOR_EACH_I_B_I(i, x, n, s, macro, _m, data) \
        CHAOS_PP_IIF(i)(CHAOS_IP_SEQ_FOR_EACH_I_B_II, CHAOS_PP_TUPLE_EAT(6))(x, n, s, macro, _m, data) \
        /**/
#    define CHAOS_IP_SEQ_FOR_EACH_I_B_II(x, n, s, macro, _m, data) \
        _m()(s, macro, n CHAOS_PP_COMMA() x CHAOS_PP_COMMA() data) CHAOS_IP_SEQ_FOR_EACH_I_B_INDIRECT \
        /**/
# endif
#
# define CHAOS_PP_SEQ_FOR_EACH_I_S_ID() CHAOS_PP_SEQ_FOR_EACH_I_S
#
# define CHAOS_IP_SEQ_FOR_EACH_I_A_INDIRECT() CHAOS_IP_SEQ_FOR_EACH_I_A_II
# define CHAOS_IP_SEQ_FOR_EACH_I_B_INDIRECT() CHAOS_IP_SEQ_FOR_EACH_I_B_I
#
# endif
