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
# ifndef CHAOS_PREPROCESSOR_SEQ_REMOVE_H
# define CHAOS_PREPROCESSOR_SEQ_REMOVE_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/first_n.h>
# include <chaos/preprocessor/seq/rest_n.h>
#
# /* CHAOS_PP_SEQ_REMOVE */
#
# define CHAOS_PP_SEQ_REMOVE(i, seq) \
    CHAOS_PP_SEQ_FIRST_N(i, seq) CHAOS_PP_SEQ_REST_N(CHAOS_PP_INC(i), seq) \
    /**/
# define CHAOS_PP_SEQ_REMOVE_ID() CHAOS_PP_SEQ_REMOVE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_REMOVE_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_REMOVE_ID)()
# endif
#
# endif
