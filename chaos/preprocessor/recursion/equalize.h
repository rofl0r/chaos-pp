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
# ifndef CHAOS_PREPROCESSOR_RECURSION_EQUALIZE_H
# define CHAOS_PREPROCESSOR_RECURSION_EQUALIZE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_EQUALIZE */
#
# define CHAOS_PP_EQUALIZE(n) CHAOS_PP_PRIMITIVE_CAT_SHADOW(CHAOS_IP_EQUALIZE_, n)
# define CHAOS_PP_EQUALIZE_ID() CHAOS_PP_EQUALIZE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EQUALIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_EQUALIZE)
# endif
#
# define CHAOS_IP_EQUALIZE_1(x) x
# define CHAOS_IP_EQUALIZE_2(x) CHAOS_IP_EQUALIZE_1(x)
# define CHAOS_IP_EQUALIZE_3(x) CHAOS_IP_EQUALIZE_2(x)
# define CHAOS_IP_EQUALIZE_4(x) CHAOS_IP_EQUALIZE_3(x)
# define CHAOS_IP_EQUALIZE_5(x) CHAOS_IP_EQUALIZE_4(x)
# define CHAOS_IP_EQUALIZE_6(x) CHAOS_IP_EQUALIZE_5(x)
# define CHAOS_IP_EQUALIZE_7(x) CHAOS_IP_EQUALIZE_6(x)
# define CHAOS_IP_EQUALIZE_8(x) CHAOS_IP_EQUALIZE_7(x)
# define CHAOS_IP_EQUALIZE_9(x) CHAOS_IP_EQUALIZE_8(x)
# define CHAOS_IP_EQUALIZE_10(x) CHAOS_IP_EQUALIZE_9(x)
# define CHAOS_IP_EQUALIZE_11(x) CHAOS_IP_EQUALIZE_10(x)
# define CHAOS_IP_EQUALIZE_12(x) CHAOS_IP_EQUALIZE_11(x)
# define CHAOS_IP_EQUALIZE_13(x) CHAOS_IP_EQUALIZE_12(x)
# define CHAOS_IP_EQUALIZE_14(x) CHAOS_IP_EQUALIZE_13(x)
# define CHAOS_IP_EQUALIZE_15(x) CHAOS_IP_EQUALIZE_14(x)
# define CHAOS_IP_EQUALIZE_16(x) CHAOS_IP_EQUALIZE_15(x)
# define CHAOS_IP_EQUALIZE_17(x) CHAOS_IP_EQUALIZE_16(x)
# define CHAOS_IP_EQUALIZE_18(x) CHAOS_IP_EQUALIZE_17(x)
# define CHAOS_IP_EQUALIZE_19(x) CHAOS_IP_EQUALIZE_18(x)
# define CHAOS_IP_EQUALIZE_20(x) CHAOS_IP_EQUALIZE_19(x)
# define CHAOS_IP_EQUALIZE_21(x) CHAOS_IP_EQUALIZE_20(x)
# define CHAOS_IP_EQUALIZE_22(x) CHAOS_IP_EQUALIZE_21(x)
# define CHAOS_IP_EQUALIZE_23(x) CHAOS_IP_EQUALIZE_22(x)
# define CHAOS_IP_EQUALIZE_24(x) CHAOS_IP_EQUALIZE_23(x)
# define CHAOS_IP_EQUALIZE_25(x) CHAOS_IP_EQUALIZE_24(x)
#
# endif
