#ifndef CXX_INIT_H
#define CXX_INIT_H

#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>

namespace cxx_init {

    namespace detail {
#define CXX_ASSIGN_FIELD(r, data, elem) data elem;

        template<typename Func>
        struct cxx_init_helper 
        {
            Func cb;

            template<typename T>
            operator T() const {
                return cb(T{});
            }
        };

        template<typename Func>
        cxx_init_helper<Func> makeInitHelper(Func cb) {
            return { cb };
        }
    }

} // namespace cxx_init

#define cxx(...) cxx_init::detail::makeInitHelper([](auto temp) -> decltype(temp) { \
    BOOST_PP_SEQ_FOR_EACH( \
        CXX_ASSIGN_FIELD, \
        temp, \
        BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__) \
    ) \
    return temp; \
})

#endif // CXX_INIT_H