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
# ifndef CHAOS_PREPROCESSOR_CONTROL_BRANCH_H
# define CHAOS_PREPROCESSOR_CONTROL_BRANCH_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/logical/bool.h>
#
# /* CHAOS_PP_BRANCH */
#
# define CHAOS_PP_BRANCH(id) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BRANCH_A_, id)
# define CHAOS_PP_BRANCH_ID() CHAOS_PP_BRANCH
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_BRANCH_ CHAOS_PP_LAMBDA(CHAOS_PP_BRANCH)
# endif
#
# define CHAOS_IP_BRANCH_A_0xIF(cond) CHAOS_IP_BRANCH_A_0xIIF(CHAOS_PP_BOOL(cond))
# define CHAOS_IP_BRANCH_A_0xIIF(bit) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BRANCH_A_0xIIF_, bit)
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_BRANCH_A_0xIIF_0(...) CHAOS_IP_BRANCH_B
#    define CHAOS_IP_BRANCH_A_0xIIF_1(...) __VA_ARGS__ CHAOS_IP_BRANCH_C
# else
#    define CHAOS_IP_BRANCH_A_0xIIF_0(x) CHAOS_IP_BRANCH_B
#    define CHAOS_IP_BRANCH_A_0xIIF_1(x) x CHAOS_IP_BRANCH_C
# endif
#
# define CHAOS_IP_BRANCH_B(id) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BRANCH_B_, id)
# define CHAOS_IP_BRANCH_B_0xELIF CHAOS_IP_BRANCH_A_0xIF
# define CHAOS_IP_BRANCH_B_0xELIIF CHAOS_IP_BRANCH_A_0xIIF
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_BRANCH_B_0xELSE(...) __VA_ARGS__ CHAOS_IP_BRANCH_D
# else
#    define CHAOS_IP_BRANCH_B_0xELSE(x) x CHAOS_IP_BRANCH_D
# endif
#
# define CHAOS_IP_BRANCH_B_0xENDIF
#
# define CHAOS_IP_BRANCH_C(n) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BRANCH_C_, n)
# define CHAOS_IP_BRANCH_C_0xELIF CHAOS_IP_BRANCH_C_0xELIIF
# define CHAOS_IP_BRANCH_C_0xELIIF(bit) CHAOS_IP_BRANCH_C_0xELIIF_I
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_BRANCH_C_0xELIIF_I(...) CHAOS_IP_BRANCH_C
#    define CHAOS_IP_BRANCH_C_0xELSE(...) CHAOS_IP_BRANCH_D
# else
#    define CHAOS_IP_BRANCH_C_0xELIIF_I(x) CHAOS_IP_BRANCH_C
#    define CHAOS_IP_BRANCH_C_0xELSE(x) CHAOS_IP_BRANCH_D
# endif
#
# define CHAOS_IP_BRANCH_C_0xENDIF
#
# define CHAOS_IP_BRANCH_D(id) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_BRANCH_D_, id)
# define CHAOS_IP_BRANCH_D_0xENDIF
#
# endif
