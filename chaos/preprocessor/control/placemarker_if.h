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
# ifndef CHAOS_PREPROCESSOR_CONTROL_PLACEMARKER_IF_H
# define CHAOS_PREPROCESSOR_CONTROL_PLACEMARKER_IF_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_PLACEMARKER_IF */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PLACEMARKER_IF(p) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_PLACEMARKER_IF_, p)
#    define CHAOS_PP_PLACEMARKER_IF_ID() CHAOS_PP_PLACEMARKER_IF
#    define CHAOS_PP_PLACEMARKER_IF_ CHAOS_PP_LAMBDA(CHAOS_PP_PLACEMARKER_IF)
# endif
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_PLACEMARKER_IF_(...) __VA_ARGS__
#    define CHAOS_IP_PLACEMARKER_IF_0(...)
# endif
#
# endif
