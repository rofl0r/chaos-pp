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
# ifndef CHAOS_PREPROCESSOR_DETECTION_IS_NUMERIC_H
# define CHAOS_PREPROCESSOR_DETECTION_IS_NUMERIC_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_empty.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/facilities/intercept.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_IS_NUMERIC */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_NUMERIC(x) \
        CHAOS_PP_IIF(CHAOS_PP_IS_VARIADIC(x))( \
            0, \
            CHAOS_PP_IS_EMPTY(CHAOS_PP_CAT(CHAOS_PP_INTERCEPT, x)) \
        ) \
        /**/
#    define CHAOS_PP_IS_NUMERIC_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_NUMERIC)
# else
#    define CHAOS_PP_IS_NUMERIC(x) CHAOS_PP_IS_EMPTY(CHAOS_PP_CAT(CHAOS_PP_INTERCEPT, x))
# endif
#
# define CHAOS_PP_IS_NUMERIC_ID() CHAOS_PP_IS_NUMERIC
#
# endif
