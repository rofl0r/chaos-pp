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
# ifndef CHAOS_PREPROCESSOR_FACILITIES_ENCODE_H
# define CHAOS_PREPROCESSOR_FACILITIES_ENCODE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ENCODE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ENCODE(...) (__VA_ARGS__)
#    define CHAOS_PP_ENCODE_ID() CHAOS_PP_ENCODE
#    define CHAOS_PP_ENCODE_ CHAOS_PP_LAMBDA(CHAOS_PP_ENCODE_ID)()
# endif
#
# /* CHAOS_PP_DECODE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DECODE(...) \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_IS_VARIADIC(__VA_ARGS__))( \
            CHAOS_PP_TUPLE_REM(?) \
        ) __VA_ARGS__ \
        /**/
#    define CHAOS_PP_DECODE_ID() CHAOS_PP_DECODE
#    define CHAOS_PP_DECODE_ CHAOS_PP_LAMBDA(CHAOS_PP_DECODE_ID)()
# endif
#
# endif
