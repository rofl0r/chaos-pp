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
# ifndef CHAOS_PREPROCESSOR_LAMBDA_EXECUTE_H
# define CHAOS_PREPROCESSOR_LAMBDA_EXECUTE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ELEMENT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ELEMENT(...) (1, __VA_ARGS__)
#    define CHAOS_PP_ELEMENT_ CHAOS_PP_LAMBDA(CHAOS_PP_ELEMENT_ID)()
# else
#    define CHAOS_PP_ELEMENT(x) (1, x)
# endif
#
# define CHAOS_PP_ELEMENT_ID() CHAOS_PP_ELEMENT
#
# /* CHAOS_PP_OPERATOR */
#
# define CHAOS_PP_OPERATOR(op) (0, op)
# define CHAOS_PP_OPERATOR_ID() CHAOS_PP_OPERATOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_OPERATOR_ CHAOS_PP_LAMBDA(CHAOS_PP_OPERATOR)
# endif
#
# /* CHAOS_PP_EXECUTE */
#
# define CHAOS_PP_EXECUTE(il) \
    CHAOS_PP_EXPAND( \
        CHAOS_IP_EXECUTE_X \
            CHAOS_PP_CAT(CHAOS_IP_EXECUTE_A il, 0)(CHAOS_PP_TUPLE_EAT, ...) \
    ) \
    /**/
# define CHAOS_PP_EXECUTE_ID() CHAOS_PP_EXECUTE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EXECUTE_ CHAOS_PP_LAMBDA(CHAOS_PP_EXECUTE_ID)()
# endif
#
# define CHAOS_IP_EXECUTE_A0
# define CHAOS_IP_EXECUTE_B0
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_EXECUTE_A(b, ...) (CHAOS_PP_TUPLE_REM, __VA_ARGS__ CHAOS_PP_EXPR_IIF(b)(CHAOS_PP_EMPTY)) CHAOS_IP_EXECUTE_B
#    define CHAOS_IP_EXECUTE_B(b, ...) (CHAOS_PP_TUPLE_REM, __VA_ARGS__ CHAOS_PP_EXPR_IIF(b)(CHAOS_PP_EMPTY)) CHAOS_IP_EXECUTE_A
#    define CHAOS_IP_EXECUTE_X(m, ...) m(?)(__VA_ARGS__() CHAOS_IP_EXECUTE_Y)
#    define CHAOS_IP_EXECUTE_Y(m, ...) m(?)(__VA_ARGS__() CHAOS_IP_EXECUTE_X)
# else
#    define CHAOS_IP_EXECUTE_A(b, x) (CHAOS_PP_TUPLE_REM, x CHAOS_PP_EXPR_IIF(b)(CHAOS_PP_EMPTY)) CHAOS_IP_EXECUTE_B
#    define CHAOS_IP_EXECUTE_B(b, x) (CHAOS_PP_TUPLE_REM, x CHAOS_PP_EXPR_IIF(b)(CHAOS_PP_EMPTY)) CHAOS_IP_EXECUTE_A
#    define CHAOS_IP_EXECUTE_X(m, x) m(1)(x() CHAOS_IP_EXECUTE_Y)
#    define CHAOS_IP_EXECUTE_Y(m, x) m(1)(x() CHAOS_IP_EXECUTE_X)
# endif
#
# endif
