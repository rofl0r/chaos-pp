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
# ifndef CHAOS_PREPROCESSOR_REPETITION_X_ENUM_H
# define CHAOS_PREPROCESSOR_REPETITION_X_ENUM_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/repetition/x/delineate.h>
#
# /* CHAOS_PP_ENUM_X */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUM_X(size, count, ...) CHAOS_PP_ENUM_X_S(CHAOS_PP_STATE(), size, count, __VA_ARGS__)
#    define CHAOS_PP_ENUM_X_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUM_X_ID)()
# else
#    define CHAOS_PP_ENUM_X(size, count, macro, data) CHAOS_PP_ENUM_X_S(CHAOS_PP_STATE(), size, count, macro, data)
# endif
#
# define CHAOS_PP_ENUM_X_ID() CHAOS_PP_ENUM_X
#
# /* CHAOS_PP_ENUM_X_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENUM_X_S(s, size, count, ...) CHAOS_PP_DELINEATE_X_S(s, size, count, CHAOS_PP_COMMA, __VA_ARGS__)
#    define CHAOS_PP_ENUM_X_S_ CHAOS_PP_LAMBDA(CHAOS_PP_ENUM_X_S_ID)()
# else
#    define CHAOS_PP_ENUM_X_S(s, size, count, macro, data) CHAOS_PP_DELINEATE_X_S(s, size, count, CHAOS_PP_COMMA, macro, data)
# endif
#
# define CHAOS_PP_ENUM_X_S_ID() CHAOS_PP_ENUM_X_S
#
# endif
