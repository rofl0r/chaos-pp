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
# ifndef CHAOS_PREPROCESSOR_LAMBDA_CLOSURE_H
# define CHAOS_PREPROCESSOR_LAMBDA_CLOSURE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/execute.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/punctuation/paren.h>
#
# /* CHAOS_PP_CLOSURE */
#
# define CHAOS_PP_CLOSURE(macro, arity) \
    CHAOS_PP_ELEMENT(macro) CHAOS_PP_ELEMENT(()) \
    CHAOS_PP_OPERATOR(CHAOS_PP_LPAREN) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_CLOSURE_, arity) \
    /**/
# define CHAOS_PP_CLOSURE_ID() CHAOS_PP_CLOSURE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CLOSURE_ CHAOS_PP_LAMBDA(CHAOS_PP_CLOSURE_ID)()
# endif
#
# define CHAOS_IP_CLOSURE_I(arg, n) CHAOS_PP_ELEMENT(arg) CHAOS_PP_OPERATOR(CHAOS_PP_COMMA) CHAOS_IP_CLOSURE_ ## n
#
# define CHAOS_IP_CLOSURE_0 CHAOS_PP_OPERATOR(CHAOS_PP_RPAREN) CHAOS_IP_CLOSURE_A
# define CHAOS_IP_CLOSURE_1(arg) CHAOS_PP_ELEMENT(arg) CHAOS_IP_CLOSURE_0
# define CHAOS_IP_CLOSURE_2(arg) CHAOS_IP_CLOSURE_I(arg, 1)
# define CHAOS_IP_CLOSURE_3(arg) CHAOS_IP_CLOSURE_I(arg, 2)
# define CHAOS_IP_CLOSURE_4(arg) CHAOS_IP_CLOSURE_I(arg, 3)
# define CHAOS_IP_CLOSURE_5(arg) CHAOS_IP_CLOSURE_I(arg, 4)
# define CHAOS_IP_CLOSURE_6(arg) CHAOS_IP_CLOSURE_I(arg, 5)
# define CHAOS_IP_CLOSURE_7(arg) CHAOS_IP_CLOSURE_I(arg, 6)
# define CHAOS_IP_CLOSURE_8(arg) CHAOS_IP_CLOSURE_I(arg, 7)
# define CHAOS_IP_CLOSURE_9(arg) CHAOS_IP_CLOSURE_I(arg, 8)
# define CHAOS_IP_CLOSURE_10(arg) CHAOS_IP_CLOSURE_I(arg, 9)
# define CHAOS_IP_CLOSURE_11(arg) CHAOS_IP_CLOSURE_I(arg, 10)
# define CHAOS_IP_CLOSURE_12(arg) CHAOS_IP_CLOSURE_I(arg, 11)
# define CHAOS_IP_CLOSURE_13(arg) CHAOS_IP_CLOSURE_I(arg, 12)
# define CHAOS_IP_CLOSURE_14(arg) CHAOS_IP_CLOSURE_I(arg, 13)
# define CHAOS_IP_CLOSURE_15(arg) CHAOS_IP_CLOSURE_I(arg, 14)
# define CHAOS_IP_CLOSURE_16(arg) CHAOS_IP_CLOSURE_I(arg, 15)
# define CHAOS_IP_CLOSURE_17(arg) CHAOS_IP_CLOSURE_I(arg, 16)
# define CHAOS_IP_CLOSURE_18(arg) CHAOS_IP_CLOSURE_I(arg, 17)
# define CHAOS_IP_CLOSURE_19(arg) CHAOS_IP_CLOSURE_I(arg, 18)
# define CHAOS_IP_CLOSURE_20(arg) CHAOS_IP_CLOSURE_I(arg, 19)
# define CHAOS_IP_CLOSURE_21(arg) CHAOS_IP_CLOSURE_I(arg, 20)
# define CHAOS_IP_CLOSURE_22(arg) CHAOS_IP_CLOSURE_I(arg, 21)
# define CHAOS_IP_CLOSURE_23(arg) CHAOS_IP_CLOSURE_I(arg, 22)
# define CHAOS_IP_CLOSURE_24(arg) CHAOS_IP_CLOSURE_I(arg, 23)
# define CHAOS_IP_CLOSURE_25(arg) CHAOS_IP_CLOSURE_I(arg, 24)
#
# define CHAOS_IP_CLOSURE_A(arg) CHAOS_IP_CLOSURE_B
# define CHAOS_IP_CLOSURE_B(arg) CHAOS_IP_CLOSURE_A
#
# define CHAOS_IP_CLOSURE_A0x0
# define CHAOS_IP_CLOSURE_B0x0
#
# /* CHAOS_PP_DIRECT_CLOSURE */
#
# define CHAOS_PP_DIRECT_CLOSURE(macro, arity) \
    CHAOS_PP_ELEMENT(macro) \
    CHAOS_PP_OPERATOR(CHAOS_PP_LPAREN) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_CLOSURE_, arity) \
    /**/
# define CHAOS_PP_DIRECT_CLOSURE_ID() CHAOS_PP_DIRECT_CLOSURE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DIRECT_CLOSURE_ CHAOS_PP_LAMBDA(CHAOS_PP_DIRECT_CLOSURE_ID)()
# endif
#
# /* CHAOS_PP_IS_BOUND */
#
# define CHAOS_PP_IS_BOUND(cl) \
    CHAOS_PP_IS_NULLARY(CHAOS_PP_CAT( \
        CHAOS_PP_EXPAND(CHAOS_IP_IS_BOUND_I CHAOS_PP_PRIMITIVE_CAT(cl, 0x0)), \
        0x0 \
    )) \
    /**/
# define CHAOS_PP_IS_BOUND_ID() CHAOS_PP_IS_BOUND
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_BOUND_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_BOUND)
# endif
#
# define CHAOS_IP_IS_BOUND_INDIRECT() CHAOS_IP_IS_BOUND_I
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_IS_BOUND_I(...) CHAOS_IP_IS_BOUND_INDIRECT
# else
#    define CHAOS_IP_IS_BOUND_I(bit, x) CHAOS_IP_IS_BOUND_INDIRECT
# endif
#
# define CHAOS_IP_IS_BOUND_I0x0 ()
#
# /* CHAOS_PP_DISPATCH */
#
# define CHAOS_PP_DISPATCH(cl) CHAOS_PP_EXECUTE(CHAOS_PP_PRIMITIVE_CAT(cl, 0x0))
# define CHAOS_PP_DISPATCH_ID() CHAOS_PP_DISPATCH
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DISPATCH_ CHAOS_PP_LAMBDA(CHAOS_PP_DISPATCH_ID)()
# endif
#
# endif
