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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_DEMOTE_H
# define CHAOS_PREPROCESSOR_HIGHPREC_DEMOTE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/highprec/detail/length.h>
# include <chaos/preprocessor/highprec/sign.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_DEMOTE_HP */
#
# define CHAOS_PP_DEMOTE_HP(x) \
    CHAOS_PP_INLINE_WHEN(CHAOS_PP_SIGN_HP(x))(-) CHAOS_IP_DEMOTE_HP_I(CHAOS_PP_BINARY(0) x) \
    /**/
# define CHAOS_PP_DEMOTE_HP_ID() CHAOS_PP_DEMOTE_HP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DEMOTE_HP_ CHAOS_PP_LAMBDA(CHAOS_PP_DEMOTE_HP)
# endif
#
# define CHAOS_IP_DEMOTE_HP_I(rep) CHAOS_PP_CAT(CHAOS_IP_DEMOTE_HP_, CHAOS_PP_LENGTH_HP_INTERNAL(rep)) rep
#
# define CHAOS_IP_DEMOTE_HP_1(a, b, c, d, e, f, g, h, i, j) j
# define CHAOS_IP_DEMOTE_HP_2(a, b, c, d, e, f, g, h, i, j) i ## j
# define CHAOS_IP_DEMOTE_HP_3(a, b, c, d, e, f, g, h, i, j) h ## i ## j
# define CHAOS_IP_DEMOTE_HP_4(a, b, c, d, e, f, g, h, i, j) g ## h ## i ## j
# define CHAOS_IP_DEMOTE_HP_5(a, b, c, d, e, f, g, h, i, j) f ## g ## h ## i ## j
# define CHAOS_IP_DEMOTE_HP_6(a, b, c, d, e, f, g, h, i, j) e ## f ## g ## h ## i ## j
# define CHAOS_IP_DEMOTE_HP_7(a, b, c, d, e, f, g, h, i, j) d ## e ## f ## g ## h ## i ## j
# define CHAOS_IP_DEMOTE_HP_8(a, b, c, d, e, f, g, h, i, j) c ## d ## e ## f ## g ## h ## i ## j
# define CHAOS_IP_DEMOTE_HP_9(a, b, c, d, e, f, g, h, i, j) b ## c ## d ## e ## f ## g ## h ## i ## j
# define CHAOS_IP_DEMOTE_HP_10(a, b, c, d, e, f, g, h, i, j) a ## b ## c ## d ## e ## f ## g ## h ## i ## j
#
# endif
