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
# ifndef CHAOS_PREPROCESSOR_STRING_WCHARIZE_H
# define CHAOS_PREPROCESSOR_STRING_WCHARIZE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/string/charize.h>
#
# /* CHAOS_PP_WCHARIZE */
#
# define CHAOS_PP_WCHARIZE(c) CHAOS_IP_WCHARIZE_I(CHAOS_PP_CHARIZE(c))
# define CHAOS_PP_WCHARIZE_ID() CHAOS_PP_WCHARIZE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WCHARIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_WCHARIZE)
# endif
#
# define CHAOS_IP_WCHARIZE_I(c) CHAOS_PP_PRIMITIVE_CAT(L, c)
#
# endif
