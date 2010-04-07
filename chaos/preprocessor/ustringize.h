# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_USTRINGIZE_H
# define CHAOS_PREPROCESSOR_USTRINGIZE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_USTRINGIZE */
#
# ifdef __cplusplus
#
#    define CHAOS_PP_USTRINGIZE(n) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_USTRINGIZE_, n)
#    define CHAOS_PP_USTRINGIZE_ID() CHAOS_PP_USTRINGIZE
#
#    if CHAOS_PP_VARIADICS
#        define CHAOS_PP_USTRINGIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_USTRINGIZE)
#        define CHAOS_IP_USTRINGIZE_8(...) CHAOS_IP_PRIMITIVE_USTRINGIZE_8(__VA_ARGS__)
#        define CHAOS_IP_USTRINGIZE_16(...) CHAOS_IP_PRIMITIVE_USTRINGIZE_16(__VA_ARGS__)
#        define CHAOS_IP_USTRINGIZE_32(...) CHAOS_IP_PRIMITIVE_USTRINGIZE_32(__VA_ARGS__)
#    else
#        define CHAOS_IP_USTRINGIZE_8(x) CHAOS_IP_PRIMITIVE_USTRINGIZE_8(x)
#        define CHAOS_IP_USTRINGIZE_16(x) CHAOS_IP_PRIMITIVE_USTRINGIZE_16(x)
#        define CHAOS_IP_USTRINGIZE_32(x) CHAOS_IP_PRIMITIVE_USTRINGIZE_32(x)
#    endif
#
# endif
#
# /* CHAOS_PP_PRIMITIVE_USTRINGIZE */
#
# ifdef __cplusplus
#
#    define CHAOS_PP_PRIMITIVE_USTRINGIZE(n) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_PRIMITIVE_USTRINGIZE_, n)
#    define CHAOS_PP_PRIMITIVE_USTRINGIZE_ID() CHAOS_PP_PRIMITIVE_USTRINGIZE
#
#    if CHAOS_PP_VARIADICS
#        define CHAOS_PP_PRIMITIVE_USTRINGIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_PRIMITIVE_USTRINGIZE)
#        define CHAOS_IP_PRIMITIVE_USTRINGIZE_8(...) CHAOS_PP_PRIMITIVE_CAT(u8, #__VA_ARGS__)
#        define CHAOS_IP_PRIMITIVE_USTRINGIZE_16(...) CHAOS_PP_PRIMITIVE_CAT(u, #__VA_ARGS__)
#        define CHAOS_IP_PRIMITIVE_USTRINGIZE_32(...) CHAOS_PP_PRIMITIVE_CAT(U, #__VA_ARGS__)
#    else
#        define CHAOS_IP_PRIMITIVE_USTRINGIZE_8(x) CHAOS_PP_PRIMITIVE_CAT(u8, #x)
#        define CHAOS_IP_PRIMITIVE_USTRINGIZE_16(x) CHAOS_PP_PRIMITIVE_CAT(u, #x)
#        define CHAOS_IP_PRIMITIVE_USTRINGIZE_32(x) CHAOS_PP_PRIMITIVE_CAT(U, #x)
#    endif
#
# endif
#
# endif
