# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2004.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_SEQ_RANGE_H
# define CHAOS_PREPROCESSOR_SEQ_RANGE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/first_n.h>
# include <chaos/preprocessor/seq/rest_n.h>
#
# /* CHAOS_PP_SEQ_RANGE */
#
# define CHAOS_PP_SEQ_RANGE(i, len, seq) \
    CHAOS_PP_SEQ_FIRST_N(len, CHAOS_PP_SEQ_REST_N(i, seq)) \
    /**/
# define CHAOS_PP_SEQ_RANGE_ID() CHAOS_PP_SEQ_RANGE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_RANGE_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_RANGE_ID)()
# endif
#
# endif
