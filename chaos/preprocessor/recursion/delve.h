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
# ifndef CHAOS_PREPROCESSOR_RECURSION_DELVE_H
# define CHAOS_PREPROCESSOR_RECURSION_DELVE_H
#
# include <chaos/preprocessor/arithmetic/inc.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
#
# /* CHAOS_PP_DELVE */
#
# define CHAOS_PP_DELVE() CHAOS_IP_DELVE_I(0)
# define CHAOS_PP_DELVE_ID() CHAOS_PP_DELVE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DELVE_ CHAOS_PP_LAMBDA(CHAOS_PP_DELVE)
# endif
#
# define CHAOS_IP_DELVE_INDIRECT() CHAOS_IP_DELVE_I
# define CHAOS_IP_DELVE_I(n) \
    CHAOS_PP_IIF_SHADOW(CHAOS_PP_IS_NULLARY(CHAOS_PP_HALT(())))( \
        CHAOS_IP_DELVE_INDIRECT CHAOS_PP_OBSTRUCT()()(CHAOS_PP_INC(n)), \
        n \
    ) \
    /**/
#
# /* CHAOS_PP_HALT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_HALT(...) __VA_ARGS__
#    define CHAOS_PP_HALT_ CHAOS_PP_LAMBDA(CHAOS_PP_HALT_ID)()
# else
#    define CHAOS_PP_HALT(x) x
# endif
#
# define CHAOS_PP_HALT_ID() CHAOS_PP_HALT
#
# endif
