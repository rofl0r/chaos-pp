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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_NOT_EQUAL_H
# define CHAOS_PREPROCESSOR_HIGHPREC_NOT_EQUAL_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_binary.h>
# include <chaos/preprocessor/highprec/equal.h>
# include <chaos/preprocessor/highprec/promote.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_AUTO_NOT_EQUAL */
#
# define CHAOS_PP_AUTO_NOT_EQUAL(x, y) \
    CHAOS_PP_NOT_EQUAL_HP( \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(x))(x, CHAOS_PP_PROMOTE_HP(x)), \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(y))(y, CHAOS_PP_PROMOTE_HP(y)) \
    ) \
    /**/
# define CHAOS_PP_AUTO_NOT_EQUAL_ID() CHAOS_PP_AUTO_NOT_EQUAL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_NOT_EQUAL_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_NOT_EQUAL)
# endif
#
# /* CHAOS_PP_NOT_EQUAL_HP */
#
# define CHAOS_PP_NOT_EQUAL_HP(x, y) CHAOS_PP_COMPL(CHAOS_PP_EQUAL_HP(x, y))
# define CHAOS_PP_NOT_EQUAL_HP_ID() CHAOS_PP_NOT_EQUAL_HP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NOT_EQUAL_HP_ CHAOS_PP_LAMBDA(CHAOS_PP_NOT_EQUAL_HP)
# endif
#
# define CHAOS_PP_NOT_EQUAL_HP_INTERNAL(x, y) CHAOS_PP_COMPL(CHAOS_PP_EQUAL_HP_INTERNAL(x, y))
#
# endif
