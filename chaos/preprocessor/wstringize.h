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
# ifndef CHAOS_PREPROCESSOR_WSTRINGIZE_H
# define CHAOS_PREPROCESSOR_WSTRINGIZE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_WSTRINGIZE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WSTRINGIZE(...) CHAOS_PP_PRIMITIVE_WSTRINGIZE(__VA_ARGS__)
#    define CHAOS_PP_WSTRINGIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_WSTRINGIZE)
# else
#    define CHAOS_PP_WSTRINGIZE(x) CHAOS_PP_PRIMITIVE_WSTRINGIZE(x)
# endif
#
# define CHAOS_PP_WSTRINGIZE_ID() CHAOS_PP_WSTRINGIZE
#
# /* CHAOS_PP_PRIMITIVE_WSTRINGIZE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PRIMITIVE_WSTRINGIZE(...) CHAOS_PP_PRIMITIVE_CAT(L, #__VA_ARGS__)
#    define CHAOS_PP_PRIMITIVE_WSTRINGIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_PRIMITIVE_WSTRINGIZE)
# else
#    define CHAOS_PP_PRIMITIVE_WSTRINGIZE(x) CHAOS_PP_PRIMITIVE_CAT(L, #x)
# endif
#
# define CHAOS_PP_PRIMITIVE_WSTRINGIZE_ID() CHAOS_PP_PRIMITIVE_WSTRINGIZE
#
# endif
