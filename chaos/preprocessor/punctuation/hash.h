# /* *************************************************************************
#  *                                                                         *
#  *    (C) Copyright Paul Mensonides 2004.                                  *
#  *                                                                         *
#  *    Use, modification, and distribution are subject to Version 1.0 of    *
#  *    the Boost Software License.  (See accompanying file LICENSE.)        *
#  *                                                                         *
#  *    See http://chaos-pp.sourceforge.net for most recent version.         *
#  *                                                                         *
#  ************************************************************************* */
#
# ifndef CHAOS_PREPROCESSOR_PUNCTUATION_HASH_H
# define CHAOS_PREPROCESSOR_PUNCTUATION_HASH_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/lambda/ops.h>
#
# /* CHAOS_PP_HASH */
#
# define CHAOS_PP_HASH() CHAOS_IP_HASH_I
# define CHAOS_PP_HASH_ID() CHAOS_PP_HASH
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_HASH_ CHAOS_PP_LAMBDA(CHAOS_PP_HASH)
# endif
#
# define CHAOS_IP_HASH_I #
#
# /* CHAOS_PP_HASH_HASH */
#
# define CHAOS_PP_HASH_HASH() CHAOS_PP_CAT(CHAOS_PP_HASH(), CHAOS_PP_HASH())
# define CHAOS_PP_HASH_HASH_ID() CHAOS_PP_HASH_HASH
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_HASH_HASH_ CHAOS_PP_LAMBDA(CHAOS_PP_HASH_HASH)
# endif
#
# /* CHAOS_PP_DIGRAPH_HASH */
#
# define CHAOS_PP_DIGRAPH_HASH() % ## :
# define CHAOS_PP_DIGRAPH_HASH_ID() CHAOS_PP_DIGRAPH_HASH
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DIGRAPH_HASH_ CHAOS_PP_LAMBDA(CHAOS_PP_DIGRAPH_HASH)
# endif
#
# /* CHAOS_PP_DIGRAPH_HASH_HASH */
#
# define CHAOS_PP_DIGRAPH_HASH_HASH() CHAOS_PP_PRIMITIVE_CAT(% ## :, % ## :)
# define CHAOS_PP_DIGRAPH_HASH_HASH_ID() CHAOS_PP_DIGRAPH_HASH_HASH
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_DIGRAPH_HASH_HASH_ CHAOS_PP_LAMBDA(CHAOS_PP_DIGRAPH_HASH_HASH)
# endif
#
# endif
