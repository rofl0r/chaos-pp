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
# ifndef CHAOS_PREPROCESSOR_SEQ_ELEM_H
# define CHAOS_PREPROCESSOR_SEQ_ELEM_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/core.h>
# include <chaos/preprocessor/seq/drop.h>
#
# /* CHAOS_PP_SEQ_ELEM */
#
# define CHAOS_PP_SEQ_ELEM(i, seq) CHAOS_PP_SEQ_HEAD(CHAOS_PP_SEQ_DROP(i, seq))
# define CHAOS_PP_SEQ_ELEM_ID() CHAOS_PP_SEQ_ELEM
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_ELEM_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_ELEM_ID)()
# endif
#
# endif
