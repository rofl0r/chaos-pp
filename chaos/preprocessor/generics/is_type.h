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
# ifndef CHAOS_PREPROCESSOR_GENERICS_IS_TYPE_H
# define CHAOS_PREPROCESSOR_GENERICS_IS_TYPE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detection/is_nullary.h>
# include <chaos/preprocessor/generics/spec.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/compl.h>
#
# /* CHAOS_PP_IS_TYPE */
#
# define CHAOS_PP_IS_TYPE(type, g) \
    CHAOS_PP_COMPL(CHAOS_PP_IS_NULLARY( \
        CHAOS_PP_TAG(type)(CHAOS_PP_TAG(CHAOS_PP_TYPEOF(g)))(()) \
    )) \
    /**/
# define CHAOS_PP_IS_TYPE_ID() CHAOS_PP_IS_TYPE
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_TYPE_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_TYPE)
# endif
#
# endif
