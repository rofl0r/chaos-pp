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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_BITNAND_H
# define CHAOS_PREPROCESSOR_LOGICAL_BITNAND_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_BITNAND */
#
# define CHAOS_PP_BITNAND(x) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BITNAND_, x)
# define CHAOS_PP_BITNAND_ID() CHAOS_PP_BITNAND
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BITNAND_ CHAOS_PP_LAMBDA(CHAOS_PP_BITNAND)
# endif
#
# define CHAOS_IP_BITNAND_0(y) 1
# define CHAOS_IP_BITNAND_1(y) CHAOS_PP_COMPL(y)
#
# endif
