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
# ifndef CHAOS_PREPROCESSOR_SEQ_SIZE_H
# define CHAOS_PREPROCESSOR_SEQ_SIZE_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/seq/binary_transform.h>
# include <chaos/preprocessor/seq/detail/close.h>
#
# /* CHAOS_PP_SEQ_SIZE */
#
# define CHAOS_PP_SEQ_SIZE(seq) CHAOS_PP_EXPAND(CHAOS_IP_SEQ_SIZE_I(CHAOS_PP_SEQ_BINARY_TRANSFORM(seq, ~)))
# define CHAOS_PP_SEQ_SIZE_ID() CHAOS_PP_SEQ_SIZE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_SIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_SIZE)
# endif
#
# define CHAOS_IP_SEQ_SIZE_I(bin) CHAOS_IP_SEQ_SIZE_II bin 0 CHAOS_PP_SEQ_CLOSE(bin)
# define CHAOS_IP_SEQ_SIZE_INDIRECT() CHAOS_IP_SEQ_SIZE_II
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_SIZE_II(m, ...) m(?)(CHAOS_PP_INC CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() CHAOS_IP_SEQ_SIZE_INDIRECT)
# else
#    define CHAOS_IP_SEQ_SIZE_II(m, x) m(1)(CHAOS_PP_INC CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() CHAOS_IP_SEQ_SIZE_INDIRECT)
# endif
#
# endif
