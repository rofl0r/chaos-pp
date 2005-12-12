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
# ifndef CHAOS_PREPROCESSOR_RECURSION_DYNAMIC_H
# define CHAOS_PREPROCESSOR_RECURSION_DYNAMIC_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/binary_transform.h>
# include <chaos/preprocessor/seq/detail/close.h>
# include <chaos/preprocessor/seq/infuse.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_DYNAMIC */
#
# define CHAOS_PP_DYNAMIC(seq, macro, args) CHAOS_PP_DYNAMIC_S(CHAOS_PP_STATE(), seq, macro, args)
# define CHAOS_PP_DYNAMIC_ID() CHAOS_PP_DYNAMIC
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DYNAMIC_ CHAOS_PP_LAMBDA(CHAOS_PP_DYNAMIC_ID)()
# endif
#
# /* CHAOS_PP_DYNAMIC_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DYNAMIC_S(s, seq, macro, args) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_DYNAMIC_I CHAOS_PP_SEQ_INFUSE(seq, CHAOS_IP_DYNAMIC_II, CHAOS_PP_NEXT(s))(CHAOS_PP_EAT, ~, ~)) \
        CHAOS_PP_DEFER(macro) args \
        CHAOS_PP_SEQ_CLOSE(CHAOS_PP_SEQ_BINARY_TRANSFORM(seq,)) \
        /**/
#    define CHAOS_PP_DYNAMIC_S_ CHAOS_PP_LAMBDA(CHAOS_PP_DYNAMIC_S_ID)()
# else
#    define CHAOS_PP_DYNAMIC_S(s, seq, macro, args) \
        CHAOS_PP_EXPR_S(s)(CHAOS_IP_DYNAMIC_I CHAOS_PP_SEQ_INFUSE(seq, (CHAOS_IP_DYNAMIC_II, CHAOS_PP_NEXT(s)))((CHAOS_PP_EAT, ~), ~)) \
        CHAOS_PP_DEFER(macro) args \
        CHAOS_PP_SEQ_CLOSE(CHAOS_PP_SEQ_BINARY_TRANSFORM(seq, ~)) \
        /**/
# endif
#
# define CHAOS_IP_DYNAMIC_INDIRECT() CHAOS_IP_DYNAMIC_I
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_IP_DYNAMIC_I(m, s, ...) m(s)
# else
#    define CHAOS_IP_DYNAMIC_I(pair, _) CHAOS_PP_BINARY(0) pair(CHAOS_PP_BINARY(1) pair)
# endif
#
# define CHAOS_IP_DYNAMIC_II(s) CHAOS_PP_DEFER(CHAOS_PP_EXPR_S)(s)(CHAOS_IP_DYNAMIC_INDIRECT
#
# endif
