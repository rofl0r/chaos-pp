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
# ifndef CHAOS_PREPROCESSOR_REPETITION_AUTO_ENUM_H
# define CHAOS_PREPROCESSOR_REPETITION_AUTO_ENUM_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/higher_order.h>
# include <chaos/preprocessor/repetition/enum.h>
#
# /* CHAOS_PP_AUTO_ENUM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_ENUM CHAOS_PP_CAT(CHAOS_IP_AUTO_ENUM_, CHAOS_PP_HIGHER_ORDER())
#    define CHAOS_PP_AUTO_ENUM_ID() CHAOS_PP_AUTO_ENUM
#    define CHAOS_PP_AUTO_ENUM_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_ENUM_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_AUTO_ENUM_1(...) CHAOS_PP_HIGHER_ORDER(1)(, CHAOS_PP_EXPR(CHAOS_PP_ENUM(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_ENUM_2(...) CHAOS_PP_HIGHER_ORDER(2)(, CHAOS_PP_EXPR(CHAOS_PP_ENUM(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_ENUM_3(...) CHAOS_PP_HIGHER_ORDER(3)(, CHAOS_PP_EXPR(CHAOS_PP_ENUM(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_ENUM_4(...) CHAOS_PP_HIGHER_ORDER(4)(, CHAOS_PP_EXPR(CHAOS_PP_ENUM(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_ENUM_5(...) CHAOS_PP_HIGHER_ORDER(5)(, CHAOS_PP_EXPR(CHAOS_PP_ENUM(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_ENUM_6(...) CHAOS_PP_HIGHER_ORDER(6)(, CHAOS_PP_EXPR(CHAOS_PP_ENUM(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_ENUM_7(...) CHAOS_PP_HIGHER_ORDER(7)(, CHAOS_PP_EXPR(CHAOS_PP_ENUM(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_ENUM_8(...) CHAOS_PP_HIGHER_ORDER(8)(, CHAOS_PP_EXPR(CHAOS_PP_ENUM(__VA_ARGS__)))
# endif
#
# endif
