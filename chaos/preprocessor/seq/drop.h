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
# ifndef CHAOS_PREPROCESSOR_SEQ_DROP_H
# define CHAOS_PREPROCESSOR_SEQ_DROP_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/take.h>
#
# /* CHAOS_PP_SEQ_DROP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_DROP(n, seq) \
        CHAOS_PP_SPLIT(1, CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_SEQ_TAKE_, n) seq) \
        /**/
#    define CHAOS_PP_SEQ_DROP_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_DROP_ID)()
# else
#    define CHAOS_PP_SEQ_DROP(n, seq) \
        CHAOS_PP_SPLIT(1, ~ CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_SEQ_TAKE_, n) seq CHAOS_PP_EMPTY)() \
        /**/
# endif
#
# define CHAOS_PP_SEQ_DROP_ID() CHAOS_PP_SEQ_DROP
#
# endif
