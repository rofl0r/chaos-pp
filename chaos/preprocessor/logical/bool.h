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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_BOOL_H
# define CHAOS_PREPROCESSOR_LOGICAL_BOOL_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/logical/not.h>
#
# /* CHAOS_PP_BOOL */
#
# define CHAOS_PP_BOOL(x) CHAOS_PP_COMPL(CHAOS_PP_NOT(x))
# define CHAOS_PP_BOOL_ID() CHAOS_PP_BOOL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BOOL_ CHAOS_PP_LAMBDA(CHAOS_PP_BOOL)
# endif
#
# endif
