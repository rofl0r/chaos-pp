# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003-2004.                             *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_SEQ_REST_N_H
# define CHAOS_PREPROCESSOR_SEQ_REST_N_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/first_n.h>
#
# /* CHAOS_PP_SEQ_REST_N */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_REST_N(n, seq) \
        CHAOS_PP_SPLIT(1, CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_SEQ_FIRST_N_, n) seq) \
        /**/
#    define CHAOS_PP_SEQ_REST_N_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_REST_N_ID)()
# else
#    define CHAOS_PP_SEQ_REST_N(n, seq) \
        CHAOS_PP_SPLIT(1, ~ CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_SEQ_FIRST_N_, n) seq CHAOS_PP_EMPTY)() \
        /**/
# endif
#
# define CHAOS_PP_SEQ_REST_N_ID() CHAOS_PP_SEQ_REST_N
#
# endif
