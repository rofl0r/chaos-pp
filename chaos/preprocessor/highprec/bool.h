# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003-2004.                             *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_HIGHPREC_BOOL_H
# define CHAOS_PREPROCESSOR_HIGHPREC_BOOL_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_BOOL_HP */
#
# define CHAOS_PP_BOOL_HP(x) CHAOS_PP_BOOL_HP_INTERNAL(CHAOS_PP_BINARY(0) x)
# define CHAOS_PP_BOOL_HP_ID() CHAOS_PP_BOOL_HP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BOOL_HP_ CHAOS_PP_LAMBDA(CHAOS_PP_BOOL_HP)
# endif
#
# define CHAOS_PP_BOOL_HP_INTERNAL(x) CHAOS_IP_BOOL_HP_I x
# define CHAOS_IP_BOOL_HP_I(a, b, c, d, e, f, g, h, i, j) \
    CHAOS_PP_COMPL(CHAOS_PP_IS_NULLARY( \
        CHAOS_IP_BOOL_HP_ ## a ## b ## c ## d ## e ## f ## g ## h ## i ## j \
    )) \
    /**/
# define CHAOS_IP_BOOL_HP_0000000000 ()
#
# endif
