# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2003.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_FACILITIES_AS_ARGS_H
# define CHAOS_PREPROCESSOR_FACILITIES_AS_ARGS_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/rem.h>
#
# /* CHAOS_PP_AS_ARGS */
#
# define CHAOS_PP_AS_ARGS(n) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_AS_ARGS_, n)
# define CHAOS_PP_AS_ARGS_ID() CHAOS_PP_AS_ARGS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_AS_ARGS_ CHAOS_PP_LAMBDA(CHAOS_PP_AS_ARGS)
# endif
#
# define CHAOS_IP_AS_ARGS_2(s, array) (CHAOS_PP_NEXT(s), CHAOS_PP_TUPLE_REM_CTOR array)
# define CHAOS_IP_AS_ARGS_3(s, a, array) (CHAOS_PP_NEXT(s), a, CHAOS_PP_TUPLE_REM_CTOR array)
# define CHAOS_IP_AS_ARGS_4(s, a, b, array) (CHAOS_PP_NEXT(s), a, b, CHAOS_PP_TUPLE_REM_CTOR array)
# define CHAOS_IP_AS_ARGS_5(s, a, b, c, array) (CHAOS_PP_NEXT(s), a, b, c, CHAOS_PP_TUPLE_REM_CTOR array)
#
# endif
