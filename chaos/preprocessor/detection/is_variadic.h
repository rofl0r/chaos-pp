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
# ifndef CHAOS_PREPROCESSOR_DETECTION_IS_VARIADIC_H
# define CHAOS_PREPROCESSOR_DETECTION_IS_VARIADIC_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_IS_VARIADIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_VARIADIC(...) CHAOS_PP_IS_NULLARY(CHAOS_IP_IS_VARIADIC_C __VA_ARGS__)
#    define CHAOS_PP_IS_VARIADIC_ID() CHAOS_PP_IS_VARIADIC
#    define CHAOS_PP_IS_VARIADIC_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_VARIADIC)
#    define CHAOS_IP_IS_VARIADIC_C(...) ()
# endif
#
# endif
