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
# ifndef CHAOS_PREPROCESSOR_SEQ_BINARY_TRANSFORM_H
# define CHAOS_PREPROCESSOR_SEQ_BINARY_TRANSFORM_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/eat.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_SEQ_BINARY_TRANSFORM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_BINARY_TRANSFORM(seq, ...) CHAOS_PP_CAT(CHAOS_IP_SEQ_BINARY_TRANSFORM_A seq, 0)(CHAOS_PP_TUPLE_EAT, __VA_ARGS__)
#    define CHAOS_PP_SEQ_BINARY_TRANSFORM_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_BINARY_TRANSFORM_ID)()
# else
#    define CHAOS_PP_SEQ_BINARY_TRANSFORM(seq, def) CHAOS_PP_CAT(CHAOS_IP_SEQ_BINARY_TRANSFORM_A seq, 0)(CHAOS_PP_TUPLE_EAT, def)
# endif
#
# define CHAOS_PP_SEQ_BINARY_TRANSFORM_ID() CHAOS_PP_SEQ_BINARY_TRANSFORM
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_BINARY_TRANSFORM_A(...) (CHAOS_PP_TUPLE_REM, __VA_ARGS__)() CHAOS_IP_SEQ_BINARY_TRANSFORM_B
#    define CHAOS_IP_SEQ_BINARY_TRANSFORM_B(...) (CHAOS_PP_TUPLE_REM, __VA_ARGS__)() CHAOS_IP_SEQ_BINARY_TRANSFORM_A
# else
#    define CHAOS_IP_SEQ_BINARY_TRANSFORM_A(x) (CHAOS_PP_TUPLE_REM, x)() CHAOS_IP_SEQ_BINARY_TRANSFORM_B
#    define CHAOS_IP_SEQ_BINARY_TRANSFORM_B(x) (CHAOS_PP_TUPLE_REM, x)() CHAOS_IP_SEQ_BINARY_TRANSFORM_A
# endif
#
# define CHAOS_IP_SEQ_BINARY_TRANSFORM_A0
# define CHAOS_IP_SEQ_BINARY_TRANSFORM_B0
#
# /* CHAOS_PP_SEQ_BINARY_TRANSFORM_2ND */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_BINARY_TRANSFORM_2ND(seq, ...) CHAOS_PP_CAT(CHAOS_IP_SEQ_BINARY_TRANSFORM_2ND_A seq, 0)(0, __VA_ARGS__)
#    define CHAOS_PP_SEQ_BINARY_TRANSFORM_2ND_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_BINARY_TRANSFORM_2ND_ID)()
# else
#    define CHAOS_PP_SEQ_BINARY_TRANSFORM_2ND(seq, def) CHAOS_PP_CAT(CHAOS_IP_SEQ_BINARY_TRANSFORM_2ND_A seq, 0)(0, def)
# endif
#
# define CHAOS_PP_SEQ_BINARY_TRANSFORM_2ND_ID() CHAOS_PP_SEQ_BINARY_TRANSFORM_2ND
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SEQ_BINARY_TRANSFORM_2ND_A(...) (1, __VA_ARGS__)() CHAOS_IP_SEQ_BINARY_TRANSFORM_2ND_B
#    define CHAOS_IP_SEQ_BINARY_TRANSFORM_2ND_B(...) (1, __VA_ARGS__)() CHAOS_IP_SEQ_BINARY_TRANSFORM_2ND_A
# else
#    define CHAOS_IP_SEQ_BINARY_TRANSFORM_2ND_A(x) (1, x)() CHAOS_IP_SEQ_BINARY_TRANSFORM_2ND_B
#    define CHAOS_IP_SEQ_BINARY_TRANSFORM_2ND_B(x) (1, x)() CHAOS_IP_SEQ_BINARY_TRANSFORM_2ND_A
# endif
#
# define CHAOS_IP_SEQ_BINARY_TRANSFORM_2ND_A0
# define CHAOS_IP_SEQ_BINARY_TRANSFORM_2ND_B0
#
# endif
