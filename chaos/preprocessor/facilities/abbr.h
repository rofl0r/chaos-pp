# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2004.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_FACILITIES_ABBR_H
# define CHAOS_PREPROCESSOR_FACILITIES_ABBR_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_ABBR */
#
# define CHAOS_PP_ABBR(id) CHAOS_PP_ ## id
# define CHAOS_PP_ABBR_ID() CHAOS_PP_ABBR
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ABBR_ CHAOS_PP_LAMBDA(CHAOS_PP_ABBR)
# endif
#
# endif
