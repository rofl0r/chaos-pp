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
# ifndef CHAOS_PREPROCESSOR_EXTENDED_REVERSE_CAT_H
# define CHAOS_PREPROCESSOR_EXTENDED_REVERSE_CAT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_REVERSE_CAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REVERSE_CAT(a, ...) CHAOS_PP_PRIMITIVE_REVERSE_CAT(a, __VA_ARGS__)
#    define CHAOS_PP_REVERSE_CAT_ CHAOS_PP_LAMBDA(CHAOS_PP_REVERSE_CAT_ID)()
# else
#    define CHAOS_PP_REVERSE_CAT(a, b) CHAOS_PP_PRIMITIVE_REVERSE_CAT(a, b)
# endif
#
# define CHAOS_PP_REVERSE_CAT_ID() CHAOS_PP_REVERSE_CAT
#
# /* CHAOS_PP_PRIMITIVE_REVERSE_CAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PRIMITIVE_REVERSE_CAT(a, ...) __VA_ARGS__ ## a
#    define CHAOS_PP_PRIMITIVE_REVERSE_CAT_ CHAOS_PP_LAMBDA(CHAOS_PP_PRIMITIVE_REVERSE_CAT_ID)()
# else
#    define CHAOS_PP_PRIMITIVE_REVERSE_CAT(a, b) b ## a
# endif
#
# define CHAOS_PP_PRIMITIVE_REVERSE_CAT_ID() CHAOS_PP_PRIMITIVE_REVERSE_CAT
#
# endif
