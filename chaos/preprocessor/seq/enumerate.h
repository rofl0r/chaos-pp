# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_SEQ_ENUMERATE_H
# define CHAOS_PREPROCESSOR_SEQ_ENUMERATE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/seq/binary_transform.h>
#
# /* CHAOS_PP_SEQ_ENUMERATE */
#
# define CHAOS_PP_SEQ_ENUMERATE(seq) \
    CHAOS_PP_EXPAND(CHAOS_IP_SEQ_ENUMERATE_A CHAOS_PP_SEQ_BINARY_TRANSFORM(seq, ~)) \
    /**/
# define CHAOS_PP_SEQ_ENUMERATE_ID() CHAOS_PP_SEQ_ENUMERATE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_ENUMERATE_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_ENUMERATE_ID)()
# endif
#
# define CHAOS_IP_SEQ_ENUMERATE_B_ID() CHAOS_IP_SEQ_ENUMERATE_B
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_ENUMERATE_A(m, ...) m(?)(__VA_ARGS__ CHAOS_IP_SEQ_ENUMERATE_B_ID)
#    define CHAOS_IP_SEQ_ENUMERATE_B(m, ...) m(?)(, __VA_ARGS__ CHAOS_IP_SEQ_ENUMERATE_B_ID)
# else
#    define CHAOS_IP_SEQ_ENUMERATE_A(m, x) m(1)(x CHAOS_IP_SEQ_ENUMERATE_B_ID)
#    define CHAOS_IP_SEQ_ENUMERATE_B(m, x) m(1)(CHAOS_PP_COMMA() x CHAOS_IP_SEQ_ENUMERATE_B_ID)
# endif
#
# endif
