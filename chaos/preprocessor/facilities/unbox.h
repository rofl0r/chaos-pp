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
# ifndef CHAOS_PREPROCESSOR_FACILITIES_UNBOX_H
# define CHAOS_PREPROCESSOR_FACILITIES_UNBOX_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_UNBOX */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_UNBOX(...) \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_VARIADIC(__VA_ARGS__))( \
            CHAOS_PP_REM __VA_ARGS__ \
        ) \
        /**/
#    define CHAOS_PP_UNBOX_ CHAOS_PP_LAMBDA(CHAOS_PP_UNBOX_ID)()
# else
#    define CHAOS_PP_UNBOX(x) \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_UNARY(x))( \
            CHAOS_PP_REM x \
        ) \
        /**/
# endif
#
# define CHAOS_PP_UNBOX_ID() CHAOS_PP_UNBOX
#
# endif
