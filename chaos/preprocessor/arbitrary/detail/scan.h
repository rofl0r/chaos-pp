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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_SCAN_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_SCAN_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
#
# /* CHAOS_PP_SCAN */
#
# define CHAOS_PP_SCAN(level) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_SCAN_, level)
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SCAN_1(...) __VA_ARGS__
#    define CHAOS_IP_SCAN_2(...) __VA_ARGS__
#    define CHAOS_IP_SCAN_3(...) __VA_ARGS__
#    define CHAOS_IP_SCAN_4(...) __VA_ARGS__
# else
#    define CHAOS_IP_SCAN_1(x) x
#    define CHAOS_IP_SCAN_2(x) x
#    define CHAOS_IP_SCAN_3(x) x
#    define CHAOS_IP_SCAN_4(x) x
# endif
#
# endif
