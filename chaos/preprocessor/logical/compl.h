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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_COMPL_H
# define CHAOS_PREPROCESSOR_LOGICAL_COMPL_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_COMPL */
#
# define CHAOS_PP_COMPL(bit) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_COMPL_, bit)
# define CHAOS_PP_COMPL_ID() CHAOS_PP_COMPL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_COMPL_ CHAOS_PP_LAMBDA(CHAOS_PP_COMPL)
# endif
#
# define CHAOS_IP_COMPL_0 1
# define CHAOS_IP_COMPL_1 0
#
# endif
