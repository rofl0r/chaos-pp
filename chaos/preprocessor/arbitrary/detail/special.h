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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_SPECIAL_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DETAIL_SPECIAL_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/punctuation/paren.h>
#
# /* CHAOS_PP_SPECIAL */
#
# define CHAOS_PP_SPECIAL(digit) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_SPECIAL_, digit)
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_SPECIAL_00(...)
#    define CHAOS_IP_SPECIAL_0(...) __VA_ARGS__
#    define CHAOS_IP_SPECIAL_1(...) __VA_ARGS__
#    define CHAOS_IP_SPECIAL_2(...) __VA_ARGS__
#    define CHAOS_IP_SPECIAL_3(...) __VA_ARGS__
#    define CHAOS_IP_SPECIAL_4(...) __VA_ARGS__
#    define CHAOS_IP_SPECIAL_5(...) __VA_ARGS__
#    define CHAOS_IP_SPECIAL_6(...) __VA_ARGS__
#    define CHAOS_IP_SPECIAL_7(...) __VA_ARGS__
#    define CHAOS_IP_SPECIAL_8(...) __VA_ARGS__
#    define CHAOS_IP_SPECIAL_9(...) __VA_ARGS__
# else
#    define CHAOS_IP_SPECIAL_00(x)
#    define CHAOS_IP_SPECIAL_0(x) x
#    define CHAOS_IP_SPECIAL_1(x) x
#    define CHAOS_IP_SPECIAL_2(x) x
#    define CHAOS_IP_SPECIAL_3(x) x
#    define CHAOS_IP_SPECIAL_4(x) x
#    define CHAOS_IP_SPECIAL_5(x) x
#    define CHAOS_IP_SPECIAL_6(x) x
#    define CHAOS_IP_SPECIAL_7(x) x
#    define CHAOS_IP_SPECIAL_8(x) x
#    define CHAOS_IP_SPECIAL_9(x) x
# endif
#
# /* CHAOS_PP_SPECIAL_CLOSE */
#
# define CHAOS_PP_SPECIAL_CLOSE(x) CHAOS_IP_SPECIAL_CLOSE_A x(00)
#
# define CHAOS_IP_SPECIAL_CLOSE_A(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_PP_RPAREN() CHAOS_IP_SPECIAL_CLOSE_B)
# define CHAOS_IP_SPECIAL_CLOSE_B(digit) CHAOS_PP_SPECIAL(digit)(CHAOS_PP_RPAREN() CHAOS_IP_SPECIAL_CLOSE_A)
#
# endif
