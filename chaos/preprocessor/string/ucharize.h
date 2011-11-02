# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2011.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_STRING_UCHARIZE_H
# define CHAOS_PREPROCESSOR_STRING_UCHARIZE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/string/charize.h>
#
# /* CHAOS_PP_UCHARIZE */
#
# ifdef __cplusplus
#
#    define CHAOS_PP_UCHARIZE(n) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_UCHARIZE_, n)
#    define CHAOS_PP_UCHARIZE_ID() CHAOS_PP_UCHARIZE
#
#    if CHAOS_PP_VARIADICS
#        define CHAOS_PP_UCHARIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_UCHARIZE)
#    endif
#
#    define CHAOS_IP_UCHARIZE_8(c) CHAOS_IP_UCHARIZE_8_I(CHAOS_PP_CHARIZE(c))
#    define CHAOS_IP_UCHARIZE_16(c) CHAOS_IP_UCHARIZE_16_I(CHAOS_PP_CHARIZE(c))
#    define CHAOS_IP_UCHARIZE_32(c) CHAOS_IP_UCHARIZE_32_I(CHAOS_PP_CHARIZE(c))
#
#    define CHAOS_IP_UCHARIZE_8_I(c) CHAOS_PP_PRIMITIVE_CAT(u8, c)
#    define CHAOS_IP_UCHARIZE_16_I(c) CHAOS_PP_PRIMITIVE_CAT(u, c)
#    define CHAOS_IP_UCHARIZE_32_I(c) CHAOS_PP_PRIMITIVE_CAT(U, c)
#
# endif
#
# endif
