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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_NAMESPACE_H
# define CHAOS_PREPROCESSOR_ARBITRARY_NAMESPACE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/recursion/machine.h>
#
# /* CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY(id) CHAOS_PP_INSTRUCTION_0xCHAOS_0xARBITRARY_ ## id
# endif
#
# endif
