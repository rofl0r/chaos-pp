# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2004.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_TUPLE_RANGE_H
# define CHAOS_PREPROCESSOR_TUPLE_RANGE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/limits.h>
# include <chaos/preprocessor/tuple/drop.h>
# include <chaos/preprocessor/tuple/take.h>
#
# /* CHAOS_PP_TUPLE_RANGE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_RANGE(i, len, tuple) CHAOS_PP_TUPLE_RANGE_BYPASS(CHAOS_PP_LIMIT_EXPR, i, len, tuple)
#    define CHAOS_PP_TUPLE_RANGE_ID() CHAOS_PP_TUPLE_RANGE
#    define CHAOS_PP_TUPLE_RANGE_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_RANGE_ID)()
# endif
#
# /* CHAOS_PP_TUPLE_RANGE_BYPASS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_RANGE_BYPASS(s, i, len, tuple) \
        CHAOS_PP_TUPLE_TAKE_BYPASS(s, len, CHAOS_PP_TUPLE_DROP_BYPASS(s, i, tuple)) \
        /**/
#    define CHAOS_PP_TUPLE_RANGE_BYPASS_ID() CHAOS_PP_TUPLE_RANGE_BYPASS
#    define CHAOS_PP_TUPLE_RANGE_BYPASS_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_RANGE_BYPASS_ID)()
# endif
#
# endif
