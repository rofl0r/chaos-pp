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
# ifndef CHAOS_PREPROCESSOR_SEQ_TO_TUPLE_H
# define CHAOS_PREPROCESSOR_SEQ_TO_TUPLE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/enumerate.h>
#
# /* CHAOS_PP_SEQ_TO_TUPLE */
#
# define CHAOS_PP_SEQ_TO_TUPLE(seq) (CHAOS_PP_SEQ_ENUMERATE(seq))
# define CHAOS_PP_SEQ_TO_TUPLE_ID() CHAOS_PP_SEQ_TO_TUPLE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_TO_TUPLE_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_TO_TUPLE_ID)()
# endif
#
# endif
