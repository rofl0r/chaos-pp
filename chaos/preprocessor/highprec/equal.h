# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003-2004.                             *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_EQUAL_H
# define CHAOS_PREPROCESSOR_HIGHPREC_EQUAL_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_binary.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/highprec/promote.h>
# include <chaos/preprocessor/highprec/sign.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bitxor.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_AUTO_EQUAL */
#
# define CHAOS_PP_AUTO_EQUAL(x, y) \
    CHAOS_PP_EQUAL_HP( \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(x))(x, CHAOS_PP_PROMOTE_HP(x)), \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(y))(y, CHAOS_PP_PROMOTE_HP(y)) \
    ) \
    /**/
# define CHAOS_PP_AUTO_EQUAL_ID() CHAOS_PP_AUTO_EQUAL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_EQUAL_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_EQUAL)
# endif
#
# /* CHAOS_PP_EQUAL_HP */
#
# define CHAOS_PP_EQUAL_HP(x, y) \
    CHAOS_PP_IIF(CHAOS_PP_BITXOR(CHAOS_PP_SIGN_HP(x))(CHAOS_PP_SIGN_HP(y)))( \
        0, CHAOS_PP_EQUAL_HP_INTERNAL(CHAOS_PP_BINARY(0) x, CHAOS_PP_BINARY(0) y) \
    ) \
    /**/
# define CHAOS_PP_EQUAL_HP_ID() CHAOS_PP_EQUAL_HP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EQUAL_HP_ CHAOS_PP_LAMBDA(CHAOS_PP_EQUAL_HP)
# endif
#
# define CHAOS_PP_EQUAL_HP_INTERNAL(x, y) \
    CHAOS_PP_EXPAND(CHAOS_PP_DEFER(CHAOS_IP_EQUAL_HP_I)( \
        CHAOS_IP_EQUAL_HP_M, CHAOS_PP_TUPLE_REM(10) x, CHAOS_PP_TUPLE_REM(10) y \
    )) \
    /**/
# define CHAOS_IP_EQUAL_HP_I(_, x9, x8, x7, x6, x5, x4, x3, x2, x1, x0, y9, y8, y7, y6, y5, y4, y3, y2, y1, y0) \
    CHAOS_PP_IS_NULLARY( \
        _(x9, y9) _(x8, y8) _(x7, y7) _(x6, y6) _(x5, y5) \
        _(x4, y4) _(x3, y3) _(x2, y2) _(x1, y1) _(x0, y0) \
        () \
    ) \
    /**/
# define CHAOS_IP_EQUAL_HP_M(a, b) CHAOS_IP_EQUAL_HP_ ## a ## b
#
# define CHAOS_IP_EQUAL_HP_00
# define CHAOS_IP_EQUAL_HP_11
# define CHAOS_IP_EQUAL_HP_22
# define CHAOS_IP_EQUAL_HP_33
# define CHAOS_IP_EQUAL_HP_44
# define CHAOS_IP_EQUAL_HP_55
# define CHAOS_IP_EQUAL_HP_66
# define CHAOS_IP_EQUAL_HP_77
# define CHAOS_IP_EQUAL_HP_88
# define CHAOS_IP_EQUAL_HP_99
#
# endif
