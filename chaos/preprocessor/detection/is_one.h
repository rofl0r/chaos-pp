# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_DETECTION_IS_ONE_H
# define CHAOS_PREPROCESSOR_DETECTION_IS_ONE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_IS_ONE */
#
# define CHAOS_PP_IS_ONE(id) \
    CHAOS_PP_IS_NULLARY(CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_IS_ONE_, id CHAOS_PP_EMPTY())) \
    /**/
# define CHAOS_PP_IS_ONE_ID() CHAOS_PP_IS_ONE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_ONE_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_ONE)
# endif
#
# define CHAOS_IP_IS_ONE_1 ()
#
# endif
