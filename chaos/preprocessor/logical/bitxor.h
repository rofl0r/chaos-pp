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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_BITXOR_H
# define CHAOS_PREPROCESSOR_LOGICAL_BITXOR_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_BITXOR */
#
# define CHAOS_PP_BITXOR(x) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BITXOR_, x)
# define CHAOS_PP_BITXOR_ID() CHAOS_PP_BITXOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BITXOR_ CHAOS_PP_LAMBDA(CHAOS_PP_BITXOR)
# endif
#
# define CHAOS_IP_BITXOR_0(y) y
# define CHAOS_IP_BITXOR_1(y) CHAOS_PP_COMPL(y)
#
# endif
