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
# ifndef CHAOS_PREPROCESSOR_TUPLE_AUTO_TRANSFORM_H
# define CHAOS_PREPROCESSOR_TUPLE_AUTO_TRANSFORM_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/higher_order.h>
# include <chaos/preprocessor/tuple/transform.h>
#
# /* CHAOS_PP_TUPLE_AUTO_TRANSFORM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_AUTO_TRANSFORM CHAOS_PP_CAT(CHAOS_IP_TUPLE_AUTO_TRANSFORM_, CHAOS_PP_HIGHER_ORDER())
#    define CHAOS_PP_TUPLE_AUTO_TRANSFORM_ID() CHAOS_PP_TUPLE_AUTO_TRANSFORM
#    define CHAOS_PP_TUPLE_AUTO_TRANSFORM_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_AUTO_TRANSFORM_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_TUPLE_AUTO_TRANSFORM_1(...) CHAOS_PP_HIGHER_ORDER(1)(, CHAOS_PP_EXPR(CHAOS_PP_TUPLE_TRANSFORM(__VA_ARGS__)))
#    define CHAOS_IP_TUPLE_AUTO_TRANSFORM_2(...) CHAOS_PP_HIGHER_ORDER(2)(, CHAOS_PP_EXPR(CHAOS_PP_TUPLE_TRANSFORM(__VA_ARGS__)))
#    define CHAOS_IP_TUPLE_AUTO_TRANSFORM_3(...) CHAOS_PP_HIGHER_ORDER(3)(, CHAOS_PP_EXPR(CHAOS_PP_TUPLE_TRANSFORM(__VA_ARGS__)))
#    define CHAOS_IP_TUPLE_AUTO_TRANSFORM_4(...) CHAOS_PP_HIGHER_ORDER(4)(, CHAOS_PP_EXPR(CHAOS_PP_TUPLE_TRANSFORM(__VA_ARGS__)))
#    define CHAOS_IP_TUPLE_AUTO_TRANSFORM_5(...) CHAOS_PP_HIGHER_ORDER(5)(, CHAOS_PP_EXPR(CHAOS_PP_TUPLE_TRANSFORM(__VA_ARGS__)))
#    define CHAOS_IP_TUPLE_AUTO_TRANSFORM_6(...) CHAOS_PP_HIGHER_ORDER(6)(, CHAOS_PP_EXPR(CHAOS_PP_TUPLE_TRANSFORM(__VA_ARGS__)))
#    define CHAOS_IP_TUPLE_AUTO_TRANSFORM_7(...) CHAOS_PP_HIGHER_ORDER(7)(, CHAOS_PP_EXPR(CHAOS_PP_TUPLE_TRANSFORM(__VA_ARGS__)))
#    define CHAOS_IP_TUPLE_AUTO_TRANSFORM_8(...) CHAOS_PP_HIGHER_ORDER(8)(, CHAOS_PP_EXPR(CHAOS_PP_TUPLE_TRANSFORM(__VA_ARGS__)))
# endif
#
# endif
