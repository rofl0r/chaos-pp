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
# ifndef CHAOS_PREPROCESSOR_ARRAY_TO_LIST_H
# define CHAOS_PREPROCESSOR_ARRAY_TO_LIST_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/to_list.h>
#
# /* CHAOS_PP_ARRAY_TO_LIST */
#
# define CHAOS_PP_ARRAY_TO_LIST(array) CHAOS_PP_TUPLE_TO_LIST array
# define CHAOS_PP_ARRAY_TO_LIST_ID() CHAOS_PP_ARRAY_TO_LIST
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ARRAY_TO_LIST_ CHAOS_PP_LAMBDA(CHAOS_PP_ARRAY_TO_LIST_ID)()
# endif
#
# endif
