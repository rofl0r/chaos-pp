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
# ifndef CHAOS_PREPROCESSOR_SEQ_TO_LIST_H
# define CHAOS_PREPROCESSOR_SEQ_TO_LIST_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/seq/binary_transform.h>
# include <chaos/preprocessor/seq/detail/close.h>
#
# /* CHAOS_PP_SEQ_TO_LIST */
#
# define CHAOS_PP_SEQ_TO_LIST(seq) CHAOS_IP_SEQ_TO_LIST_I(CHAOS_PP_SEQ_BINARY_TRANSFORM(seq, ~))
# define CHAOS_PP_SEQ_TO_LIST_ID() CHAOS_PP_SEQ_TO_LIST
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_TO_LIST_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_TO_LIST_ID)()
# endif
#
# define CHAOS_IP_SEQ_TO_LIST_I(bin) CHAOS_IP_SEQ_TO_LIST_II bin ... CHAOS_PP_SEQ_CLOSE(bin)
# define CHAOS_IP_SEQ_TO_LIST_INDIRECT() CHAOS_IP_SEQ_TO_LIST_II
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_TO_LIST_II(m, ...) m(?)(CHAOS_PP_LPAREN() __VA_ARGS__, CHAOS_IP_SEQ_TO_LIST_INDIRECT)
# else
#    define CHAOS_IP_SEQ_TO_LIST_II(m, x) m(1)(CHAOS_PP_LPAREN() x CHAOS_PP_COMMA() CHAOS_IP_SEQ_TO_LIST_INDIRECT)
# endif
#
# endif
