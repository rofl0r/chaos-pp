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
# ifndef CHAOS_PREPROCESSOR_LOGICAL_NAND_H
# define CHAOS_PREPROCESSOR_LOGICAL_NAND_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bool.h>
# include <chaos/preprocessor/logical/not.h>
#
# /* CHAOS_PP_NAND */
#
# define CHAOS_PP_NAND(p) CHAOS_PP_CAT(CHAOS_IP_NAND_, CHAOS_PP_BOOL(p))
# define CHAOS_PP_NAND_ID() CHAOS_PP_NAND
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NAND_ CHAOS_PP_LAMBDA(CHAOS_PP_NAND)
# endif
#
# define CHAOS_IP_NAND_0(q) 1
# define CHAOS_IP_NAND_1(q) CHAOS_PP_NOT(q)
#
# endif
