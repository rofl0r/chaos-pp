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
# ifndef CHAOS_PREPROCESSOR_ALGORITHM_AUTO_MERGE_SORT_H
# define CHAOS_PREPROCESSOR_ALGORITHM_AUTO_MERGE_SORT_H
#
# include <chaos/preprocessor/algorithm/merge_sort.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/higher_order.h>
#
# /* CHAOS_PP_AUTO_MERGE_SORT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_MERGE_SORT CHAOS_PP_CAT(CHAOS_IP_AUTO_MERGE_SORT_, CHAOS_PP_HIGHER_ORDER())
#    define CHAOS_PP_AUTO_MERGE_SORT_ID() CHAOS_PP_AUTO_MERGE_SORT
#    define CHAOS_PP_AUTO_MERGE_SORT_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_MERGE_SORT_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_AUTO_MERGE_SORT_1(...) CHAOS_PP_HIGHER_ORDER(1)(, CHAOS_PP_EXPR(CHAOS_PP_MERGE_SORT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_MERGE_SORT_2(...) CHAOS_PP_HIGHER_ORDER(2)(, CHAOS_PP_EXPR(CHAOS_PP_MERGE_SORT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_MERGE_SORT_3(...) CHAOS_PP_HIGHER_ORDER(3)(, CHAOS_PP_EXPR(CHAOS_PP_MERGE_SORT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_MERGE_SORT_4(...) CHAOS_PP_HIGHER_ORDER(4)(, CHAOS_PP_EXPR(CHAOS_PP_MERGE_SORT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_MERGE_SORT_5(...) CHAOS_PP_HIGHER_ORDER(5)(, CHAOS_PP_EXPR(CHAOS_PP_MERGE_SORT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_MERGE_SORT_6(...) CHAOS_PP_HIGHER_ORDER(6)(, CHAOS_PP_EXPR(CHAOS_PP_MERGE_SORT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_MERGE_SORT_7(...) CHAOS_PP_HIGHER_ORDER(7)(, CHAOS_PP_EXPR(CHAOS_PP_MERGE_SORT(__VA_ARGS__)))
#    define CHAOS_IP_AUTO_MERGE_SORT_8(...) CHAOS_PP_HIGHER_ORDER(8)(, CHAOS_PP_EXPR(CHAOS_PP_MERGE_SORT(__VA_ARGS__)))
# endif
#
# endif
