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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_BOOL_H
# define CHAOS_PREPROCESSOR_ARBITRARY_BOOL_H
#
# include <chaos/preprocessor/arbitrary/detail/fix.h>
# include <chaos/preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ARBITRARY_BOOL */
#
# define CHAOS_PP_ARBITRARY_BOOL(x) \
    CHAOS_PP_ARBITRARY_BOOL_INTERNAL(CHAOS_PP_ARBITRARY_FIX_INTERNAL( \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_ARBITRARY_SIGN(x))( \
            CHAOS_PP_REM \
        ) x \
    )) \
    /**/
# define CHAOS_PP_ARBITRARY_BOOL_ID() CHAOS_PP_ARBITRARY_BOOL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARBITRARY_BOOL_ CHAOS_PP_LAMBDA(CHAOS_PP_ARBITRARY_BOOL)
# endif
#
# /* CHAOS_PP_ARBITRARY_BOOL_INTERNAL */
#
# define CHAOS_PP_ARBITRARY_BOOL_INTERNAL(x) \
    CHAOS_PP_COMPL(CHAOS_PP_IS_NULLARY(CHAOS_IP_ARBITRARY_BOOL_I x)) \
    /**/
#
# define CHAOS_IP_ARBITRARY_BOOL_I(digit) CHAOS_IP_ARBITRARY_BOOL_ ## digit
# define CHAOS_IP_ARBITRARY_BOOL_0 ()
#
# endif
