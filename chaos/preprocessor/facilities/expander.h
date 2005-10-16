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
# ifndef CHAOS_PREPROCESSOR_FACILITIES_EXPANDER_H
# define CHAOS_PREPROCESSOR_FACILITIES_EXPANDER_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/enumerate.h>
#
# /* CHAOS_PP_EXPANDER */
#
# define CHAOS_PP_EXPANDER(arity) CHAOS_PP_PRIMITIVE_CAT(CHAOS_IP_EXPANDER_, arity)
# define CHAOS_PP_EXPANDER_ID() CHAOS_PP_EXPANDER
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_EXPANDER_ CHAOS_PP_LAMBDA(CHAOS_PP_EXPANDER)
# endif
#
# define CHAOS_IP_EXPANDER_2(s, seq) (CHAOS_PP_NEXT(s), CHAOS_PP_SEQ_ENUMERATE(seq))
# define CHAOS_IP_EXPANDER_3(s, p1, seq) (CHAOS_PP_NEXT(s), p1, CHAOS_PP_SEQ_ENUMERATE(seq))
# define CHAOS_IP_EXPANDER_4(s, p1, p2, seq) (CHAOS_PP_NEXT(s), p1, p2, CHAOS_PP_SEQ_ENUMERATE(seq))
# define CHAOS_IP_EXPANDER_5(s, p1, p2, p3, seq) (CHAOS_PP_NEXT(s), p1, p2, p3, CHAOS_PP_SEQ_ENUMERATE(seq))
#
# endif
