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
# ifndef CHAOS_PREPROCESSOR_REPETITION_AUTO_DELINEATE_TRAILING_H
# define CHAOS_PREPROCESSOR_REPETITION_AUTO_DELINEATE_TRAILING_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/higher_order.h>
# include <chaos/preprocessor/repetition/delineate_trailing.h>
#
# /* CHAOS_PP_AUTO_DELINEATE_TRAILING */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_DELINEATE_TRAILING CHAOS_PP_CAT(CHAOS_IP_AUTO_DELINEATE_TRAILING_, CHAOS_PP_HIGHER_ORDER())
#    define CHAOS_PP_AUTO_DELINEATE_TRAILING_ID() CHAOS_PP_AUTO_DELINEATE_TRAILING
#    define CHAOS_PP_AUTO_DELINEATE_TRAILING_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_DELINEATE_TRAILING_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_AUTO_DELINEATE_TRAILING_1(...) CHAOS_PP_HIGHER_ORDER(1)(, CHAOS_PP_EXPR(CHAOS_PP_DELINEATE_TRAILING(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_DELINEATE_TRAILING_2(...) CHAOS_PP_HIGHER_ORDER(2)(, CHAOS_PP_EXPR(CHAOS_PP_DELINEATE_TRAILING(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_DELINEATE_TRAILING_3(...) CHAOS_PP_HIGHER_ORDER(3)(, CHAOS_PP_EXPR(CHAOS_PP_DELINEATE_TRAILING(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_DELINEATE_TRAILING_4(...) CHAOS_PP_HIGHER_ORDER(4)(, CHAOS_PP_EXPR(CHAOS_PP_DELINEATE_TRAILING(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_DELINEATE_TRAILING_5(...) CHAOS_PP_HIGHER_ORDER(5)(, CHAOS_PP_EXPR(CHAOS_PP_DELINEATE_TRAILING(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_DELINEATE_TRAILING_6(...) CHAOS_PP_HIGHER_ORDER(6)(, CHAOS_PP_EXPR(CHAOS_PP_DELINEATE_TRAILING(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_DELINEATE_TRAILING_7(...) CHAOS_PP_HIGHER_ORDER(7)(, CHAOS_PP_EXPR(CHAOS_PP_DELINEATE_TRAILING(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_DELINEATE_TRAILING_8(...) CHAOS_PP_HIGHER_ORDER(8)(, CHAOS_PP_EXPR(CHAOS_PP_DELINEATE_TRAILING(__VA_ARGS__)))
# endif
#
# endif
