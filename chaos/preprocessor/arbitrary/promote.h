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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_PROMOTE_H
# define CHAOS_PREPROCESSOR_ARBITRARY_PROMOTE_H
#
# include <chaos/preprocessor/arbitrary/detail/clean.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/highprec/promote.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_PROMOTE_AP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PROMOTE_AP(x) CHAOS_PP_EXPAND(CHAOS_IP_PROMOTE_AP_I CHAOS_PP_PROMOTE_HP(x))
#    define CHAOS_PP_PROMOTE_AP_ID() CHAOS_PP_PROMOTE_AP
#    define CHAOS_PP_PROMOTE_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_PROMOTE_AP)
#    define CHAOS_IP_PROMOTE_AP_I(r, sign) (sign, CHAOS_IP_PROMOTE_AP_II r)
#    define CHAOS_IP_PROMOTE_AP_II(a, b, c, d, e, f, g, h, i, j) CHAOS_PP_CLEAN_AP_INTERNAL((a)(b)(c)(d)(e)(f)(g)(h)(i)(j))
# endif
#
# endif
