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
# ifndef CHAOS_PREPROCESSOR_SEQ_VARIADIC_FILTER_H
# define CHAOS_PREPROCESSOR_SEQ_VARIADIC_FILTER_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/optional.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/recursion/expr.h>
# include <chaos/preprocessor/seq/filter.h>
# include <chaos/preprocessor/seq/zip.h>
#
# /* CHAOS_PP_VARIADIC_SEQ_FILTER */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_FILTER(pred, ...) CHAOS_PP_VARIADIC_SEQ_FILTER_S(CHAOS_PP_STATE(), pred, __VA_ARGS__)
#    define CHAOS_PP_VARIADIC_SEQ_FILTER_ID() CHAOS_PP_VARIADIC_SEQ_FILTER
#    define CHAOS_PP_VARIADIC_SEQ_FILTER_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_FILTER_ID)()
# endif
#
# /* CHAOS_PP_VARIADIC_SEQ_FILTER_S */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_VARIADIC_SEQ_FILTER_S(s, pred, ...) CHAOS_PP_DEFER(CHAOS_PP_SEQ_UNZIP)(CHAOS_PP_SEQ_FILTER_S(s, pred, CHAOS_PP_SEQ_ZIP(CHAOS_PP_NON_OPTIONAL(__VA_ARGS__)) CHAOS_PP_EXPOSE(CHAOS_PP_PACK_OPTIONAL(__VA_ARGS__))))
#    define CHAOS_PP_VARIADIC_SEQ_FILTER_S_ID() CHAOS_PP_VARIADIC_SEQ_FILTER_S
#    define CHAOS_PP_VARIADIC_SEQ_FILTER_S_ CHAOS_PP_LAMBDA(CHAOS_PP_VARIADIC_SEQ_FILTER_S_ID)()
# endif
#
# endif
