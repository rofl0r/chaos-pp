# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_COMPARISON_GREATER_EQUAL_H
# define CHAOS_PREPROCESSOR_COMPARISON_GREATER_EQUAL_H
#
# include <chaos/preprocessor/comparison/less.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/names.h>
#
# /* CHAOS_PP_GREATER_EQUAL */
#
# define CHAOS_PP_GREATER_EQUAL(x, y) CHAOS_PP_COMPL(CHAOS_PP_LESS(x, y))
# define CHAOS_PP_GREATER_EQUAL_ID() CHAOS_PP_GREATER_EQUAL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_GREATER_EQUAL_ CHAOS_PP_LAMBDA(CHAOS_PP_GREATER_EQUAL)
# endif
#
# if CHAOS_PP_NO_PREFIX
#    define GREATER_EQUAL    CHAOS_PP_NO_PREFIX(GREATER_EQUAL)
#    define GREATER_EQUAL_   CHAOS_PP_NO_PREFIX(GREATER_EQUAL_)
#    define GREATER_EQUAL_ID CHAOS_PP_NO_PREFIX(GREATER_EQUAL_ID)
# endif
#
# endif
