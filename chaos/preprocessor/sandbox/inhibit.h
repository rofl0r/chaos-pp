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
# ifndef CHAOS_PREPROCESSOR_DETAIL_SANDBOX_INHIBIT_H
# define CHAOS_PREPROCESSOR_DETAIL_SANDBOX_INHIBIT_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/iif.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
#
# /* CHAOS_PP_INHIBIT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_INHIBIT(pred, op, macro, ...) \
        CHAOS_PP_IIF_SHADOW(pred(__VA_ARGS__))( \
            CHAOS_PP_OBSTRUCT(CHAOS_PP_INHIBIT_ID)()(pred, op, macro, op(__VA_ARGS__)), \
            macro \
        ) \
        /**/
#    define CHAOS_PP_INHIBIT_ CHAOS_PP_LAMBDA(CHAOS_PP_INHIBIT_ID)()
# else
#    define CHAOS_PP_INHIBIT(pred, op, macro, state) \
        CHAOS_PP_IIF_SHADOW(pred(state))( \
            CHAOS_PP_INHIBIT_ID CHAOS_PP_OBSTRUCT()()(pred, op, macro, op(state)), \
            macro \
        ) \
        /**/
# endif
#
# define CHAOS_PP_INHIBIT_ID() CHAOS_PP_INHIBIT
#
# endif
