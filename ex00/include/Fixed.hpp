#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int _fixedPoint;
		static const int _bits;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& src);
		Fixed& operator=(const Fixed& src);

		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif
