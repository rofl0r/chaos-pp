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
# ifndef CHAOS_PREPROCESSOR_SEQ_REPLACE_H
# define CHAOS_PREPROCESSOR_SEQ_REPLACE_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/first_n.h>
# include <chaos/preprocessor/seq/rest_n.h>
#
# /* CHAOS_PP_SEQ_REPLACE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_REPLACE(i, seq, ...) \
        CHAOS_PP_SEQ_FIRST_N(i, seq) (__VA_ARGS__) CHAOS_PP_SEQ_REST_N(CHAOS_PP_INC(i), seq) \
        /**/
#    define CHAOS_PP_SEQ_REPLACE_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_REPLACE_ID)()
# else
#    define CHAOS_PP_SEQ_REPLACE(i, seq, x) \
        CHAOS_PP_SEQ_FIRST_N(i, seq) (x) CHAOS_PP_SEQ_REST_N(CHAOS_PP_INC(i), seq) \
        /**/
# endif
#
# define CHAOS_PP_SEQ_REPLACE_ID() CHAOS_PP_SEQ_REPLACE
#
# endif
