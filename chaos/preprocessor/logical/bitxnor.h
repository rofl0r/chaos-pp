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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_BITXNOR_H
# define CHAOS_PREPROCESSOR_LOGICAL_BITXNOR_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_BITXNOR */
#
# define CHAOS_PP_BITXNOR(x) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BITXNOR_, x)
# define CHAOS_PP_BITXNOR_ID() CHAOS_PP_BITXOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BITXNOR_ CHAOS_PP_LAMBDA(CHAOS_PP_BITXNOR)
# endif
#
# define CHAOS_IP_BITXNOR_0(y) CHAOS_PP_COMPL(y)
# define CHAOS_IP_BITXNOR_1(y) y
#
# endif
