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
# ifndef CHAOS_PREPROCESSOR_ITERATION_LOCAL_H
# define CHAOS_PREPROCESSOR_ITERATION_LOCAL_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_LOCAL_ITERATE */
#
# define CHAOS_PP_LOCAL_ITERATE() "chaos/preprocessor/iteration/detail/local.h"
# define CHAOS_PP_LOCAL_ITERATE_ID() CHAOS_PP_LOCAL_ITERATE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_LOCAL_ITERATE_ CHAOS_PP_LAMBDA(CHAOS_PP_LOCAL_ITERATE)
# endif
#
# define CHAOS_IP_LOCAL_ITERATE_F(x, y) \
    (CHAOS_PP_BINARY_CTOR(0, CHAOS_PP_LOCAL_LIMITS)) <= x && x <= (CHAOS_PP_BINARY_CTOR(1, CHAOS_PP_LOCAL_LIMITS)) \
    /**/
# define CHAOS_IP_LOCAL_ITERATE_R(x, y) \
    (CHAOS_PP_BINARY_CTOR(0, CHAOS_PP_LOCAL_LIMITS)) >= y && y >= (CHAOS_PP_BINARY_CTOR(1, CHAOS_PP_LOCAL_LIMITS)) \
    /**/
#
# endif
