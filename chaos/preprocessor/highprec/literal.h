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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_LITERAL_H
# define CHAOS_PREPROCESSOR_HIGHPREC_LITERAL_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/highprec/detail/fix.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/to_tuple.h>
# include <chaos/preprocessor/string/spec.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_LITERAL_HP */
#
# define CHAOS_PP_LITERAL_HP(literal) CHAOS_PP_LITERAL_HP_BYPASS(CHAOS_PP_LIMIT_EXPR, literal)
# define CHAOS_PP_LITERAL_HP_ID() CHAOS_PP_LITERAL_HP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LITERAL_HP_ CHAOS_PP_LAMBDA(CHAOS_PP_LITERAL_HP)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LITERAL_HP_BYPASS(s, literal) \
        CHAOS_PP_FIX_HP(CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(literal))( \
            (CHAOS_PP_EXPR_S(s)(CHAOS_IP_LITERAL_HP_I( \
                CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), CHAOS_PP_TUPLE_EAT(1) literal, 10, \
            )), 1), \
            (CHAOS_PP_EXPR_S(s)(CHAOS_IP_LITERAL_HP_I( \
                CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), literal, 10, \
            )), 0) \
        )) \
        /**/
#    define CHAOS_PP_LITERAL_HP_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_LITERAL_HP_BYPASS)
#    define CHAOS_IP_LITERAL_HP_I(_, s, string, c, ...) \
        CHAOS_PP_IIF _(CHAOS_PP_STRING_IS_CONS(string))( \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_LITERAL_HP_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_STRING_REST _(string), CHAOS_PP_DEC(c), __VA_ARGS__, CHAOS_PP_STRING_FIRST _(string) \
            )), \
            CHAOS_IP_LITERAL_HP_II _(c, __VA_ARGS__) \
        ) \
        /**/
#    define CHAOS_IP_LITERAL_HP_II(c, _, ...) (CHAOS_IP_LITERAL_HP_ ## c __VA_ARGS__)
#    define CHAOS_IP_LITERAL_HP_0
#    define CHAOS_IP_LITERAL_HP_1 0,
#    define CHAOS_IP_LITERAL_HP_2 0, 0,
#    define CHAOS_IP_LITERAL_HP_3 0, 0, 0,
#    define CHAOS_IP_LITERAL_HP_4 0, 0, 0, 0,
#    define CHAOS_IP_LITERAL_HP_5 0, 0, 0, 0, 0,
#    define CHAOS_IP_LITERAL_HP_6 0, 0, 0, 0, 0, 0,
#    define CHAOS_IP_LITERAL_HP_7 0, 0, 0, 0, 0, 0, 0,
#    define CHAOS_IP_LITERAL_HP_8 0, 0, 0, 0, 0, 0, 0, 0,
#    define CHAOS_IP_LITERAL_HP_9 0, 0, 0, 0, 0, 0, 0, 0, 0,
# else
#    define CHAOS_PP_LITERAL_HP_BYPASS(s, literal) \
        CHAOS_PP_FIX_HP(CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(literal))( \
            (CHAOS_PP_EXPR_S(s)(CHAOS_IP_LITERAL_HP_I( \
                CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), CHAOS_PP_TUPLE_EAT(1) literal, 10, CHAOS_IP_LITERAL_HP_ID \
            )), 1), \
            (CHAOS_PP_EXPR_S(s)(CHAOS_IP_LITERAL_HP_I( \
                CHAOS_PP_OBSTRUCT(), CHAOS_PP_PREV(s), literal, 10, CHAOS_IP_LITERAL_HP_ID \
            )), 0) \
        )) \
        /**/
#    define CHAOS_IP_LITERAL_HP_ID(digit) (digit)
#    define CHAOS_IP_LITERAL_HP_I(_, s, string, c, res) \
        CHAOS_PP_IIF _(CHAOS_PP_STRING_IS_CONS(string))( \
            CHAOS_PP_EXPR_S(s) _(CHAOS_IP_LITERAL_HP_INDIRECT _()( \
                CHAOS_PP_OBSTRUCT _(), CHAOS_PP_PREV(s), CHAOS_PP_STRING_REST _(string), CHAOS_PP_DEC(c), res _(CHAOS_PP_STRING_FIRST _(string)) \
            )), \
            CHAOS_IP_LITERAL_HP_II _(c, res) \
        ) \
        /**/
#    define CHAOS_IP_LITERAL_HP_II(c, res) CHAOS_PP_SEQ_TO_TUPLE(CHAOS_IP_LITERAL_HP_ ## c res)
#    define CHAOS_IP_LITERAL_HP_0
#    define CHAOS_IP_LITERAL_HP_1 (0)
#    define CHAOS_IP_LITERAL_HP_2 (0)(0)
#    define CHAOS_IP_LITERAL_HP_3 (0)(0)(0)
#    define CHAOS_IP_LITERAL_HP_4 (0)(0)(0)(0)
#    define CHAOS_IP_LITERAL_HP_5 (0)(0)(0)(0)(0)
#    define CHAOS_IP_LITERAL_HP_6 (0)(0)(0)(0)(0)(0)
#    define CHAOS_IP_LITERAL_HP_7 (0)(0)(0)(0)(0)(0)(0)
#    define CHAOS_IP_LITERAL_HP_8 (0)(0)(0)(0)(0)(0)(0)(0)
#    define CHAOS_IP_LITERAL_HP_9 (0)(0)(0)(0)(0)(0)(0)(0)(0)
# endif
#
# define CHAOS_PP_LITERAL_HP_BYPASS_ID() CHAOS_PP_LITERAL_HP_BYPASS
#
# define CHAOS_IP_LITERAL_HP_INDIRECT() CHAOS_IP_LITERAL_HP_I
#
# endif
