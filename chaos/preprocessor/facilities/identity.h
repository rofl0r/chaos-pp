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
# ifndef CHAOS_PREPROCESSOR_FACILITIES_IDENTITY_H
# define CHAOS_PREPROCESSOR_FACILITIES_IDENTITY_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_IDENTITY */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IDENTITY(...) __VA_ARGS__ CHAOS_PP_EMPTY
#    define CHAOS_PP_IDENTITY_ CHAOS_PP_LAMBDA(CHAOS_PP_IDENTITY_ID)()
# else
#    define CHAOS_PP_IDENTITY(x) x CHAOS_PP_EMPTY
# endif
#
# define CHAOS_PP_IDENTITY_ID() CHAOS_PP_IDENTITY
#
# endif
