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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_SIGN_H
# define CHAOS_PREPROCESSOR_ARBITRARY_SIGN_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ARBITRARY_SIGN */
#
# define CHAOS_PP_ARBITRARY_SIGN(x) CHAOS_PP_IS_UNARY(CHAOS_PP_REM x)
# define CHAOS_PP_ARBITRARY_SIGN_ID() CHAOS_PP_ARBITRARY_SIGN
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_SIGN_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_SIGN)
# endif
#
# endif
