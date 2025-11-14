#include "../include/Fixed.hpp"
#include <iostream>

int main(void) {
	std::cout << "=== CONSTRUCTORS TEST ===" << std::endl;
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===" << std::endl;
	a = Fixed(1234.4321f);

	std::cout << "\n=== OUTPUT TEST ===" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "\n=== CONVERSION TEST ===" << std::endl;
	std::cout << "a as int: " << a.toInt() << std::endl;
	std::cout << "b as int: " << b.toInt() << std::endl;
	std::cout << "c as int: " << c.toInt() << std::endl;

	std::cout << "\n=== COMPARISON OPERATORS TEST ===" << std::endl;
	Fixed e(5.5f);
	Fixed f(10.2f);

	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "e > f: " << (e > f) << std::endl;
	std::cout << "e < f: " << (e < f) << std::endl;
	std::cout << "e >= f: " << (e >= f) << std::endl;
	std::cout << "e <= f: " << (e <= f) << std::endl;
	std::cout << "e == f: " << (e == f) << std::endl;
	std::cout << "e != f: " << (e != f) << std::endl;

	Fixed g(5.5f);
	std::cout << "\ng = " << g << ", e = " << e << std::endl;
	std::cout << "g == e: " << (g == e) << std::endl;

	std::cout << "\n=== ARITHMETIC OPERATORS TEST ===" << std::endl;
	Fixed h(10.5f);
	Fixed i(2.5f);

	std::cout << "h = " << h << ", i = " << i << std::endl;
	std::cout << "h + i = " << (h + i) << std::endl;
	std::cout << "h - i = " << (h - i) << std::endl;
	std::cout << "h * i = " << (h * i) << std::endl;
	std::cout << "h / i = " << (h / i) << std::endl;

	std::cout << "\n=== INCREMENT/DECREMENT TEST ===" << std::endl;
	Fixed j(5.0f);

	std::cout << "j = " << j << std::endl;
	std::cout << "++j = " << ++j << std::endl;
	std::cout << "j = " << j << std::endl;
	std::cout << "j++ = " << j++ << std::endl;
	std::cout << "j = " << j << std::endl;

	std::cout << "\n--j = " << --j << std::endl;
	std::cout << "j = " << j << std::endl;
	std::cout << "j-- = " << j-- << std::endl;
	std::cout << "j = " << j << std::endl;

	std::cout << "\n=== EPSILON TEST ===" << std::endl;
	Fixed k(1.0f);
	std::cout << "k = " << k << std::endl;
	++k;
	std::cout << "After ++k = " << k << std::endl;
	std::cout << "Difference (should be epsilon ~0.00390625): " << (k.toFloat() - 1.0f) << std::endl;

	std::cout << "\n=== MIN/MAX TEST ===" << std::endl;
	Fixed m(10.5f);
	Fixed n(20.3f);

	std::cout << "m = " << m << ", n = " << n << std::endl;
	std::cout << "min(m, n) = " << Fixed::min(m, n) << std::endl;
	std::cout << "max(m, n) = " << Fixed::max(m, n) << std::endl;

	std::cout << "\n=== CONST MIN/MAX TEST ===" << std::endl;
	Fixed const o(42.42f);
	Fixed const p(21.21f);

	std::cout << "o = " << o << ", p = " << p << std::endl;
	std::cout << "min(o, p) = " << Fixed::min(o, p) << std::endl;
	std::cout << "max(o, p) = " << Fixed::max(o, p) << std::endl;

	std::cout << "\n=== COMPLEX EXPRESSION TEST ===" << std::endl;
	Fixed q(5.0f);
	Fixed r(2.0f);
	Fixed s(3.0f);

	std::cout << "q = " << q << ", r = " << r << ", s = " << s << std::endl;
	std::cout << "(q + r) * s = " << ((q + r) * s) << std::endl;
	std::cout << "q / r + s = " << (q / r + s) << std::endl;

	std::cout << "\n=== EDGE CASES TEST ===" << std::endl;
	Fixed zero(0.0f);
	Fixed negative(-5.5f);
	Fixed small(0.01f);

	std::cout << "zero = " << zero << std::endl;
	std::cout << "negative = " << negative << std::endl;
	std::cout << "small = " << small << std::endl;
	std::cout << "negative + small = " << (negative + small) << std::endl;
	std::cout << "negative * negative = " << (negative * negative) << std::endl;

	std::cout << "\n=== DESTRUCTORS (watch for destructor calls) ===" << std::endl;

	return 0;
}
