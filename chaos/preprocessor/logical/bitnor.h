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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_BITNOR_H
# define CHAOS_PREPROCESSOR_LOGICAL_BITNOR_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_BITNOR */
#
# define CHAOS_PP_BITNOR(x) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BITNOR_, x)
# define CHAOS_PP_BITNOR_ID() CHAOS_PP_BITNOR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BITNOR_ CHAOS_PP_LAMBDA(CHAOS_PP_BITNOR)
# endif
#
# define CHAOS_IP_BITNOR_0(y) CHAOS_PP_COMPL(y)
# define CHAOS_IP_BITNOR_1(y) 0
#
# endif
