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
# ifndef CHAOS_PREPROCESSOR_CONTROL_EXPR_IF_H
# define CHAOS_PREPROCESSOR_CONTROL_EXPR_IF_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bool.h>
#
# /* CHAOS_PP_EXPR_IF */
#
# define CHAOS_PP_EXPR_IF(cond) CHAOS_PP_EXPR_IIF(CHAOS_PP_BOOL(cond))
# define CHAOS_PP_EXPR_IF_ID() CHAOS_PP_EXPR_IF
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EXPR_IF_ CHAOS_PP_LAMBDA(CHAOS_PP_EXPR_IF)
# endif
#
# endif
