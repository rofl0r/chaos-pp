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
# ifndef CHAOS_PREPROCESSOR_SEQ_ZIP_H
# define CHAOS_PREPROCESSOR_SEQ_ZIP_H
#
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/facilities/expand.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/seq/binary_transform.h>
#
# /* CHAOS_PP_SEQ_ZIP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_ZIP(seq) \
        CHAOS_PP_EXPAND(CHAOS_IP_SEQ_ZIP_I CHAOS_PP_SEQ_BINARY_TRANSFORM(seq,)) \
        /**/
#    define CHAOS_PP_SEQ_ZIP_ID() CHAOS_PP_SEQ_ZIP
#    define CHAOS_PP_SEQ_ZIP_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_ZIP_ID)()
#    define CHAOS_IP_SEQ_ZIP_INDIRECT() CHAOS_IP_SEQ_ZIP_I
#    define CHAOS_IP_SEQ_ZIP_I(id, ...) id(?)(((__VA_ARGS__)) CHAOS_IP_SEQ_ZIP_INDIRECT)
# endif
#
# /* CHAOS_PP_SEQ_UNZIP */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_SEQ_UNZIP(seq) \
        CHAOS_PP_EXPAND(CHAOS_IP_SEQ_UNZIP_I CHAOS_PP_SEQ_BINARY_TRANSFORM(seq,)) \
        /**/
#    define CHAOS_PP_SEQ_UNZIP_ID() CHAOS_PP_SEQ_UNZIP
#    define CHAOS_PP_SEQ_UNZIP_ CHAOS_PP_LAMBDA(CHAOS_PP_SEQ_UNZIP_ID)()
#    define CHAOS_IP_SEQ_UNZIP_INDIRECT() CHAOS_IP_SEQ_UNZIP_I
#    define CHAOS_IP_SEQ_UNZIP_I(id, zip) id(?)((CHAOS_PP_TUPLE_REM(?) zip) CHAOS_IP_SEQ_UNZIP_INDIRECT)
# endif
#
# endif
