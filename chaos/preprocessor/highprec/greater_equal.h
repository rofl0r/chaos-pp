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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_GREATER_EQUAL_H
# define CHAOS_PREPROCESSOR_HIGHPREC_GREATER_EQUAL_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_binary.h>
# include <chaos/preprocessor/highprec/less_equal.h>
# include <chaos/preprocessor/highprec/promote.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_AUTO_GREATER_EQUAL */
#
# define CHAOS_PP_AUTO_GREATER_EQUAL(x, y) \
    CHAOS_PP_GREATER_EQUAL_HP( \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(x))(x, CHAOS_PP_PROMOTE_HP(x)), \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(y))(y, CHAOS_PP_PROMOTE_HP(y)) \
    ) \
    /**/
# define CHAOS_PP_AUTO_GREATER_EQUAL_ID() CHAOS_PP_AUTO_GREATER_EQUAL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_GREATER_EQUAL_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_GREATER_EQUAL)
# endif
#
# /* CHAOS_PP_GREATER_EQUAL_HP */
#
# define CHAOS_PP_GREATER_EQUAL_HP(x, y) CHAOS_PP_LESS_EQUAL_HP(y, x)
# define CHAOS_PP_GREATER_EQUAL_HP_ID() CHAOS_PP_GREATER_EQUAL_HP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_GREATER_EQUAL_HP_ CHAOS_PP_LAMBDA(CHAOS_PP_GREATER_EQUAL_HP)
# endif
#
# define CHAOS_PP_GREATER_EQUAL_HP_INTERNAL(x, y) CHAOS_PP_LESS_EQUAL_HP_INTERNAL(y, x)
#
# endif
