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
# ifndef CHAOS_PREPROCESSOR_CAT_H
# define CHAOS_PREPROCESSOR_CAT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_CAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CAT(a, ...) CHAOS_PP_PRIMITIVE_CAT(a, __VA_ARGS__)
#    define CHAOS_PP_CAT_ CHAOS_PP_LAMBDA(CHAOS_PP_CAT_ID)()
# else
#    define CHAOS_PP_CAT(a, b) CHAOS_PP_PRIMITIVE_CAT(a, b)
# endif
#
# define CHAOS_PP_CAT_ID() CHAOS_PP_CAT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CAT_SHADOW(a, ...) CHAOS_PP_PRIMITIVE_CAT_SHADOW(a, __VA_ARGS__)
# else
#    define CHAOS_PP_CAT_SHADOW(a, b) CHAOS_PP_PRIMITIVE_CAT_SHADOW(a, b)
# endif
#
# /* CHAOS_PP_PRIMITIVE_CAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#    define CHAOS_PP_PRIMITIVE_CAT_ CHAOS_PP_LAMBDA(CHAOS_PP_PRIMITIVE_CAT_ID)()
# else
#    define CHAOS_PP_PRIMITIVE_CAT(a, b) a ## b
# endif
#
# define CHAOS_PP_PRIMITIVE_CAT_ID() CHAOS_PP_PRIMITIVE_CAT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PRIMITIVE_CAT_SHADOW(a, ...) a ## __VA_ARGS__
# else
#    define CHAOS_PP_PRIMITIVE_CAT_SHADOW(a, b) a ## b
# endif
#
# endif
