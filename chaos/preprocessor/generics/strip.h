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
# ifndef CHAOS_PREPROCESSOR_GENERICS_STRIP_H
# define CHAOS_PREPROCESSOR_GENERICS_STRIP_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_STRIP */
#
# define CHAOS_PP_STRIP(g) CHAOS_PP_TUPLE_EAT(1) g
# define CHAOS_PP_STRIP_ID() CHAOS_PP_STRIP
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRIP_ CHAOS_PP_LAMBDA(CHAOS_PP_STRIP_ID)()
# endif
#
# endif
