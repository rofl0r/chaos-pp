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
# ifndef CHAOS_PREPROCESSOR_SEQ_TO_STRING_H
# define CHAOS_PREPROCESSOR_SEQ_TO_STRING_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/binary_transform.h>
#
# /* CHAOS_PP_SEQ_TO_STRING */
#
# define CHAOS_PP_SEQ_TO_STRING(seq) \
    CHAOS_PP_EXPAND(CHAOS_IP_SEQ_TO_STRING_I CHAOS_PP_SEQ_BINARY_TRANSFORM(seq, ~)) \
    /**/
# define CHAOS_PP_SEQ_TO_STRING_ID() CHAOS_PP_SEQ_TO_STRING
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_TO_STRING_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_TO_STRING_ID)()
# endif
#
# define CHAOS_IP_SEQ_TO_STRING_INDIRECT() CHAOS_IP_SEQ_TO_STRING_I
# define CHAOS_IP_SEQ_TO_STRING_I(m, x) m(1)(x CHAOS_IP_SEQ_TO_STRING_INDIRECT)
#
# endif
