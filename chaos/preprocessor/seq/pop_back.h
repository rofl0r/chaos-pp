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
# ifndef CHAOS_PREPROCESSOR_SEQ_POP_BACK_H
# define CHAOS_PREPROCESSOR_SEQ_POP_BACK_H
#
# include <chaos/preprocessor/arithmetic/dec.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/first_n.h>
# include <chaos/preprocessor/seq/size.h>
#
# /* CHAOS_PP_SEQ_POP_BACK */
#
# define CHAOS_PP_SEQ_POP_BACK(seq) \
    CHAOS_PP_SEQ_FIRST_N(CHAOS_PP_DEC(CHAOS_PP_SEQ_SIZE(seq)), seq) \
    /**/
# define CHAOS_PP_SEQ_POP_BACK_ID() CHAOS_PP_SEQ_POP_BACK
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_POP_BACK_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_POP_BACK_ID)()
# endif
#
# endif
