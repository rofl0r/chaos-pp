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
# ifndef CHAOS_PREPROCESSOR_SEQ_REMOVE_H
# define CHAOS_PREPROCESSOR_SEQ_REMOVE_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/drop.h>
# include <chaos/preprocessor/seq/take.h>
#
# /* CHAOS_PP_SEQ_REMOVE */
#
# define CHAOS_PP_SEQ_REMOVE(i, seq) \
    CHAOS_PP_SEQ_TAKE(i, seq) CHAOS_PP_SEQ_DROP(CHAOS_PP_INC(i), seq) \
    /**/
# define CHAOS_PP_SEQ_REMOVE_ID() CHAOS_PP_SEQ_REMOVE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_REMOVE_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_REMOVE_ID)()
# endif
#
# endif
