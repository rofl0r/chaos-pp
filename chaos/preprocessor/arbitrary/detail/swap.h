# /* ********************************************************************
#  *                                                                    *
#  *    (C) Copyright Paul Mensonides 2003-2005.                        *
#  *                                                                    *
#  *    Distributed under the Boost Software License, Version 1.0.      *
#  *    (See accompanying file LICENSE).                                *
#  *                                                                    *
#  *    See http://chaos-pp.sourceforge.net for most recent version.    *
#  *                                                                    *
#  ******************************************************************** */
#
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_SWAP_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_SWAP_H
#
# include <chaos/preprocessor/config.h>
#
# /* CHAOS_PP_SWAP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SWAP(a, ...) (__VA_ARGS__, a)
# else
#    define CHAOS_PP_SWAP(a, b) (b, a)
# endif
#
# /* CHAOS_PP_NO_SWAP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NO_SWAP(a, ...) (a, __VA_ARGS__)
# else
#    define CHAOS_PP_NO_SWAP(a, b) (a, b)
# endif
#
# endif
