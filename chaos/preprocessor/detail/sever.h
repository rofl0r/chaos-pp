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
# ifndef CHAOS_PREPROCESSOR_DETAIL_SEVER_H
# define CHAOS_PREPROCESSOR_DETAIL_SEVER_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/detail/paste.h>
#
# /* CHAOS_PP_SEVER */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEVER(i, ...) CHAOS_PP_PRIMITIVE_PASTE(CHAOS_IP_SEVER_, i)(__VA_ARGS__)
#    define CHAOS_IP_SEVER_0(a, ...) a
#    define CHAOS_IP_SEVER_1(a, ...) __VA_ARGS__
# else
#    define CHAOS_PP_SEVER(i, im) CHAOS_PP_PRIMITIVE_PASTE(CHAOS_IP_SEVER_, i)(im)
#    define CHAOS_IP_SEVER_0(a, b) a
#    define CHAOS_IP_SEVER_1(a, b) b
# endif
#
# endif
