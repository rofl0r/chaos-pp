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
# ifndef CHAOS_PREPROCESSOR_RECURSION_CONTEXT_H
# define CHAOS_PREPROCESSOR_RECURSION_CONTEXT_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/auto_rec.h>
#
# /* CHAOS_PP_CONTEXT */
#
# define CHAOS_PP_CONTEXT(bit) CHAOS_IP_CONTEXT_I(CHAOS_IP_CONTEXT_N(), bit)
# define CHAOS_PP_CONTEXT_ID() CHAOS_PP_CONTEXT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CONTEXT_ CHAOS_PP_LAMBDA(CHAOS_PP_CONTEXT)
# endif
#
# define CHAOS_IP_CONTEXT_N() CHAOS_PP_AUTO_REC(CHAOS_IP_CONTEXT_P, 16)
# define CHAOS_IP_CONTEXT_P(n) \
    CHAOS_PP_IS_NULLARY(CHAOS_IP_CONTEXT_ ## n ## _0(CHAOS_IP_CONTEXT_ ## n ## _1(()))) \
    /**/
#
# define CHAOS_IP_CONTEXT_I(n, bit) CHAOS_IP_CONTEXT_II(n, bit)
# define CHAOS_IP_CONTEXT_II(n, bit) CHAOS_IP_CONTEXT_ ## n ## _ ## bit
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_CONTEXT_1_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_1_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_2_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_2_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_3_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_3_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_4_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_4_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_5_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_5_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_6_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_6_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_7_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_7_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_8_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_8_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_9_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_9_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_10_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_10_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_11_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_11_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_12_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_12_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_13_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_13_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_14_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_14_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_15_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_15_1(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_16_0(...) __VA_ARGS__
#    define CHAOS_IP_CONTEXT_16_1(...) __VA_ARGS__
# else
#    define CHAOS_IP_CONTEXT_1_0(x) x
#    define CHAOS_IP_CONTEXT_1_1(x) x
#    define CHAOS_IP_CONTEXT_2_0(x) x
#    define CHAOS_IP_CONTEXT_2_1(x) x
#    define CHAOS_IP_CONTEXT_3_0(x) x
#    define CHAOS_IP_CONTEXT_3_1(x) x
#    define CHAOS_IP_CONTEXT_4_0(x) x
#    define CHAOS_IP_CONTEXT_4_1(x) x
#    define CHAOS_IP_CONTEXT_5_0(x) x
#    define CHAOS_IP_CONTEXT_5_1(x) x
#    define CHAOS_IP_CONTEXT_6_0(x) x
#    define CHAOS_IP_CONTEXT_6_1(x) x
#    define CHAOS_IP_CONTEXT_7_0(x) x
#    define CHAOS_IP_CONTEXT_7_1(x) x
#    define CHAOS_IP_CONTEXT_8_0(x) x
#    define CHAOS_IP_CONTEXT_8_1(x) x
#    define CHAOS_IP_CONTEXT_9_0(x) x
#    define CHAOS_IP_CONTEXT_9_1(x) x
#    define CHAOS_IP_CONTEXT_10_0(x) x
#    define CHAOS_IP_CONTEXT_10_1(x) x
#    define CHAOS_IP_CONTEXT_11_0(x) x
#    define CHAOS_IP_CONTEXT_11_1(x) x
#    define CHAOS_IP_CONTEXT_12_0(x) x
#    define CHAOS_IP_CONTEXT_12_1(x) x
#    define CHAOS_IP_CONTEXT_13_0(x) x
#    define CHAOS_IP_CONTEXT_13_1(x) x
#    define CHAOS_IP_CONTEXT_14_0(x) x
#    define CHAOS_IP_CONTEXT_14_1(x) x
#    define CHAOS_IP_CONTEXT_15_0(x) x
#    define CHAOS_IP_CONTEXT_15_1(x) x
#    define CHAOS_IP_CONTEXT_16_0(x) x
#    define CHAOS_IP_CONTEXT_16_1(x) x
# endif
#
# /* CHAOS_PP_ABSOLUTE */
#
# define CHAOS_PP_ABSOLUTE(n) \
    CHAOS_IP_ABSOLUTE_I(CHAOS_IP_ABSOLUTE_A(n, 0)(n, 1)) \
    /**/
# define CHAOS_PP_ABSOLUTE_ID() CHAOS_PP_ABSOLUTE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ABSOLUTE_ CHAOS_PP_LAMBDA(CHAOS_PP_ABSOLUTE)
# endif
#
# define CHAOS_IP_ABSOLUTE_I(res) \
    CHAOS_PP_EXPR_IIF(CHAOS_PP_IS_UNARY(res))(CHAOS_PP_SPLIT(0, CHAOS_IP_ABSOLUTE_II res)) \
    /**/
# define CHAOS_IP_ABSOLUTE_II(x) x, ...
#
# define CHAOS_IP_ABSOLUTE_A(n, bit) CHAOS_PP_IIF(CHAOS_PP_IS_NULLARY(CHAOS_IP_CONTEXT_I(n, bit)(())))(CHAOS_IP_ABSOLUTE_B, (bit))
# define CHAOS_IP_ABSOLUTE_B(n, bit) CHAOS_PP_IIF(CHAOS_PP_IS_NULLARY(CHAOS_IP_CONTEXT_I(n, bit)(())))(CHAOS_IP_ABSOLUTE_A, (bit))
#
# /* CHAOS_PP_RELATIVE */
#
# define CHAOS_PP_RELATIVE(n) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_RELATIVE_, n)(CHAOS_IP_CONTEXT_N())
# define CHAOS_PP_RELATIVE_ID() CHAOS_PP_RELATIVE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_RELATIVE_ CHAOS_PP_LAMBDA(CHAOS_PP_RELATIVE)
# endif
#
# define CHAOS_IP_RELATIVE_0(n) CHAOS_PP_ABSOLUTE(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_1(n) CHAOS_IP_RELATIVE_0(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_2(n) CHAOS_IP_RELATIVE_1(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_3(n) CHAOS_IP_RELATIVE_2(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_4(n) CHAOS_IP_RELATIVE_3(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_5(n) CHAOS_IP_RELATIVE_4(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_6(n) CHAOS_IP_RELATIVE_5(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_7(n) CHAOS_IP_RELATIVE_6(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_8(n) CHAOS_IP_RELATIVE_7(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_9(n) CHAOS_IP_RELATIVE_8(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_10(n) CHAOS_IP_RELATIVE_9(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_11(n) CHAOS_IP_RELATIVE_10(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_12(n) CHAOS_IP_RELATIVE_11(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_13(n) CHAOS_IP_RELATIVE_12(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_14(n) CHAOS_IP_RELATIVE_13(CHAOS_PP_DEC(n))
# define CHAOS_IP_RELATIVE_15(n) CHAOS_IP_RELATIVE_14(CHAOS_PP_DEC(n))
#
# /* CHAOS_PP_RETRIEVE */
#
# define CHAOS_PP_RETRIEVE() CHAOS_PP_RELATIVE(0)
# define CHAOS_PP_RETRIEVE_ID() CHAOS_PP_RETRIEVE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_RETRIEVE_ CHAOS_PP_LAMBDA(CHAOS_PP_RETRIEVE)
# endif
#
# endif
