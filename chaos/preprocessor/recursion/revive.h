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
# ifndef CHAOS_PREPROCESSOR_RECURSION_REVIVE_H
# define CHAOS_PREPROCESSOR_RECURSION_REVIVE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_REVIVE */
#
# define CHAOS_PP_REVIVE(macro) CHAOS_PP_PRIMITIVE_CAT(macro, ID)()
# define CHAOS_PP_REVIVE_ID() CHAOS_PP_REVIVE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REVIVE_ CHAOS_PP_LAMBDA(CHAOS_PP_REVIVE)
# endif
#
# endif
