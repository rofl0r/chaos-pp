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
# ifndef CHAOS_PREPROCESSOR_RECURSION_RAIL_H
# define CHAOS_PREPROCESSOR_RECURSION_RAIL_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
#
# /* CHAOS_PP_RAIL */
#
# define CHAOS_PP_RAIL(macro) \
    CHAOS_PP_IIF_SHADOW(CHAOS_PP_IS_NULLARY(CHAOS_PP_WALL(())))( \
        CHAOS_PP_RAIL_ID CHAOS_PP_OBSTRUCT()()(macro), \
        macro CHAOS_PP_OBSTRUCT() \
    ) \
    /**/
# define CHAOS_PP_RAIL_ID() CHAOS_PP_RAIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_RAIL_ CHAOS_PP_LAMBDA(CHAOS_PP_RAIL)
# endif
#
# /* CHAOS_PP_UNSAFE_RAIL */
#
# define CHAOS_PP_UNSAFE_RAIL(macro) \
    CHAOS_PP_IIF_SHADOW(CHAOS_PP_IS_NULLARY(CHAOS_PP_WALL(())))( \
        CHAOS_PP_UNSAFE_RAIL_ID CHAOS_PP_OBSTRUCT()()(macro), \
        macro \
    ) \
    /**/
# define CHAOS_PP_UNSAFE_RAIL_ID() CHAOS_PP_UNSAFE_RAIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_UNSAFE_RAIL_ CHAOS_PP_LAMBDA(CHAOS_PP_UNSAFE_RAIL)
# endif
#
# /* CHAOS_PP_WALL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_WALL(...) __VA_ARGS__
#    define CHAOS_PP_WALL_ CHAOS_PP_LAMBDA(CHAOS_PP_WALL_ID)()
# else
#    define CHAOS_PP_WALL(x) x
# endif
#
# define CHAOS_PP_WALL_ID() CHAOS_PP_WALL
#
# endif
