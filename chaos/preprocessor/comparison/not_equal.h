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
# ifndef CHAOS_PREPROCESSOR_COMPARISON_NOT_EQUAL_H
# define CHAOS_PREPROCESSOR_COMPARISON_NOT_EQUAL_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/comparison/less.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_NOT_EQUAL */
#
# define CHAOS_PP_NOT_EQUAL(x, y) \
    CHAOS_PP_IS_NULLARY( \
        CHAOS_PP_EXPAND(CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_LESS_, x)( \
            CHAOS_PP_TUPLE_EAT(1), \
            CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_LESS_, y) CHAOS_PP_TUPLE_EAT(2) \
        ))(CHAOS_PP_TUPLE_EAT(1), ()) \
    ) \
    /**/
# define CHAOS_PP_NOT_EQUAL_ID() CHAOS_PP_NOT_EQUAL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NOT_EQUAL_ CHAOS_PP_LAMBDA(CHAOS_PP_NOT_EQUAL)
# endif
#
# endif
