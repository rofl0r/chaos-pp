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
# ifndef CHAOS_PREPROCESSOR_FACILITIES_EXPAND_H
# define CHAOS_PREPROCESSOR_FACILITIES_EXPAND_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_EXPAND */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EXPAND(...) __VA_ARGS__
#    define CHAOS_PP_EXPAND_ CHAOS_PP_LAMBDA(CHAOS_PP_EXPAND_ID)()
# else
#    define CHAOS_PP_EXPAND(x) x
# endif
#
# define CHAOS_PP_EXPAND_ID() CHAOS_PP_EXPAND
#
# endif
