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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_FIX_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_FIX_H
#
# include <chaos/preprocessor/arbitrary/bool.h>
# include <chaos/preprocessor/arbitrary/sign.h>
# include <chaos/preprocessor/control/if.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/control/inline_unless.h>
# include <chaos/preprocessor/detection/is_unary.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ARBITRARY_FIX */
#
# define CHAOS_PP_ARBITRARY_FIX(x) \
    CHAOS_PP_IIF(CHAOS_PP_ARBITRARY_SIGN(x))( \
        CHAOS_IP_ARBITRARY_FIX_I(CHAOS_PP_ARBITRARY_FIX_INTERNAL(CHAOS_PP_REM x)), \
        CHAOS_PP_ARBITRARY_FIX_INTERNAL(x) \
    ) \
    /**/
#
# define CHAOS_IP_ARBITRARY_FIX_I(x) \
    CHAOS_PP_INLINE_UNLESS(CHAOS_PP_ARBITRARY_BOOL_INTERNAL(x))( \
        CHAOS_PP_REM \
    )(x) \
    /**/
#
# /* CHAOS_PP_ARBITRARY_FIX_INTERNAL */
#
# define CHAOS_PP_ARBITRARY_FIX_INTERNAL(x) CHAOS_IP_ARBITRARY_FIX_II(CHAOS_IP_ARBITRARY_FIX_A x)
#
# define CHAOS_IP_ARBITRARY_FIX_II(c) CHAOS_PP_IIF(CHAOS_PP_IS_UNARY(c))(c, (0))
# define CHAOS_IP_ARBITRARY_FIX_A(digit) CHAOS_PP_IF(digit)((digit), CHAOS_IP_ARBITRARY_FIX_B)
# define CHAOS_IP_ARBITRARY_FIX_B(digit) CHAOS_PP_IF(digit)((digit), CHAOS_IP_ARBITRARY_FIX_A)
#
# endif
