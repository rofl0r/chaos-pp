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
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_MOD_H
# define CHAOS_PREPROCESSOR_HIGHPREC_MOD_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_binary.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/highprec/demote.h>
# include <chaos/preprocessor/highprec/detail/fix.h>
# include <chaos/preprocessor/highprec/div.h>
# include <chaos/preprocessor/highprec/promote.h>
# include <chaos/preprocessor/highprec/sign.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
#
# /* CHAOS_PP_AUTO_MOD */
#
# define CHAOS_PP_AUTO_MOD(x, y) CHAOS_PP_AUTO_MOD_BYPASS(CHAOS_PP_LIMIT_EXPR, x, y)
# define CHAOS_PP_AUTO_MOD_ID() CHAOS_PP_AUTO_MOD
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AUTO_MOD_ CHAOS_PP_LAMBDA(CHAOS_PP_AUTO_MOD)
# endif
#
# /* CHAOS_PP_AUTO_MOD_BYPASS */
#
# define CHAOS_PP_AUTO_MOD_BYPASS(s, x, y) \
    CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(x))( \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(y))( \
            CHAOS_PP_MOD_HP_BYPASS(s, x, y), \
            CHAOS_PP_MOD_HP_BYPASS(s, x, CHAOS_PP_PROMOTE_HP(y)) \
        ), \
        CHAOS_PP_IIF(CHAOS_PP_IS_BINARY(y))( \
            CHAOS_PP_MOD_HP_BYPASS(s, CHAOS_PP_PROMOTE_HP(x), y), \
            CHAOS_PP_DEMOTE_HP(CHAOS_PP_MOD_HP_BYPASS(s, CHAOS_PP_PROMOTE_HP(x), CHAOS_PP_PROMOTE_HP(y))) \
        ) \
    ) \
    /**/
# define CHAOS_PP_AUTO_MOD_BYPASS_ID() CHAOS_PP_AUTO_MOD_BYPASS
#
# /* CHAOS_PP_MOD_HP */
#
# define CHAOS_PP_MOD_HP(x, y) CHAOS_PP_MOD_HP_BYPASS(CHAOS_PP_LIMIT_EXPR, x, y)
# define CHAOS_PP_MOD_HP_ID() CHAOS_PP_MOD_HP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MOD_HP_ CHAOS_PP_LAMBDA(CHAOS_PP_MOD_HP)
# endif
#
# /* CHAOS_PP_MOD_HP_BYPASS */
#
# define CHAOS_PP_MOD_HP_BYPASS(s, x, y) \
    CHAOS_PP_FIX_HP(( \
        CHAOS_PP_BINARY_CTOR(0, CHAOS_PP_DIV_HP_INTERNAL(s, CHAOS_PP_BINARY(0) x, CHAOS_PP_BINARY(0) y)), \
        CHAOS_PP_SIGN_HP(x) \
    )) \
    /**/
# define CHAOS_PP_MOD_HP_BYPASS_ID() CHAOS_PP_MOD_HP_BYPASS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MOD_HP_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_MOD_HP_BYPASS)
# endif
#
# endif
