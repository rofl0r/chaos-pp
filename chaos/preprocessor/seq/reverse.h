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
# ifndef CHAOS_PREPROCESSOR_SEQ_REVERSE_H
# define CHAOS_PREPROCESSOR_SEQ_REVERSE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/seq/binary_transform.h>
# include <chaos/preprocessor/seq/detail/close.h>
#
# /* CHAOS_PP_SEQ_REVERSE */
#
# define CHAOS_PP_SEQ_REVERSE(seq) CHAOS_PP_EXPAND(CHAOS_IP_SEQ_REVERSE_I(CHAOS_PP_SEQ_BINARY_TRANSFORM(seq, ~)))
# define CHAOS_PP_SEQ_REVERSE_ID() CHAOS_PP_SEQ_REVERSE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_REVERSE_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_REVERSE_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_REVERSE_I(bin) CHAOS_IP_SEQ_REVERSE_II bin CHAOS_PP_SEQ_CLOSE(bin)
#    define CHAOS_IP_SEQ_REVERSE_II(m, ...) m(?)(CHAOS_IP_SEQ_REVERSE_III CHAOS_PP_DEFER(CHAOS_PP_LPAREN)()(__VA_ARGS__), CHAOS_IP_SEQ_REVERSE_INDIRECT)
# else
#    define CHAOS_IP_SEQ_REVERSE_I(bin) CHAOS_IP_SEQ_REVERSE_II bin CHAOS_IP_SEQ_REVERSE_ID CHAOS_PP_SEQ_CLOSE(bin)
#    define CHAOS_IP_SEQ_REVERSE_II(m, x) m(2)(CHAOS_IP_SEQ_REVERSE_III CHAOS_PP_DEFER(CHAOS_PP_LPAREN)()(x), CHAOS_IP_SEQ_REVERSE_INDIRECT)
#    define CHAOS_IP_SEQ_REVERSE_ID(x) (x)
# endif
#
# define CHAOS_IP_SEQ_REVERSE_INDIRECT() CHAOS_IP_SEQ_REVERSE_II
# define CHAOS_IP_SEQ_REVERSE_III(x, res) res x
#
# endif
