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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_DETAIL_LENGTH_H
# define CHAOS_PREPROCESSOR_HIGHPREC_DETAIL_LENGTH_H
#
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/facilities/indirect.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_LENGTH_HP */
#
# define CHAOS_PP_LENGTH_HP(x) CHAOS_PP_LENGTH_HP_INTERNAL(CHAOS_PP_BINARY(0) x)
#
# define CHAOS_PP_LENGTH_HP_INTERNAL(rep) \
    CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_LENGTH_HP_I)( \
        CHAOS_IP_LENGTH_HP_M, CHAOS_PP_TUPLE_REM(10) rep \
    )) \
    /**/
#
# define CHAOS_IP_LENGTH_HP_I(_, a, b, c, d, e, f, g, h, i, j) \
    _(1) \
    (a, 10)(_)(b, 9)(_)(c, 8)(_)(d, 7)(_)(e, 6)(_) \
    (f, 5)(_)(g, 4)(_)(h, 3)(_)(i, 2)(_)(1, 1)(CHAOS_PP_EAT) \
    /**/
# define CHAOS_IP_LENGTH_HP_M(x) CHAOS_IP_LENGTH_HP_ ## x
# define CHAOS_IP_LENGTH_HP_0(n, r) CHAOS_PP_INDIRECT(0)
# define CHAOS_IP_LENGTH_HP_1(n, r) CHAOS_PP_IF(n)(r CHAOS_PP_INDIRECT(0), CHAOS_PP_INDIRECT(1))
#
# endif
