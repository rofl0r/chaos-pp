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
# ifndef CHAOS_PREPROCESSOR_LAMBDA_PARSE_H
# define CHAOS_PREPROCESSOR_LAMBDA_PARSE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_empty.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/lambda/execute.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/spec.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/elem.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_PARSE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PARSE(expr, ...) CHAOS_PP_PARSE_S(CHAOS_PP_STATE(), expr, __VA_ARGS__)
#    define CHAOS_PP_PARSE_ID() CHAOS_PP_PARSE
#    define CHAOS_PP_PARSE_ CHAOS_PP_LAMBDA(CHAOS_PP_PARSE_ID)()
# endif
#
# /* CHAOS_PP_PARSE_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PARSE_S(s, expr, ...) CHAOS_PP_PARSE_BACKDOOR(s, CHAOS_PP_NEXT(s), expr, __VA_ARGS__)
#    define CHAOS_PP_PARSE_S_ID() CHAOS_PP_PARSE_S
#    define CHAOS_PP_PARSE_S_ CHAOS_PP_LAMBDA(CHAOS_PP_PARSE_S_ID)()
#    define CHAOS_PP_PARSE_BACKDOOR(s, o, expr, ...) \
        CHAOS_PP_EXPR_S(s)( \
            CHAOS_IP_PARSE_I(, CHAOS_PP_NEXT(s), o, expr, (o, __VA_ARGS__), expr) \
        ) \
        /**/
#    define CHAOS_IP_PARSE_INDIRECT() CHAOS_IP_PARSE_I
#    define CHAOS_IP_PARSE_I(p, s, o, orig, args, expr) \
        CHAOS_PP_IIF(CHAOS_PP_IS_VARIADIC(p ## expr))( \
            CHAOS_IP_PARSE_II, \
            CHAOS_PP_ELEMENT(p ## expr) CHAOS_PP_TUPLE_EAT(?) \
        )(, s, o, p ## orig, p ## args, p ## expr) \
        /**/
#    define CHAOS_IP_PARSE_II(p, s, o, orig, args, expr) \
        CHAOS_PP_CAT( \
            CHAOS_IP_PARSE_, \
            CHAOS_PP_FLAG_NAME((CHAOS_PP_SEQ_FIRST(p ## expr))) \
        )(, s, o, p ## orig, p ## args, (CHAOS_PP_SEQ_FIRST(p ## expr))) \
        CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_IP_PARSE_INDIRECT)()( \
            , CHAOS_PP_NEXT(s), o, p ## orig, p ## args, CHAOS_PP_SEQ_REST(p ## expr) \
        )) \
        /**/
#    define CHAOS_IP_PARSE_E(p, s, o, orig, args, sep, ...) \
        CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_IP_PARSE_E_I( \
            , CHAOS_PP_NEXT(s), o, p ## orig, p ## args,, p ## sep, p ## __VA_ARGS__, \
        )) \
        /**/
#    define CHAOS_IP_PARSE_E_INDIRECT() CHAOS_IP_PARSE_E_I
#    define CHAOS_IP_PARSE_E_I(p, s, o, orig, args, s1, s2, ...) \
        CHAOS_PP_IIF(CHAOS_PP_IS_EMPTY_NON_FUNCTION(p ## __VA_ARGS__))( \
            CHAOS_PP_TUPLE_EAT(?), \
            CHAOS_IP_PARSE_E_II \
        )(, CHAOS_PP_OBSTRUCT(), s, o, p ## orig, p ## args, p ## s1, p ## s2, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_PARSE_E_II(p, _, s, o, orig, args, s1, s2, x, ...) \
        s1 CHAOS_PP_EXPR_S(s) _( \
            CHAOS_IP_PARSE_INDIRECT _()(, CHAOS_PP_NEXT(s), o, p ## orig, p ## args, p ## x) \
            CHAOS_IP_PARSE_E_INDIRECT _()(, CHAOS_PP_NEXT(s), o, p ## orig, p ## args, p ## s2, p ## s2, p ## __VA_ARGS__) \
        ) \
        /**/
#    define CHAOS_IP_PARSE_(p, s, o, orig, args, expr) \
        CHAOS_PP_OPERATOR(CHAOS_PP_LPAREN) \
        CHAOS_IP_PARSE_E(, s, o, p ## orig, p ## args, CHAOS_PP_OPERATOR(CHAOS_PP_COMMA), CHAOS_PP_TUPLE_REM(?) expr) \
        CHAOS_PP_OPERATOR(CHAOS_PP_RPAREN) \
        /**/
#    define CHAOS_IP_PARSE_0xCOMMA(...) CHAOS_PP_OPERATOR(CHAOS_PP_COMMA)
#    define CHAOS_IP_PARSE_0xESCAPE(p, s, o, orig, args, flag) CHAOS_PP_ELEMENT(CHAOS_PP_FLAG_DATA(p ## flag))
#    define CHAOS_IP_PARSE_0xLAMBDA(p, s, o, orig, args, flag) CHAOS_IP_PARSE_E(, s, o, p ## orig, p ## args,, CHAOS_PP_FLAG_DATA(p ## flag))
#    define CHAOS_IP_PARSE_0xLPAREN(...) CHAOS_PP_OPERATOR(CHAOS_PP_LPAREN)
#    define CHAOS_IP_PARSE_0xOPEN(p, s, o, orig, args, flag) CHAOS_IP_PARSE_E(, s, o, p ## orig, p ## args, CHAOS_PP_OPERATOR(CHAOS_PP_COMMA), CHAOS_PP_FLAG_DATA(p ## flag))
#    define CHAOS_IP_PARSE_0xOVERRIDE(p, s, o, orig, args, flag) CHAOS_PP_OPERATOR(CHAOS_PP_LPAREN) CHAOS_IP_PARSE_0xOPEN(, s, o, p ## orig, p ## args, p ## flag) CHAOS_PP_OPERATOR(CHAOS_PP_RPAREN)
#    define CHAOS_IP_PARSE_0xPARAM(p, s, o, orig, args, flag) \
        CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_IP_PARSE_INDIRECT)()( \
            , CHAOS_PP_NEXT(s), o, p ## orig, p ## args, CHAOS_PP_TUPLE_ELEM(?, CHAOS_PP_FLAG_DATA(p ## flag), p ## args) \
        )) \
        /**/
#    define CHAOS_IP_PARSE_0xRPAREN(...) CHAOS_PP_OPERATOR(CHAOS_PP_RPAREN)
#    define CHAOS_IP_PARSE_0xSELF(p, s, o, orig, ...) CHAOS_PP_ELEMENT(p ## orig)
#    define CHAOS_IP_PARSE_0xSTATE(p, s, o, ...) CHAOS_PP_ELEMENT(o)
# endif
#
# endif
