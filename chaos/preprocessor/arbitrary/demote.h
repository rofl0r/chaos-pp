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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DEMOTE_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DEMOTE_H
#
# include <chaos/preprocessor/arbitrary/detail/fix.h>
# include <chaos/preprocessor/arbitrary/detail/scan.h>
# include <chaos/preprocessor/arbitrary/detail/special.h>
# include <chaos/preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/comma.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/seq/core.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ARBITRARY_DEMOTE */
#
# define CHAOS_PP_ARBITRARY_DEMOTE(x) CHAOS_IP_ARBITRARY_DEMOTE_I(CHAOS_PP_ARBITRARY_FIX(x))
# define CHAOS_PP_ARBITRARY_DEMOTE_ID() CHAOS_PP_ARBITRARY_DEMOTE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_DEMOTE_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_DEMOTE)
# endif
#
# define CHAOS_IP_ARBITRARY_DEMOTE_I(x) \
    CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_SIGN(x))( \
        -CHAOS_PP_ARBITRARY_DEMOTE_INTERNAL(CHAOS_PP_REM x), \
        CHAOS_PP_ARBITRARY_DEMOTE_INTERNAL(x) \
    ) \
    /**/
#
# /* CHAOS_PP_ARBITRARY_DEMOTE_INTERNAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_DEMOTE_INTERNAL(x) \
        CHAOS_PP_SCAN(1)(CHAOS_IP_ARBITRARY_DEMOTE_A x(00) CHAOS_IP_ARBITRARY_DEMOTE_X x(00)) \
        /**/
# else
#    define CHAOS_PP_ARBITRARY_DEMOTE_INTERNAL(x) \
        CHAOS_PP_SCAN(1)(CHAOS_PP_SCAN(1)( \
            CHAOS_IP_ARBITRARY_DEMOTE_A CHAOS_PP_EAT x(00) CHAOS_PP_SEQ_FIRST(x) CHAOS_IP_ARBITRARY_DEMOTE_X CHAOS_PP_EAT x(00) \
        )) \
        /**/
# endif
#
# define CHAOS_IP_ARBITRARY_DEMOTE_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_PP_CAT CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() CHAOS_IP_ARBITRARY_DEMOTE_B)
# define CHAOS_IP_ARBITRARY_DEMOTE_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_PP_CAT CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() CHAOS_IP_ARBITRARY_DEMOTE_A)
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_ARBITRARY_DEMOTE_X(digit) CHAOS_PP_SPECIAL(digit)(, digit CHAOS_PP_RPAREN() CHAOS_IP_ARBITRARY_DEMOTE_Y)
#    define CHAOS_IP_ARBITRARY_DEMOTE_Y(digit) CHAOS_PP_SPECIAL(digit)(, digit CHAOS_PP_RPAREN() CHAOS_IP_ARBITRARY_DEMOTE_X)
# else
#    define CHAOS_IP_ARBITRARY_DEMOTE_X(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_PP_COMMA() digit CHAOS_PP_RPAREN() CHAOS_IP_ARBITRARY_DEMOTE_Y)
#    define CHAOS_IP_ARBITRARY_DEMOTE_Y(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_PP_COMMA() digit CHAOS_PP_RPAREN() CHAOS_IP_ARBITRARY_DEMOTE_X)
# endif
#
# endif
