# /* (C) Copyright Paul Mensonides 2003 */
#
# ifndef CHAOS_PREPROCESSOR_CAT_HPP
# define CHAOS_PREPROCESSOR_CAT_HPP
#
# include <chaos/preprocessor/config.hpp>
# include <chaos/preprocessor/lambda/ops.hpp>
#
# /* CHAOS_PP_CAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_CAT(a, ...) CHAOS_PP_PRIMITIVE_CAT(a, __VA_ARGS__)
#    define CHAOS_PP_CAT_ CHAOS_PP_LAMBDA(CHAOS_PP_CAT_ID)()
# else
#    define CHAOS_PP_CAT(a, b) CHAOS_PP_PRIMITIVE_CAT(a, b)
# endif
#
# define CHAOS_PP_CAT_ID() CHAOS_PP_CAT
#
# /* CHAOS_PP_PRIMITIVE_CAT */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__
#    define CHAOS_PP_PRIMITIVE_CAT_ CHAOS_PP_LAMBDA(CHAOS_PP_PRIMITIVE_CAT_ID)()
# else
#    define CHAOS_PP_PRIMITIVE_CAT(a, b) a ## b
# endif
#
# define CHAOS_PP_PRIMITIVE_CAT_ID() CHAOS_PP_PRIMITIVE_CAT
#
# endif
