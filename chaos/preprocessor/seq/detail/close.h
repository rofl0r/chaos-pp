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
# ifndef CHAOS_PREPROCESSOR_SEQ_DETAIL_CLOSE_H
# define CHAOS_PREPROCESSOR_SEQ_DETAIL_CLOSE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/punctuation/paren.h>
#
# /* CHAOS_PP_SEQ_CLOSE */
#
# define CHAOS_PP_SEQ_CLOSE(bin) CHAOS_IP_SEQ_CLOSE_I bin
#
# define CHAOS_IP_SEQ_CLOSE_I_ID() CHAOS_IP_SEQ_CLOSE_I
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_CLOSE_I(m, ...) m(?)(CHAOS_PP_RPAREN() CHAOS_IP_SEQ_CLOSE_I_ID)
# else
#    define CHAOS_IP_SEQ_CLOSE_I(m, x) m(1)(CHAOS_PP_RPAREN() CHAOS_IP_SEQ_CLOSE_I_ID)
# endif
#
# endif
