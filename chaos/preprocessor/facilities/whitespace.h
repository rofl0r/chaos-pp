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
# ifndef CHAOS_PREPROCESSOR_FACILITIES_WHITESPACE_H
# define CHAOS_PREPROCESSOR_FACILITIES_WHITESPACE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/extended/reverse_cat.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_NO_LEADING */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NO_LEADING(...) CHAOS_PP_PRIMITIVE_CAT(, __VA_ARGS__)
#    define CHAOS_PP_NO_LEADING_ID() CHAOS_PP_NO_LEADING
#    define CHAOS_PP_NO_LEADING_ CHAOS_PP_LAMBDA(CHAOS_PP_NO_LEADING_ID)()
# endif
#
# /* CHAOS_PP_NO_TRAILING */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NO_TRAILING(...) CHAOS_PP_PRIMITIVE_REVERSE_CAT(, __VA_ARGS__)
#    define CHAOS_PP_NO_TRAILING_ID() CHAOS_PP_NO_TRAILING
#    define CHAOS_PP_NO_TRAILING_ CHAOS_PP_LAMBDA(CHAOS_PP_NO_TRAILING_ID)()
# endif
#
# /* CHAOS_PP_CLEAN */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CLEAN(...) CHAOS_PP_NO_LEADING(CHAOS_PP_NO_TRAILING(__VA_ARGS__))
#    define CHAOS_PP_CLEAN_ID() CHAOS_PP_CLEAN
#    define CHAOS_PP_CLEAN_ CHAOS_PP_LAMBDA(CHAOS_PP_CLEAN_ID)()
# endif
#
# endif
