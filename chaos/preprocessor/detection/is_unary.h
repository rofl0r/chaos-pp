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
# ifndef CHAOS_PREPROCESSOR_DETECTION_IS_UNARY_H
# define CHAOS_PREPROCESSOR_DETECTION_IS_UNARY_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_IS_UNARY */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_UNARY(...) CHAOS_PP_IS_NULLARY(CHAOS_IP_IS_UNARY_C __VA_ARGS__)
#    define CHAOS_PP_IS_UNARY_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_UNARY)
# else
#    define CHAOS_PP_IS_UNARY(x) CHAOS_PP_IS_NULLARY(CHAOS_IP_IS_UNARY_C x)
# endif
#
# define CHAOS_PP_IS_UNARY_ID() CHAOS_PP_IS_UNARY
#
# define CHAOS_IP_IS_UNARY_C(a) ()
#
# endif
