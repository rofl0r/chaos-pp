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
# ifndef CHAOS_PREPROCESSOR_SEQ_POP_BACK_H
# define CHAOS_PREPROCESSOR_SEQ_POP_BACK_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/binary_transform.h>
#
# /* CHAOS_PP_SEQ_POP_BACK */
#
# define CHAOS_PP_SEQ_POP_BACK(seq) \
    CHAOS_PP_EXPAND( \
        CHAOS_IP_SEQ_POP_BACK_C CHAOS_PP_EXPAND( \
            CHAOS_IP_SEQ_POP_BACK_A CHAOS_PP_SEQ_BINARY_TRANSFORM(seq, ~) \
        ) \
    ) \
    /**/
# define CHAOS_PP_SEQ_POP_BACK_ID() CHAOS_PP_SEQ_POP_BACK
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_POP_BACK_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_POP_BACK_ID)()
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_POP_BACK_A(m, ...) ((__VA_ARGS__) CHAOS_IP_SEQ_POP_BACK_INDIRECT_1ST
#    define CHAOS_IP_SEQ_POP_BACK_B(m, ...) \
        , m) m(?)(() CHAOS_PP_LPAREN() (__VA_ARGS__) CHAOS_IP_SEQ_POP_BACK_INDIRECT_1ST) \
        /**/
# else
#    define CHAOS_IP_SEQ_POP_BACK_A(m, x) ((x) CHAOS_IP_SEQ_POP_BACK_INDIRECT_1ST
#    define CHAOS_IP_SEQ_POP_BACK_B(m, x) \
        , m) m(1)(() CHAOS_PP_LPAREN() (x) CHAOS_IP_SEQ_POP_BACK_INDIRECT_1ST) \
        /**/
# endif
#
# define CHAOS_IP_SEQ_POP_BACK_C(e, m) m(1)(e CHAOS_IP_SEQ_POP_BACK_INDIRECT_2ND)
#
# define CHAOS_IP_SEQ_POP_BACK_INDIRECT_1ST() CHAOS_IP_SEQ_POP_BACK_B
# define CHAOS_IP_SEQ_POP_BACK_INDIRECT_2ND() CHAOS_IP_SEQ_POP_BACK_C
#
# endif
