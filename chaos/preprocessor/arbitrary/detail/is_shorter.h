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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_IS_SHORTER_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_IS_SHORTER_H
#
# include <chaos/preprocessor/arbitrary/detail/scan.h>
# include <chaos/preprocessor/arbitrary/detail/special.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_ARBITRARY_IS_SHORTER */
#
# define CHAOS_PP_ARBITRARY_IS_SHORTER(x, y) \
    CHAOS_PP_IS_UNARY(CHAOS_PP_SCAN(1)( \
        CHAOS_IP_ARBITRARY_IS_SHORTER_A x(00) y ~ CHAOS_PP_SPECIAL_CLOSE(x) \
    )) \
    /**/
#
# define CHAOS_IP_ARBITRARY_IS_SHORTER_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_IS_SHORTER_I CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() CHAOS_IP_ARBITRARY_IS_SHORTER_B)
# define CHAOS_IP_ARBITRARY_IS_SHORTER_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_IP_ARBITRARY_IS_SHORTER_I CHAOS_PP_DEFER(CHAOS_PP_LPAREN)() CHAOS_IP_ARBITRARY_IS_SHORTER_A)
# define CHAOS_IP_ARBITRARY_IS_SHORTER_I(y) CHAOS_PP_EAT y
#
# endif
