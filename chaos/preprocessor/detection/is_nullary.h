# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2004.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_DETECTION_IS_NULLARY_H
# define CHAOS_PREPROCESSOR_DETECTION_IS_NULLARY_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_IS_NULLARY */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_NULLARY(...) CHAOS_PP_SPLIT_SHADOW(0, CHAOS_PP_CAT_SHADOW(CHAOS_IP_IS_NULLARY_R_, CHAOS_IP_IS_NULLARY_C __VA_ARGS__))
#    define CHAOS_PP_IS_NULLARY_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_NULLARY)
# else
#    define CHAOS_PP_IS_NULLARY(x) CHAOS_PP_SPLIT_SHADOW(0, CHAOS_PP_CAT_SHADOW(CHAOS_IP_IS_NULLARY_R_, CHAOS_IP_IS_NULLARY_C x))
# endif
#
# define CHAOS_PP_IS_NULLARY_ID() CHAOS_PP_IS_NULLARY
#
# define CHAOS_IP_IS_NULLARY_C() 1
# define CHAOS_IP_IS_NULLARY_R_1 1, ~
# define CHAOS_IP_IS_NULLARY_R_CHAOS_IP_IS_NULLARY_C 0, ~
#
# endif
