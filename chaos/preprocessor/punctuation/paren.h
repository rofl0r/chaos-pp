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
# ifndef CHAOS_PREPROCESSOR_PUNCTUATION_PAREN_H
# define CHAOS_PREPROCESSOR_PUNCTUATION_PAREN_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_LPAREN */
#
# define CHAOS_PP_LPAREN() (
# define CHAOS_PP_LPAREN_ID() CHAOS_PP_LPAREN
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LPAREN_ CHAOS_PP_LAMBDA(CHAOS_PP_LPAREN)
# endif
#
# /* CHAOS_PP_RPAREN */
#
# define CHAOS_PP_RPAREN() )
# define CHAOS_PP_RPAREN_ID() CHAOS_PP_RPAREN
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_RPAREN_ CHAOS_PP_LAMBDA(CHAOS_PP_RPAREN)
# endif
#
# endif
