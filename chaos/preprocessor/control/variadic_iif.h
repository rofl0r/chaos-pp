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
# ifndef CHAOS_PREPROCESSOR_CONTROL_VARIADIC_IIF_H
# define CHAOS_PREPROCESSOR_CONTROL_VARIADIC_IIF_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_VARIADIC_IIF */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_IIF(bit) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_VARIADIC_IIF_, bit)
#    define CHAOS_PP_VARIADIC_IIF_ID() CHAOS_PP_VARIADIC_IIF
#    define CHAOS_PP_VARIADIC_IIF_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_IIF)
#    define CHAOS_IP_VARIADIC_IIF_0(...) CHAOS_PP_REM
#    define CHAOS_IP_VARIADIC_IIF_1(...) __VA_ARGS__ CHAOS_PP_EAT
# endif
#
# endif
