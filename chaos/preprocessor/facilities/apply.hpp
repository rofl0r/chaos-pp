# /* (C) Copyright Paul Mensonides 2003 */
#
# ifndef CHAOS_PREPROCESSOR_FACILITIES_APPLY_HPP
# define CHAOS_PREPROCESSOR_FACILITIES_APPLY_HPP
#
# include <chaos/preprocessor/config.hpp>
# include <chaos/preprocessor/control/expr_iif.hpp>
# include <chaos/preprocessor/detection/is_unary.hpp>
# include <chaos/preprocessor/detection/is_variadic.hpp>
# include <chaos/preprocessor/lambda/ops.hpp>
# include <chaos/preprocessor/tuple/rem.hpp>
#
# /* CHAOS_PP_APPLY */
#
# if CHAOS_PP_VARIADICS
#    define CHAOS_PP_APPLY(...) \
        CHAOS_PP_EXPR_IIF(CHAOS_PP_IS_VARIADIC(__VA_ARGS__))( \
            CHAOS_PP_TUPLE_REM(?) __VA_ARGS__ \
        ) \
        /**/
#    define CHAOS_PP_APPLY_ CHAOS_PP_LAMBDA(CHAOS_PP_APPLY_ID)()
# else
#    define CHAOS_PP_APPLY(x) \
        CHAOS_PP_EXPR_IIF(CHAOS_PP_IS_UNARY(x))( \
            CHAOS_PP_TUPLE_REM(1) x \
        ) \
        /**/
# endif
#
# define CHAOS_PP_APPLY_ID() CHAOS_PP_APPLY
#
# endif
