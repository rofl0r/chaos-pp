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
# ifndef CHAOS_PREPROCESSOR_STRINGIZE_H
# define CHAOS_PREPROCESSOR_STRINGIZE_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_STRINGIZE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_STRINGIZE(...) CHAOS_PP_PRIMITIVE_STRINGIZE(__VA_ARGS__)
#    define CHAOS_PP_STRINGIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_STRINGIZE)
# else
#    define CHAOS_PP_STRINGIZE(x) CHAOS_PP_PRIMITIVE_STRINGIZE(x)
# endif
#
# define CHAOS_PP_STRINGIZE_ID() CHAOS_PP_STRINGIZE
#
# /* CHAOS_PP_PRIMITIVE_STRINGIZE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PRIMITIVE_STRINGIZE(...) #__VA_ARGS__
#    define CHAOS_PP_PRIMITIVE_STRINGIZE_ CHAOS_PP_LAMBDA(CHAOS_PP_PRIMITIVE_STRINGIZE)
# else
#    define CHAOS_PP_PRIMITIVE_STRINGIZE(x) #x
# endif
#
# define CHAOS_PP_PRIMITIVE_STRINGIZE_ID() CHAOS_PP_PRIMITIVE_STRINGIZE
#
# endif
