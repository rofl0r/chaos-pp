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
# ifndef CHAOS_PREPROCESSOR_ARRAY_TO_SEQ_H
# define CHAOS_PREPROCESSOR_ARRAY_TO_SEQ_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/to_seq.h>
#
# /* CHAOS_PP_ARRAY_TO_SEQ */
#
# define CHAOS_PP_ARRAY_TO_SEQ(array) CHAOS_PP_TUPLE_TO_SEQ array
# define CHAOS_PP_ARRAY_TO_SEQ_ID() CHAOS_PP_ARRAY_TO_SEQ
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_TO_SEQ_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_TO_SEQ_ID)()
# endif
#
# endif
