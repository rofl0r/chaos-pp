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
# ifndef CHAOS_PREPROCESSOR_SEQ_TO_ARRAY_H
# define CHAOS_PREPROCESSOR_SEQ_TO_ARRAY_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/size.h>
# include <chaos/preprocessor/seq/to_tuple.h>
#
# /* CHAOS_PP_SEQ_TO_ARRAY */
#
# define CHAOS_PP_SEQ_TO_ARRAY(seq) (CHAOS_PP_SEQ_SIZE(seq), CHAOS_PP_SEQ_TO_TUPLE(seq))
# define CHAOS_PP_SEQ_TO_ARRAY_ID() CHAOS_PP_SEQ_TO_ARRAY
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_TO_ARRAY_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_TO_ARRAY_ID)()
# endif
#
# endif
