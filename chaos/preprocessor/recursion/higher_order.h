# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_RECURSION_HIGHER_ORDER_H
# define CHAOS_PREPROCESSOR_RECURSION_HIGHER_ORDER_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/auto_rec.h>
#
# /* CHAOS_PP_HIGHER_ORDER */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_HIGHER_ORDER(e) CHAOS_IP_HIGHER_ORDER_ ## e
#    define CHAOS_PP_HIGHER_ORDER_ID() CHAOS_PP_HIGHER_ORDER
#    define CHAOS_PP_HIGHER_ORDER_ CHAOS_PP_LAMBDA(CHAOS_PP_HIGHER_ORDER)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_HIGHER_ORDER_ CHAOS_PP_AUTO_REC(CHAOS_IP_HIGHER_ORDER_P, 8)
#    define CHAOS_IP_HIGHER_ORDER_P(e) CHAOS_PP_IS_NULLARY(CHAOS_IP_HIGHER_ORDER_ ## e(, ()))
#    define CHAOS_IP_HIGHER_ORDER_1(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_HIGHER_ORDER_2(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_HIGHER_ORDER_3(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_HIGHER_ORDER_4(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_HIGHER_ORDER_5(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_HIGHER_ORDER_6(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_HIGHER_ORDER_7(p, ...) p ## __VA_ARGS__
#    define CHAOS_IP_HIGHER_ORDER_8(p, ...) p ## __VA_ARGS__
# endif
#
# endif
