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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_LESS_H
# define CHAOS_PREPROCESSOR_ARBITRARY_LESS_H
#
# include <chaos/preprocessor/arbitrary/less_equal.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_LESS_AP */
#
# define CHAOS_PP_LESS_AP(x, y) CHAOS_PP_COMPL(CHAOS_PP_LESS_EQUAL_AP(y, x))
# define CHAOS_PP_LESS_AP_ID() CHAOS_PP_LESS_AP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LESS_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_LESS_AP)
# endif
#
# /* CHAOS_PP_LESS_AP_INTERNAL */
#
# define CHAOS_PP_LESS_AP_INTERNAL(x, y) CHAOS_PP_COMPL(CHAOS_PP_LESS_EQUAL_AP_INTERNAL(y, x))
#
# endif
