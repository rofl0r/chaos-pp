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
# ifndef CHAOS_PREPROCESSOR_CONTROL_IIF_H
# define CHAOS_PREPROCESSOR_CONTROL_IIF_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_IIF */
#
# define CHAOS_PP_IIF(bit) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_IIF_, bit)
# define CHAOS_PP_IIF_ID() CHAOS_PP_IIF
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IIF_ CHAOS_PP_LAMBDA(CHAOS_PP_IIF)
#    define CHAOS_IP_IIF_0(t, ...) __VA_ARGS__
#    define CHAOS_IP_IIF_1(t, ...) t
# else
#    define CHAOS_IP_IIF_0(t, f) f
#    define CHAOS_IP_IIF_1(t, f) t
# endif
#
# define CHAOS_PP_IIF_SHADOW(bit) CHAOS_PP_PRIMITIVE_CAT_SHADOW(CHAOS_IP_IIF_SHADOW_, bit)
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_IIF_SHADOW_0(t, ...) __VA_ARGS__
#    define CHAOS_IP_IIF_SHADOW_1(t, ...) t
# else
#    define CHAOS_IP_IIF_SHADOW_0(t, f) f
#    define CHAOS_IP_IIF_SHADOW_1(t, f) t
# endif
#
# endif
