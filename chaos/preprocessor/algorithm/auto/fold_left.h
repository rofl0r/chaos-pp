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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_AUTO_FOLD_LEFT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_AUTO_FOLD_LEFT_H
#
# include <chaos/preprocessor/algorithm/fold_left.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/higher_order.h>
#
# /* CHAOS_PP_AUTO_FOLD_LEFT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_FOLD_LEFT CHAOS_PP_CAT(CHAOS_IP_AUTO_FOLD_LEFT_, CHAOS_PP_HIGHER_ORDER())
#    define CHAOS_PP_AUTO_FOLD_LEFT_ID() CHAOS_PP_AUTO_FOLD_LEFT
#    define CHAOS_PP_AUTO_FOLD_LEFT_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_FOLD_LEFT_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_AUTO_FOLD_LEFT_1(...) CHAOS_PP_HIGHER_ORDER(1)(, CHAOS_PP_EXPR(CHAOS_PP_FOLD_LEFT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOLD_LEFT_2(...) CHAOS_PP_HIGHER_ORDER(2)(, CHAOS_PP_EXPR(CHAOS_PP_FOLD_LEFT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOLD_LEFT_3(...) CHAOS_PP_HIGHER_ORDER(3)(, CHAOS_PP_EXPR(CHAOS_PP_FOLD_LEFT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOLD_LEFT_4(...) CHAOS_PP_HIGHER_ORDER(4)(, CHAOS_PP_EXPR(CHAOS_PP_FOLD_LEFT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOLD_LEFT_5(...) CHAOS_PP_HIGHER_ORDER(5)(, CHAOS_PP_EXPR(CHAOS_PP_FOLD_LEFT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOLD_LEFT_6(...) CHAOS_PP_HIGHER_ORDER(6)(, CHAOS_PP_EXPR(CHAOS_PP_FOLD_LEFT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOLD_LEFT_7(...) CHAOS_PP_HIGHER_ORDER(7)(, CHAOS_PP_EXPR(CHAOS_PP_FOLD_LEFT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOLD_LEFT_8(...) CHAOS_PP_HIGHER_ORDER(8)(, CHAOS_PP_EXPR(CHAOS_PP_FOLD_LEFT(__VA_ARGS__)))
# endif
#
# endif
