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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_AUTO_FOR_EACH_H
# define CHAOS_PREPROCESSOR_ALGORITHM_AUTO_FOR_EACH_H
#
# include <chaos/preprocessor/algorithm/for_each.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/higher_order.h>
#
# /* CHAOS_PP_AUTO_FOR_EACH */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_FOR_EACH CHAOS_PP_CAT(CHAOS_IP_AUTO_FOR_EACH_, CHAOS_PP_HIGHER_ORDER())
#    define CHAOS_PP_AUTO_FOR_EACH_ID() CHAOS_PP_AUTO_FOR_EACH
#    define CHAOS_PP_AUTO_FOR_EACH_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_FOR_EACH_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_AUTO_FOR_EACH_1(...) CHAOS_PP_HIGHER_ORDER(1)(, CHAOS_PP_EXPR(CHAOS_PP_FOR_EACH(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOR_EACH_2(...) CHAOS_PP_HIGHER_ORDER(2)(, CHAOS_PP_EXPR(CHAOS_PP_FOR_EACH(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOR_EACH_3(...) CHAOS_PP_HIGHER_ORDER(3)(, CHAOS_PP_EXPR(CHAOS_PP_FOR_EACH(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOR_EACH_4(...) CHAOS_PP_HIGHER_ORDER(4)(, CHAOS_PP_EXPR(CHAOS_PP_FOR_EACH(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOR_EACH_5(...) CHAOS_PP_HIGHER_ORDER(5)(, CHAOS_PP_EXPR(CHAOS_PP_FOR_EACH(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOR_EACH_6(...) CHAOS_PP_HIGHER_ORDER(6)(, CHAOS_PP_EXPR(CHAOS_PP_FOR_EACH(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOR_EACH_7(...) CHAOS_PP_HIGHER_ORDER(7)(, CHAOS_PP_EXPR(CHAOS_PP_FOR_EACH(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_FOR_EACH_8(...) CHAOS_PP_HIGHER_ORDER(8)(, CHAOS_PP_EXPR(CHAOS_PP_FOR_EACH(__VA_ARGS__)))
# endif
#
# endif
