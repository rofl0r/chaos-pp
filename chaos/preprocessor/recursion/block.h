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
# ifndef CHAOS_PREPROCESSOR_RECURSION_BLOCK_H
# define CHAOS_PREPROCESSOR_RECURSION_BLOCK_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/empty.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_BLOCK */
#
# define CHAOS_PP_BLOCK(n, macro) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BLOCK_, n)(macro, CHAOS_PP_EMPTY)
# define CHAOS_PP_BLOCK_ID() CHAOS_PP_BLOCK
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BLOCK_ CHAOS_PP_LAMBDA(CHAOS_PP_BLOCK)
# endif
#
# define CHAOS_IP_BLOCK_0(macro, _) macro
# define CHAOS_IP_BLOCK_1(macro, _) macro _()
# define CHAOS_IP_BLOCK_2(macro, _) macro _ _()()
# define CHAOS_IP_BLOCK_3(macro, _) macro _ _ _()()()
# define CHAOS_IP_BLOCK_4(macro, _) macro _ _ _ _()()()()
# define CHAOS_IP_BLOCK_5(macro, _) macro _ _ _ _ _()()()()()
#
# endif
