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
# ifndef CHAOS_PREPROCESSOR_FACILITIES_TYPE_H
# define CHAOS_PREPROCESSOR_FACILITIES_TYPE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/rail.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_TYPE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TYPE(...) CHAOS_PP_RAIL(CHAOS_PP_TUPLE_REM)(?)(__VA_ARGS__)
#    define CHAOS_PP_TYPE_ID() CHAOS_PP_TYPE
#    define CHAOS_PP_TYPE_ CHAOS_PP_LAMBDA(CHAOS_PP_TYPE_ID)()
# endif
#
# /* CHAOS_PP_TYPE_II */
#
# define CHAOS_PP_TYPE_II CHAOS_PP_UNSAFE_RAIL(CHAOS_PP_EMPTY CHAOS_PP_EMPTY)()
# define CHAOS_PP_TYPE_II_ID() CHAOS_PP_TYPE_II
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TYPE_II_ CHAOS_PP_LAMBDA(CHAOS_PP_TYPE_II_ID)()
# endif
#
# /* CHAOS_PP_BEGIN */
#
# define CHAOS_PP_BEGIN CHAOS_PP_UNSAFE_RAIL(CHAOS_PP_RPAREN)()
# define CHAOS_PP_BEGIN_ID() CHAOS_PP_BEGIN
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BEGIN_ CHAOS_PP_LAMBDA(CHAOS_PP_BEGIN_ID)()
# endif
#
# /* CHAOS_PP_END */
#
# define CHAOS_PP_END CHAOS_PP_UNSAFE_RAIL(CHAOS_PP_EMPTY CHAOS_PP_LPAREN)()
# define CHAOS_PP_END_ID() CHAOS_PP_END
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_END_ CHAOS_PP_LAMBDA(CHAOS_PP_END_ID)()
# endif
#
# endif
