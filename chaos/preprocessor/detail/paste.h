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
# ifndef CHAOS_PREPROCESSOR_DETAIL_PASTE_H
# define CHAOS_PREPROCESSOR_DETAIL_PASTE_H
#
# include <chaos/preprocessor/config.h>
#
# /* CHAOS_PP_PASTE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PASTE(a, ...) CHAOS_PP_PRIMITIVE_PASTE(a, __VA_ARGS__)
# else
#    define CHAOS_PP_PASTE(a, b) CHAOS_PP_PRIMITIVE_PASTE(a, b)
# endif
#
# /* CHAOS_PP_PRIMITIVE_PASTE */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PRIMITIVE_PASTE(a, ...) a ## __VA_ARGS__
# else
#    define CHAOS_PP_PRIMITIVE_PASTE(a, b) a ## b
# endif
#
# endif
