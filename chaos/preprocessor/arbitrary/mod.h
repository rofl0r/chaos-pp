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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_MOD_H
# define CHAOS_PREPROCESSOR_ARBITRARY_MOD_H
#
# include <chaos/preprocessor/arbitrary/detail/clean.h>
# include <chaos/preprocessor/arbitrary/div.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/recursion/machine.h>
#
# /* CHAOS_PP_MOD_AP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MOD_AP(x, y) CHAOS_PP_MOD_AP_S(CHAOS_PP_STATE(), x, y)
#    define CHAOS_PP_MOD_AP_ID() CHAOS_PP_MOD_AP
#    define CHAOS_PP_MOD_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_MOD_AP)
# endif
#
# /* CHAOS_PP_MOD_AP_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MOD_AP_S(s, x, y) CHAOS_IP_MOD_AP_I(s, CHAOS_PP_SUPER_CLEAN_AP(x), CHAOS_PP_SUPER_CLEAN_AP(y))
#    define CHAOS_PP_MOD_AP_S_ID() CHAOS_PP_MOD_AP_S
#    define CHAOS_PP_MOD_AP_S_ CHAOS_PP_LAMBDA(CHAOS_PP_MOD_AP_S)
#    define CHAOS_IP_MOD_AP_I(s, x, y) \
        CHAOS_PP_CLEAN_AP((CHAOS_PP_BINARY(0) x, CHAOS_PP_MOD_AP_INTERNAL(s, CHAOS_PP_BINARY(1) x, CHAOS_PP_BINARY(1) y))) \
        /**/
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_MOD_AP_INTERNAL(s, x, y) CHAOS_PP_BINARY_CTOR(1, CHAOS_PP_EXPR_S(s)(CHAOS_PP_MACHINE_S(s, (, 0xCHAOS(0xARBITRARY(0xDIV)), x, y, 0xCHAOS(0xSTOP),))))
# endif
#
# endif
