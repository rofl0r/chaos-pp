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
# ifndef CHAOS_PREPROCESSOR_CONTROL_INLINE_UNLESS_H
# define CHAOS_PREPROCESSOR_CONTROL_INLINE_UNLESS_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_INLINE_UNLESS */
#
# define CHAOS_PP_INLINE_UNLESS(bit) CHAOS_PP_INLINE_WHEN(CHAOS_PP_COMPL(bit))
# define CHAOS_PP_INLINE_UNLESS_ID() CHAOS_PP_INLINE_UNLESS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INLINE_UNLESS_ CHAOS_PP_LAMBDA(CHAOS_PP_INLINE_UNLESS)
# endif
#
# endif
