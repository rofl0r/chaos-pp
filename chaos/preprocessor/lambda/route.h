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
# ifndef CHAOS_PREPROCESSOR_LAMBDA_ROUTE_H
# define CHAOS_PREPROCESSOR_LAMBDA_ROUTE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/call.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
#
# /* CHAOS_PP_WAYPOINT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WAYPOINT(...) __VA_ARGS__
#    define CHAOS_PP_WAYPOINT_ID() CHAOS_PP_WAYPOINT
#    define CHAOS_PP_WAYPOINT_ CHAOS_PP_LAMBDA(CHAOS_PP_WAYPOINT_ID)()
# endif
#
# /* CHAOS_PP_ROUTE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ROUTE(x) CHAOS_PP_CAT(CHAOS_IP_ROUTE_, CHAOS_PP_IS_VARIADIC(x))
#    define CHAOS_PP_ROUTE_ID() CHAOS_PP_ROUTE
#    define CHAOS_PP_ROUTE_ CHAOS_PP_LAMBDA(CHAOS_PP_ROUTE)
#    define CHAOS_IP_ROUTE_INDIRECT(mode) CHAOS_IP_ROUTE_ ## mode
#    define CHAOS_IP_ROUTE_0() CHAOS_IP_ROUTE_I(0)
#    define CHAOS_IP_ROUTE_1() CHAOS_IP_ROUTE_I(1)
#    define CHAOS_IP_ROUTE_I(mode) \
        CHAOS_PP_IIF_SHADOW(CHAOS_PP_IS_NULLARY(CHAOS_PP_WAYPOINT(())))( \
            CHAOS_IP_ROUTE_A, CHAOS_IP_ROUTE_B \
        )(mode) \
        /**/
#    define CHAOS_IP_ROUTE_A(mode) CHAOS_PP_DEFER(CHAOS_IP_ROUTE_INDIRECT)(mode)()
#    define CHAOS_IP_ROUTE_B(mode) CHAOS_IP_CALL_ ## mode ## mode
# endif
#
# endif
