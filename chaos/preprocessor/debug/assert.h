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
# ifndef CHAOS_PREPROCESSOR_DEBUG_ASSERT_H
# define CHAOS_PREPROCESSOR_DEBUG_ASSERT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/debug/failure.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/not.h>
#
# /* CHAOS_PP_ASSERT */
#
# define CHAOS_PP_ASSERT(cond) CHAOS_PP_EXPR_IIF(CHAOS_PP_NOT(cond))(CHAOS_PP_FAILURE())
# define CHAOS_PP_ASSERT_ID() CHAOS_PP_ASSERT
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ASSERT_ CHAOS_PP_LAMBDA(CHAOS_PP_ASSERT)
# endif
#
# /* CHAOS_PP_ASSERT_MSG */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ASSERT_MSG(cond, ...) CHAOS_PP_EXPR_IIF(CHAOS_PP_NOT(cond))(__VA_ARGS__)
#    define CHAOS_PP_ASSERT_MSG_ CHAOS_PP_LAMBDA(CHAOS_PP_ASSERT_MSG)
# else
#    define CHAOS_PP_ASSERT_MSG(cond, msg) CHAOS_PP_EXPR_IIF(CHAOS_PP_NOT(cond))(msg)
# endif
#
# define CHAOS_PP_ASSERT_MSG_ID() CHAOS_PP_ASSERT_MSG
#
# endif
