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
# ifndef CHAOS_PREPROCESSOR_TUPLE_AS_ARGS_H
# define CHAOS_PREPROCESSOR_TUPLE_AS_ARGS_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/inline_when.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/core.h>
#
# /* CHAOS_PP_TUPLE_AS_ARGS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TUPLE_AS_ARGS(tuple) \
        CHAOS_PP_INLINE_WHEN(CHAOS_PP_TUPLE_IS_NIL(tuple))(()) tuple \
        /**/
#    define CHAOS_PP_TUPLE_AS_ARGS_ID() CHAOS_PP_TUPLE_AS_ARGS
#    define CHAOS_PP_TUPLE_AS_ARGS_ CHAOS_PP_LAMBDA(CHAOS_PP_TUPLE_AS_ARGS_ID)()
# endif
#
# endif
