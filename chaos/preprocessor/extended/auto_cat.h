# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2004.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_EXTENDED_AUTO_CAT_H
# define CHAOS_PREPROCESSOR_EXTENDED_AUTO_CAT_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/facilities/intercept.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/auto_rec.h>
#
# /* CHAOS_PP_AUTO_CAT */
#
# define CHAOS_PP_AUTO_CAT CHAOS_PP_CAT(CHAOS_IP_AUTO_CAT_, CHAOS_PP_AUTO_REC(CHAOS_IP_AUTO_CAT_P, 16))
# define CHAOS_PP_AUTO_CAT_ID() CHAOS_PP_AUTO_CAT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_CAT_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_CAT_ID)()
# endif
#
# define CHAOS_IP_AUTO_CAT_P(n) CHAOS_PP_IS_NULLARY(CHAOS_IP_AUTO_CAT_ ## n(CHAOS_PP_INTERCEPT, 0)())
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_AUTO_CAT_1(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_1(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_2(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_2(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_3(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_3(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_4(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_4(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_5(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_5(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_6(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_6(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_7(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_7(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_8(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_8(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_9(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_9(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_10(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_10(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_11(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_11(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_12(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_12(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_13(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_13(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_14(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_14(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_15(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_15(a, __VA_ARGS__)
#    define CHAOS_IP_AUTO_CAT_16(a, ...) CHAOS_IP_PRIMITIVE_AUTO_CAT_16(a, __VA_ARGS__)
# else
#    define CHAOS_IP_AUTO_CAT_1(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_1(a, b)
#    define CHAOS_IP_AUTO_CAT_2(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_2(a, b)
#    define CHAOS_IP_AUTO_CAT_3(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_3(a, b)
#    define CHAOS_IP_AUTO_CAT_4(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_4(a, b)
#    define CHAOS_IP_AUTO_CAT_5(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_5(a, b)
#    define CHAOS_IP_AUTO_CAT_6(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_6(a, b)
#    define CHAOS_IP_AUTO_CAT_7(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_7(a, b)
#    define CHAOS_IP_AUTO_CAT_8(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_8(a, b)
#    define CHAOS_IP_AUTO_CAT_9(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_9(a, b)
#    define CHAOS_IP_AUTO_CAT_10(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_10(a, b)
#    define CHAOS_IP_AUTO_CAT_11(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_11(a, b)
#    define CHAOS_IP_AUTO_CAT_12(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_12(a, b)
#    define CHAOS_IP_AUTO_CAT_13(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_13(a, b)
#    define CHAOS_IP_AUTO_CAT_14(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_14(a, b)
#    define CHAOS_IP_AUTO_CAT_15(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_15(a, b)
#    define CHAOS_IP_AUTO_CAT_16(a, b) CHAOS_IP_PRIMITIVE_AUTO_CAT_16(a, b)
# endif
#
# /* CHAOS_PP_PRIMITIVE_AUTO_CAT */
#
# define CHAOS_PP_PRIMITIVE_AUTO_CAT CHAOS_PP_CAT(CHAOS_IP_PRIMITIVE_AUTO_CAT_, CHAOS_PP_AUTO_REC(CHAOS_IP_AUTO_CAT_P, 16))
# define CHAOS_PP_PRIMITIVE_AUTO_CAT_ID() CHAOS_PP_PRIMITIVE_AUTO_CAT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PRIMITIVE_AUTO_CAT_ CHAOS_PP_LAMBDA(CHAOS_PP_PRIMITIVE_AUTO_CAT_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_1(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_2(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_3(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_4(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_5(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_6(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_7(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_8(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_9(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_10(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_11(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_12(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_13(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_14(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_15(a, ...) a ## __VA_ARGS__
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_16(a, ...) a ## __VA_ARGS__
# else
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_1(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_2(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_3(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_4(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_5(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_6(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_7(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_8(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_9(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_10(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_11(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_12(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_13(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_14(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_15(a, b) a ## b
#    define CHAOS_IP_PRIMITIVE_AUTO_CAT_16(a, b) a ## b
# endif
#
# endif
