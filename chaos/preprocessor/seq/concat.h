# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_SEQ_CONCAT_H
# define CHAOS_PREPROCESSOR_SEQ_CONCAT_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/extended/variadic_cat.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/seq/binary_transform.h>
# include <chaos/preprocessor/seq/core.h>
# include <chaos/preprocessor/seq/detail/close.h>
#
# /* CHAOS_PP_SEQ_CONCAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_CONCAT(seq) CHAOS_PP_EXPAND(CHAOS_IP_SEQ_CONCAT_I(CHAOS_PP_SEQ_BINARY_TRANSFORM(seq,)))
#    define CHAOS_PP_SEQ_CONCAT_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_CONCAT_ID)()
# else
#    define CHAOS_PP_SEQ_CONCAT(seq) \
        CHAOS_PP_IIF(CHAOS_PP_SEQ_IS_CONS(CHAOS_PP_SEQ_TAIL(seq)))( \
            CHAOS_PP_EXPAND(CHAOS_IP_SEQ_CONCAT_I( \
                CHAOS_PP_SEQ_BINARY_TRANSFORM(CHAOS_PP_SEQ_TAIL(seq), ~), CHAOS_PP_SEQ_HEAD(seq) \
            )), \
            CHAOS_PP_SEQ_HEAD(seq) \
        ) \
        /**/
# endif
#
# define CHAOS_PP_SEQ_CONCAT_ID() CHAOS_PP_SEQ_CONCAT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_CONCAT_I(bin) CHAOS_IP_SEQ_CONCAT_II bin CHAOS_PP_SEQ_CLOSE(bin)
#    define CHAOS_IP_SEQ_CONCAT_INDIRECT() CHAOS_IP_SEQ_CONCAT_II
#    define CHAOS_IP_SEQ_CONCAT_II(m, ...) m(?)(CHAOS_PP_VARIADIC_CAT CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() __VA_ARGS__, CHAOS_IP_SEQ_CONCAT_INDIRECT)
# else
#    define CHAOS_IP_SEQ_CONCAT_I(bin, init) CHAOS_IP_SEQ_CONCAT_A bin init CHAOS_IP_SEQ_CONCAT_B bin
#    define CHAOS_IP_SEQ_CONCAT_A_INDIRECT() CHAOS_IP_SEQ_CONCAT_A
#    define CHAOS_IP_SEQ_CONCAT_A(m, x) m(1)(CHAOS_PP_CAT CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() CHAOS_IP_SEQ_CONCAT_A_INDIRECT)
#    define CHAOS_IP_SEQ_CONCAT_B_INDIRECT() CHAOS_IP_SEQ_CONCAT_B
#    define CHAOS_IP_SEQ_CONCAT_B(m, x) m(1)(CHAOS_PP_COMMA() x CHAOS_PP_RPAREN() CHAOS_IP_SEQ_CONCAT_B_INDIRECT)
# endif
#
# endif
