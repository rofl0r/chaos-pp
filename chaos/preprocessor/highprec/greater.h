# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2004.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_GREATER_H
# define CHAOS_PREPROCESSOR_HIGHPREC_GREATER_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_binary.h>
# include <chaos/preprocessor/highprec/less_equal.h>
# include <chaos/preprocessor/highprec/promote.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_AUTO_GREATER */
#
# define CHAOS_PP_AUTO_GREATER(x, y) \
    CHAOS_PP_GREATER_HP( \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(x))(x, CHAOS_PP_PROMOTE_HP(x)), \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(y))(y, CHAOS_PP_PROMOTE_HP(y)) \
    ) \
    /**/
# define CHAOS_PP_AUTO_GREATER_ID() CHAOS_PP_AUTO_GREATER
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_GREATER_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_GREATER)
# endif
#
# /* CHAOS_PP_GREATER_HP */
#
# define CHAOS_PP_GREATER_HP(x, y) CHAOS_PP_COMPL(CHAOS_PP_LESS_EQUAL_HP(x, y))
# define CHAOS_PP_GREATER_HP_ID() CHAOS_PP_GREATER_HP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_GREATER_HP_ CHAOS_PP_LAMBDA(CHAOS_PP_GREATER_HP)
# endif
#
# define CHAOS_PP_GREATER_HP_INTERNAL(x, y) CHAOS_PP_COMPL(CHAOS_PP_LESS_EQUAL_HP_INTERNAL(x, y))
#
# endif
