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
# ifndef CHAOS_PREPROCESSOR_GENERICS_TYPE_H
# define CHAOS_PREPROCESSOR_GENERICS_TYPE_H
#
# include <chaos/preprocessor/cat.h>
# include <chaos/preprocessor/config.h>
# include <chaos/preprocessor/generics/strip.h>
# include <chaos/preprocessor/generics/typeof.h>
# include <chaos/preprocessor/lambda/ops.h>
# include <chaos/preprocessor/recursion/basic.h>
# include <chaos/preprocessor/tuple/eat.h>
#
# /* CHAOS_PP_TAG */
#
# define CHAOS_PP_TAG(type) CHAOS_PP_PRIMITIVE_CAT_SHADOW(type, _TAG)
# define CHAOS_PP_TAG_ID() CHAOS_PP_TAG
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_TAG_ CHAOS_PP_LAMBDA(CHAOS_PP_TAG)
# endif
#
# /* CHAOS_PP_NIL */
#
# define CHAOS_PP_NIL(type) (type) CHAOS_PP_PRIMITIVE_CAT_SHADOW(type, _NIL)()
# define CHAOS_PP_NIL_ID() CHAOS_PP_NIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_NIL)
# endif
#
# /* CHAOS_PP_CONS */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CONS(g, ...) CHAOS_IP_CONS_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP(g), (__VA_ARGS__))
#    define CHAOS_PP_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_CONS_ID)()
# else
#    define CHAOS_PP_CONS(g, x) CHAOS_IP_CONS_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP(g), (x))
# endif
#
# define CHAOS_PP_CONS_ID() CHAOS_PP_CONS
#
# define CHAOS_IP_CONS_I(type, data, px) (type) CHAOS_PP_PRIMITIVE_CAT_SHADOW(type, _CONS)(data, CHAOS_PP_UNPACK px)
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CONS_SHADOW(g, ...) CHAOS_IP_CONS_SHADOW_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP_SHADOW(g), (__VA_ARGS__))
# else
#    define CHAOS_PP_CONS_SHADOW(g, x) CHAOS_IP_CONS_SHADOW_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP_SHADOW(g), (x))
# endif
#
# define CHAOS_IP_CONS_SHADOW_I(type, data, px) (type) CHAOS_PP_PRIMITIVE_CAT_SHADOW(type, _CONS_SHADOW)(data, CHAOS_PP_UNPACK_SHADOW px)
#
# /* CHAOS_PP_ITEM */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ITEM(type, ...) CHAOS_PP_PRIMITIVE_CAT_SHADOW(type, _ITEM)(__VA_ARGS__)
#    define CHAOS_PP_ITEM_ CHAOS_PP_LAMBDA(CHAOS_PP_ITEM_ID)()
# else
#    define CHAOS_PP_ITEM(type, x) CHAOS_PP_PRIMITIVE_CAT_SHADOW(type, _ITEM)(x)
# endif
#
# define CHAOS_PP_ITEM_ID() CHAOS_PP_ITEM
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_ITEM_SHADOW(type, ...) CHAOS_PP_PRIMITIVE_CAT_SHADOW(type, _ITEM_SHADOW)(__VA_ARGS__)
# else
#    define CHAOS_PP_ITEM_SHADOW(type, x) CHAOS_PP_PRIMITIVE_CAT_SHADOW(type, _ITEM_SHADOW)(x)
# endif
#
# /* CHAOS_PP_FIRST */
#
# define CHAOS_PP_FIRST(g) CHAOS_IP_FIRST_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP(g))
# define CHAOS_PP_FIRST_ID() CHAOS_PP_FIRST
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_FIRST_ CHAOS_PP_LAMBDA(CHAOS_PP_FIRST_ID)()
# endif
#
# define CHAOS_IP_FIRST_I(type, data) CHAOS_PP_PRIMITIVE_CAT_SHADOW(type, _FIRST)(data)
#
# define CHAOS_PP_FIRST_SHADOW(g) CHAOS_IP_FIRST_SHADOW_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP_SHADOW(g))
# define CHAOS_IP_FIRST_SHADOW_I(type, data) CHAOS_PP_PRIMITIVE_CAT_SHADOW(type, _FIRST_SHADOW)(data)
#
# /* CHAOS_PP_REST */
#
# define CHAOS_PP_REST(g) CHAOS_IP_REST_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP(g))
# define CHAOS_PP_REST_ID() CHAOS_PP_REST
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_REST_ CHAOS_PP_LAMBDA(CHAOS_PP_REST_ID)()
# endif
#
# define CHAOS_IP_REST_I(type, data) (type) CHAOS_PP_PRIMITIVE_CAT_SHADOW(type, _REST)(data)
#
# define CHAOS_PP_REST_SHADOW(g) CHAOS_IP_REST_SHADOW_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP_SHADOW(g))
# define CHAOS_IP_REST_SHADOW_I(type, data) CHAOS_PP_PRIMITIVE_CAT_SHADOW(type, _REST_SHADOW)(data)
#
# /* CHAOS_PP_IS_CONS */
#
# define CHAOS_PP_IS_CONS(g) CHAOS_IP_IS_CONS_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP_SHADOW(g))
# define CHAOS_PP_IS_CONS_ID() CHAOS_PP_IS_CONS
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_CONS_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_CONS)
# endif
#
# define CHAOS_IP_IS_CONS_I(type, data) CHAOS_PP_PRIMITIVE_CAT(type, _IS_CONS)(data)
#
# /* CHAOS_PP_IS_NIL */
#
# define CHAOS_PP_IS_NIL(g) CHAOS_IP_IS_NIL_I(CHAOS_PP_TYPEOF(g), CHAOS_PP_STRIP_SHADOW(g))
# define CHAOS_PP_IS_NIL_ID() CHAOS_PP_IS_NIL
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_IS_NIL_ CHAOS_PP_LAMBDA(CHAOS_PP_IS_NIL)
# endif
#
# define CHAOS_IP_IS_NIL_I(type, data) CHAOS_PP_PRIMITIVE_CAT(type, _IS_NIL)(data)
#
# endif
