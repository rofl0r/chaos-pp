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
# ifndef CHAOS_PREPROCESSOR_GENERICS_IS_ELEMENTAL_H
# define CHAOS_PREPROCESSOR_GENERICS_IS_ELEMENTAL_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_variadic.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_IS_ELEMENTAL */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_ELEMENTAL(type) \
        CHAOS_PP_COMPL(CHAOS_PP_IS_VARIADIC(CHAOS_PP_ITEM(type,))) \
        /**/
#    define CHAOS_PP_IS_ELEMENTAL_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_ELEMENTAL)
# else
#    define CHAOS_PP_IS_ELEMENTAL(type) 1
# endif
#
# define CHAOS_PP_IS_ELEMENTAL_ID() CHAOS_PP_IS_ELEMENTAL
#
# endif
