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
# ifndef CHAOS_PREPROCESSOR_DETECTION_IS_TERNARY_H
# define CHAOS_PREPROCESSOR_DETECTION_IS_TERNARY_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_IS_TERNARY */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_TERNARY(...) CHAOS_PP_IS_NULLARY(CHAOS_IP_IS_TERNARY_C __VA_ARGS__)
#    define CHAOS_PP_IS_TERNARY_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_TERNARY)
# else
#    define CHAOS_PP_IS_TERNARY(x) CHAOS_PP_IS_NULLARY(CHAOS_IP_IS_TERNARY_C x)
# endif
#
# define CHAOS_PP_IS_TERNARY_ID() CHAOS_PP_IS_TERNARY
#
# define CHAOS_IP_IS_TERNARY_C(a, b, c) ()
#
# endif
