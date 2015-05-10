#include <type_traits>

//@{ convertible
struct has_method_impl
{
    static std::true_type TryPointer(const void*);
    static std::false_type TryPointer(...);
};

template <typename From, typename To>
struct is_convertible
    : decltype(is_convertible_impl<To>::TryPointer(*(From*) nullptr))
{
};
//@} convertiable

struct Base
{
};
struct Der : Base
{
};

struct Cast
{
    operator Base(){};
};

int main()
{
    static_assert(is_convertible<int, double>::value, "int to double");
    static_assert(is_convertible<Der, Base>::value, "Derived to Base");
    static_assert(is_convertible<Cast, Base>::value, "Cast operator");

    return 0;
}
