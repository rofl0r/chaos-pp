# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003-2004.                             *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_ARRAY_TO_TUPLE_H
# define CHAOS_PREPROCESSOR_ARRAY_TO_TUPLE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/split.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_ARRAY_TO_TUPLE */
#
# define CHAOS_PP_ARRAY_TO_TUPLE(array) CHAOS_PP_SPLIT(1, CHAOS_PP_TUPLE_REM(2) array)
# define CHAOS_PP_ARRAY_TO_TUPLE_ID() CHAOS_PP_ARRAY_TO_TUPLE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_TO_TUPLE_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_TO_TUPLE_ID)()
# endif
#
# endif
