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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_NOT_H
# define CHAOS_PREPROCESSOR_LOGICAL_NOT_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_NOT */
#
# define CHAOS_PP_NOT(x) CHAOS_PP_IS_NULLARY(CHAOS_PP_PRIMITIVE_CAT_SHADOW(CHAOS_IP_NOT_, x))
# define CHAOS_PP_NOT_ID() CHAOS_PP_NOT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NOT_ CHAOS_PP_LAMBDA(CHAOS_PP_NOT)
# endif
#
# define CHAOS_IP_NOT_0 ()
#
# endif
