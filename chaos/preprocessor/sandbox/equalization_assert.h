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
# ifndef CHAOS_PREPROCESSOR_SANDBOX_EQUALIZATION_ASSERT_H
# define CHAOS_PREPROCESSOR_SANDBOX_EQUALIZATION_ASSERT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/debug/failure.h>
# include <chaos/preprocessor/recursion/equalize.h>
# include <chaos/preprocessor/recursion/delay.h>
# include <chaos/preprocessor/recursion/delve.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_IS_EQUALIZED */
#
# define CHAOS_PP_IS_EQUALIZED(n) CHAOS_PP_DELAY(n, CHAOS_PP_FAILURE)()
# define CHAOS_PP_IS_EQUALIZED_ID() CHAOS_PP_IS_EQUALIZED
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_EQUALIZED_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_EQUALIZED)
# endif
#
# /* CHAOS_PP_EQUALIZATION_ASSERT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EQUALIZATION_ASSERT(...) CHAOS_PP_TUPLE_EAT(?)(__VA_ARGS__)
#    define CHAOS_PP_EQUALIZATION_ASSERT_ CHAOS_PP_LAMBDA(CHAOS_PP_EQUALIZATION_ASSERT)
# else
#    define CHAOS_PP_EQUALIZATION_ASSERT(x) CHAOS_PP_TUPLE_EAT(1)(x)
# endif
#
# define CHAOS_PP_EQUALIZATION_ASSERT_ID() CHAOS_PP_EQUALIZATION_ASSERT
#
# endif
