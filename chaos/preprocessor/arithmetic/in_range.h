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
# ifndef CHAOS_PREPROCESSOR_ARITHMETIC_IN_RANGE_H
# define CHAOS_PREPROCESSOR_ARITHMETIC_IN_RANGE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/comparison/less.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_IN_RANGE */
#
# define CHAOS_PP_IN_RANGE(x) \
    CHAOS_PP_IS_NULLARY( \
        CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_LESS_, x)((), ()) \
    ) \
    /**/
# define CHAOS_PP_IN_RANGE_ID() CHAOS_PP_IN_RANGE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IN_RANGE_ CHAOS_PP_LAMBDA(CHAOS_PP_IN_RANGE)
# endif
#
# endif
