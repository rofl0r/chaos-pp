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
# ifndef CHAOS_PREPROCESSOR_SLOT_SLOT_H
# define CHAOS_PREPROCESSOR_SLOT_SLOT_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/extended/variadic_cat.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/stringize.h>
#
# /* CHAOS_PP_ASSIGN_SLOT */
#
# define CHAOS_PP_ASSIGN_SLOT(i) CHAOS_IP_ASSIGN_SLOT_I(i)
# define CHAOS_PP_ASSIGN_SLOT_ID() CHAOS_PP_ASSIGN_SLOT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ASSIGN_SLOT_ CHAOS_PP_LAMBDA(CHAOS_PP_ASSIGN_SLOT)
# endif
#
# define CHAOS_IP_ASSIGN_SLOT_I(i) CHAOS_PP_PRIMITIVE_STRINGIZE(chaos/preprocessor/slot/detail/s ## i.h)
#
# /* CHAOS_PP_SLOT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SLOT(i) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_SLOT_, i)()
#    define CHAOS_PP_SLOT_ CHAOS_PP_LAMBDA(CHAOS_PP_SLOT)
# else
#    define CHAOS_PP_SLOT(i) CHAOS_PP_EXPAND(CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_SLOT_, i)())
# endif
#
# define CHAOS_PP_SLOT_ID() CHAOS_PP_SLOT
#
# define CHAOS_IP_SLOT_1 0 CHAOS_PP_EMPTY
# define CHAOS_IP_SLOT_2 0 CHAOS_PP_EMPTY
# define CHAOS_IP_SLOT_3 0 CHAOS_PP_EMPTY
# define CHAOS_IP_SLOT_4 0 CHAOS_PP_EMPTY
# define CHAOS_IP_SLOT_5 0 CHAOS_PP_EMPTY
#
# define CHAOS_IP_SLOT_MOD_0 CHAOS_IP_SLOT_MOD_1 % 10UL
# define CHAOS_IP_SLOT_MOD_1 CHAOS_IP_SLOT_MOD_2 % 100UL
# define CHAOS_IP_SLOT_MOD_2 CHAOS_IP_SLOT_MOD_3 % 1000UL
# define CHAOS_IP_SLOT_MOD_3 CHAOS_IP_SLOT_MOD_4 % 10000UL
# define CHAOS_IP_SLOT_MOD_4 CHAOS_IP_SLOT_MOD_5 % 100000UL
# define CHAOS_IP_SLOT_MOD_5 CHAOS_IP_SLOT_MOD_6 % 1000000UL
# define CHAOS_IP_SLOT_MOD_6 CHAOS_IP_SLOT_MOD_7 % 10000000UL
# define CHAOS_IP_SLOT_MOD_7 CHAOS_IP_SLOT_MOD_8 % 100000000UL
# define CHAOS_IP_SLOT_MOD_8 CHAOS_IP_SLOT_MOD_9 % 1000000000UL
# define CHAOS_IP_SLOT_MOD_9 % 1000000000UL
#
# define CHAOS_IP_SLOT_DIV_0 1UL
# define CHAOS_IP_SLOT_DIV_1 10UL
# define CHAOS_IP_SLOT_DIV_2 100UL
# define CHAOS_IP_SLOT_DIV_3 1000UL
# define CHAOS_IP_SLOT_DIV_4 10000UL
# define CHAOS_IP_SLOT_DIV_5 100000UL
# define CHAOS_IP_SLOT_DIV_6 1000000UL
# define CHAOS_IP_SLOT_DIV_7 10000000UL
# define CHAOS_IP_SLOT_DIV_8 100000000UL
# define CHAOS_IP_SLOT_DIV_9 1000000000UL
#
# define CHAOS_IP_SLOT_DIGIT(n) CHAOS_IP_SLOT_MOD_ ## n / CHAOS_IP_SLOT_DIV_ ## n
#
# define CHAOS_PP_SLOT_SHARED() "chaos/preprocessor/slot/detail/shared.h"
#
# if !CHAOS_PP_VARIADICS
#    define CHAOS_IP_SLOT_CC(n) CHAOS_PP_DEFER(CHAOS_IP_SLOT_CC_ ## n)
#    define CHAOS_IP_SLOT_CC_2(a, b) a ## b
#    define CHAOS_IP_SLOT_CC_3(a, b, c) a ## b ## c
#    define CHAOS_IP_SLOT_CC_4(a, b, c, d) a ## b ## c ## d
#    define CHAOS_IP_SLOT_CC_5(a, b, c, d, e) a ## b ## c ## d ## e
#    define CHAOS_IP_SLOT_CC_6(a, b, c, d, e, f) a ## b ## c ## d ## e ## f
#    define CHAOS_IP_SLOT_CC_7(a, b, c, d, e, f, g) a ## b ## c ## d ## e ## f ## g
#    define CHAOS_IP_SLOT_CC_8(a, b, c, d, e, f, g, h) a ## b ## c ## d ## e ## f ## g ## h
#    define CHAOS_IP_SLOT_CC_9(a, b, c, d, e, f, g, h, i) a ## b ## c ## d ## e ## f ## g ## h ## i
#    define CHAOS_IP_SLOT_CC_10(a, b, c, d, e, f, g, h, i, j) a ## b ## c ## d ## e ## f ## g ## h ## i ## j
# endif
#
# endif
