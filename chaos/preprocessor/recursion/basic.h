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
# ifndef CHAOS_PREPROCESSOR_RECURSION_BASIC_H
# define CHAOS_PREPROCESSOR_RECURSION_BASIC_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_DEFER */
#
# define CHAOS_PP_DEFER(macro) macro CHAOS_PP_EMPTY()
# define CHAOS_PP_DEFER_ID() CHAOS_PP_DEFER
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DEFER_ CHAOS_PP_LAMBDA(CHAOS_PP_DEFER)
# endif
#
# /* CHAOS_PP_REFER */
#
# define CHAOS_PP_REFER(macro) macro
# define CHAOS_PP_REFER_ID() CHAOS_PP_REFER
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REFER_ CHAOS_PP_LAMBDA(CHAOS_PP_REFER)
# endif
#
# /* CHAOS_PP_OBSTRUCT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_OBSTRUCT(macro) macro CHAOS_PP_EMPTY CHAOS_PP_EMPTY()()
#    define CHAOS_PP_OBSTRUCT_ CHAOS_PP_LAMBDA(CHAOS_PP_OBSTRUCT)
# else
#    define CHAOS_PP_OBSTRUCT() CHAOS_PP_EMPTY CHAOS_PP_EMPTY()()
# endif
#
# define CHAOS_PP_OBSTRUCT_ID() CHAOS_PP_OBSTRUCT
#
# endif
