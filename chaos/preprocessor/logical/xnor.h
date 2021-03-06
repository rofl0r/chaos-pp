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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_XNOR_H
# define CHAOS_PREPROCESSOR_LOGICAL_XNOR_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bool.h>
# include <chaos/preprocessor/logical/not.h>
#
# /* CHAOS_PP_XNOR */
#
# define CHAOS_PP_XNOR(p) CHAOS_PP_CAT(CHAOS_IP_XNOR_, CHAOS_PP_BOOL(p))
# define CHAOS_PP_XNOR_ID() CHAOS_PP_XNOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_XNOR_ CHAOS_PP_LAMBDA(CHAOS_PP_XNOR)
# endif
#
# define CHAOS_IP_XNOR_0(q) CHAOS_PP_NOT(q)
# define CHAOS_IP_XNOR_1(q) CHAOS_PP_BOOL(q)
#
# endif
