# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003-2004.                             *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_CONTROL_IF_H
# define CHAOS_PREPROCESSOR_CONTROL_IF_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bool.h>
#
# /* CHAOS_PP_IF */
#
# define CHAOS_PP_IF(cond) CHAOS_PP_IIF(CHAOS_PP_BOOL(cond))
# define CHAOS_PP_IF_ID() CHAOS_PP_IF
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IF_ CHAOS_PP_LAMBDA(CHAOS_PP_IF)
# endif
#
# define CHAOS_PP_IF_SHADOW(cond) CHAOS_PP_IIF_SHADOW(CHAOS_PP_BOOL(cond))
#
# endif
