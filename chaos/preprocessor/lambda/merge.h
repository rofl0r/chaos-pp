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
# ifndef CHAOS_PREPROCESSOR_LAMBDA_MERGE_H
# define CHAOS_PREPROCESSOR_LAMBDA_MERGE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_empty.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/spec.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/elem.h>
#
# /* CHAOS_PP_MERGE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MERGE(expr, ...) CHAOS_PP_MERGE_S(CHAOS_PP_STATE(), expr, __VA_ARGS__)
#    define CHAOS_PP_MERGE_ID() CHAOS_PP_MERGE
#    define CHAOS_PP_MERGE_ CHAOS_PP_LAMBDA(CHAOS_PP_MERGE_ID)()
# endif
#
# /* CHAOS_PP_MERGE_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MERGE_S(s, expr, ...) \
        CHAOS_PP_EXPR_S(s)( \
            CHAOS_IP_MERGE_I(, CHAOS_PP_NEXT(s), CHAOS_PP_NEXT(s), expr, \
                ( \
                    CHAOS_PP_FLAG(0xSTATE), __VA_ARGS__, \
                    CHAOS_IP_MERGE_SHIFT_A \
                        (1)(2)(3)(4)(5)(6)(7)(8)(9)(10)(11)(12)(13)(14)(15)(16)(17)(18)(19)(20)(21)(22)(23)(24) \
                ), expr \
            ) \
        ) \
        /**/
#    define CHAOS_PP_MERGE_S_ID() CHAOS_PP_MERGE_S
#    define CHAOS_PP_MERGE_S_ CHAOS_PP_LAMBDA(CHAOS_PP_MERGE_S_ID)()
#    define CHAOS_IP_MERGE_SHIFT_A(n) CHAOS_PP_PARAM(n), CHAOS_IP_MERGE_SHIFT_B
#    define CHAOS_IP_MERGE_SHIFT_B(n) CHAOS_PP_PARAM(n), CHAOS_IP_MERGE_SHIFT_A
#    define CHAOS_IP_MERGE_INDIRECT() CHAOS_IP_MERGE_I
#    define CHAOS_IP_MERGE_I(p, s, o, orig, args, expr) \
        CHAOS_PP_IIF(CHAOS_PP_IS_VARIADIC(p ## expr))( \
            CHAOS_IP_MERGE_II, \
            expr CHAOS_PP_TUPLE_EAT(?) \
        )(, s, o, p ## orig, p ## args, p ## expr) \
        /**/
#    define CHAOS_IP_MERGE_II(p, s, o, orig, args, expr) \
        CHAOS_PP_CAT( \
            CHAOS_IP_MERGE_, \
            CHAOS_PP_FLAG_NAME((CHAOS_PP_SEQ_FIRST(p ## expr))) \
        )(, s, o, p ## orig, p ## args, (CHAOS_PP_SEQ_FIRST(p ## expr))) \
        CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_PP_DEFER(CHAOS_IP_MERGE_INDIRECT)()( \
            , CHAOS_PP_NEXT(s), o, p ## orig, p ## args, CHAOS_PP_SEQ_REST(p ## expr) \
        )) \
        /**/
#    define CHAOS_IP_MERGE_E(p, s, o, orig, args, sep, ...) \
        CHAOS_PP_DEFER(CHAOS_PP_EXPR_S(s))(CHAOS_IP_MERGE_E_I( \
            , CHAOS_PP_NEXT(s), o, p ## orig, p ## args, CHAOS_PP_EMPTY, p ## sep, p ## __VA_ARGS__, \
        )) \
        /**/
#    define CHAOS_IP_MERGE_E_INDIRECT() CHAOS_IP_MERGE_E_I
#    define CHAOS_IP_MERGE_E_I(p, s, o, orig, args, s1, s2, ...) \
        CHAOS_PP_IIF(CHAOS_PP_IS_EMPTY_NON_FUNCTION(p ## __VA_ARGS__))( \
            CHAOS_PP_TUPLE_EAT(?), \
            CHAOS_IP_MERGE_E_II \
        )(, CHAOS_PP_OBSTRUCT(), s, o, p ## orig, p ## args, p ## s1, p ## s2, __VA_ARGS__) \
        /**/
#    define CHAOS_IP_MERGE_E_II(p, _, s, o, orig, args, s1, s2, x, ...) \
        s1() CHAOS_PP_EXPR_S(s) _( \
            CHAOS_IP_MERGE_INDIRECT _()(, CHAOS_PP_NEXT(s), o, p ## orig, p ## args, p ## x) \
            CHAOS_IP_MERGE_E_INDIRECT _()(, CHAOS_PP_NEXT(s), o, p ## orig, p ## args, p ## s2, p ## s2, p ## __VA_ARGS__) \
        ) \
        /**/
#    define CHAOS_IP_MERGE_(p, s, o, orig, args, expr) \
        (CHAOS_IP_MERGE_E(, s, o, p ## orig, p ## args, CHAOS_PP_COMMA, CHAOS_PP_TUPLE_REM(?) expr)) \
        /**/
#    define CHAOS_IP_MERGE_0xCOMMA(...) CHAOS_PP_FLAG(0xCOMMA)
#    define CHAOS_IP_MERGE_0xESCAPE(p, s, o, orig, args, flag) CHAOS_PP_ESCAPE(CHAOS_PP_FLAG_DATA(p ## flag))
#    define CHAOS_IP_MERGE_0xLAMBDA(p, s, o, orig, args, flag) \
        CHAOS_PP_DEFER(CHAOS_PP_LAMBDA)(CHAOS_IP_MERGE_E(, s, o, p ## orig, p ## args, CHAOS_PP_COMMA, CHAOS_PP_FLAG_DATA(p ## flag))) \
        /**/
#    define CHAOS_IP_MERGE_0xLPAREN(...) CHAOS_PP_FLAG(0xLPAREN)
#    define CHAOS_IP_MERGE_0xOPEN(p, s, o, orig, args, flag) \
        CHAOS_PP_DEFER(CHAOS_PP_OPEN)(CHAOS_IP_MERGE_E(, s, o, p ## orig, p ## args, CHAOS_PP_COMMA, CHAOS_PP_FLAG_DATA(p ## flag))) \
        /**/
#    define CHAOS_IP_MERGE_0xPARAM(p, s, o, orig, args, flag) CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_ELEM(?, CHAOS_PP_FLAG_DATA(p ## flag), p ## args))
#    define CHAOS_IP_MERGE_0xRPAREN(...) CHAOS_PP_FLAG(0xRPAREN)
#    define CHAOS_IP_MERGE_0xSELF(p, s, o, orig, ...) CHAOS_PP_ESCAPE(orig)
#    define CHAOS_IP_MERGE_0xSTATE(p, s, o, ...) CHAOS_PP_FLAG(0xSTATE)
# endif
#
# endif
