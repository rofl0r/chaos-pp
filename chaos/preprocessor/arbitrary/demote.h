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
# ifndef CHAOS_PREPROCESSOR_ARBITRARY_DEMOTE_H
# define CHAOS_PREPROCESSOR_ARBITRARY_DEMOTE_H
#
# include <chaos/preprocessor/arbitrary/detail/clean.h>
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/control/expr_iif.h>
# include <chaos/preprocessor/facilities/binary.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/punctuation/paren.h>
# include <chaos/preprocessor/seq/binary_transform.h>
# include <chaos/preprocessor/seq/detail/close.h>
#
# /* CHAOS_PP_DEMOTE_AP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DEMOTE_AP(x) CHAOS_IP_DEMOTE_AP_I(CHAOS_PP_SUPER_CLEAN_AP(x))
#    define CHAOS_PP_DEMOTE_AP_ID() CHAOS_PP_DEMOTE_AP
#    define CHAOS_PP_DEMOTE_AP_ CHAOS_PP_LAMBDA(CHAOS_PP_DEMOTE_AP)
#    define CHAOS_IP_DEMOTE_AP_I(x) \
        CHAOS_PP_EXPR_IIF(CHAOS_PP_BINARY(0) x)(-) \
        CHAOS_IP_DEMOTE_AP_II(CHAOS_PP_SEQ_BINARY_TRANSFORM(CHAOS_PP_BINARY(1) x,)) \
        /**/
#    define CHAOS_IP_DEMOTE_AP_II(seq) CHAOS_PP_EXPAND(CHAOS_IP_DEMOTE_AP_III seq CHAOS_PP_SEQ_CLOSE(seq))
#    define CHAOS_IP_DEMOTE_AP_INDIRECT() CHAOS_IP_DEMOTE_AP_III
#    define CHAOS_IP_DEMOTE_AP_III(id, n) id(?)(CHAOS_PP_OBSTRUCT(CHAOS_PP_CAT) CHAOS_PP_LPAREN() n, CHAOS_IP_DEMOTE_AP_INDIRECT)
# endif
#
# endif
