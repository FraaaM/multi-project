#include "long_number.h"

namespace MCherevko {
	LongNumber::LongNumber() {
		numbers = new int[1];
		numbers[0] = 0;
		length = 1;
		sign = NULL;
	}

	LongNumber::LongNumber(const char* const str) {
		length = get_lenght(str);

		if (str[0] == MINUS) {
			sign = NEGATIVE;
			length--;
			numbers = new int[length];
			for (int i = 0; i < length; i++) {
				numbers[i] = str[i + 1] - STR_NULL;
			}
		}
		else {
			int sign = POSITIVE;
			numbers = new int[length];
			for (int i = 0; i < length; i++) {
				numbers[i] = str[i] - STR_NULL;
			}
		}
	}

	LongNumber::LongNumber(const LongNumber& x) {
		length = x.length;
		sign = x.sign;
		numbers = new int[length];

		for (int i = 0; i < length; ++i) {
			numbers[i] = x.numbers[i];
		}
	}

	LongNumber::LongNumber(LongNumber&& x) {
		numbers = x.numbers;
		length = x.length;
		sign = x.sign;

		x.numbers = new int[1];
		x.numbers[0] = 0;
		x.length = 1;
		x.sign = NULL;
	}

	LongNumber::~LongNumber() {
		delete[] numbers;
	}

	LongNumber& LongNumber::operator = (const char* const str) {
		delete[] numbers;
		length = get_lenght(str);

		if (str[0] == MINUS) {
			sign = NEGATIVE;
			length--;
			numbers = new int[length];
			for (int i = 0; i < length; i++) {
				numbers[i] = str[i + 1] - STR_NULL;
			}
		}
		else {
			int sign = POSITIVE;
			numbers = new int[length];
			for (int i = 0; i < length; i++) {
				numbers[i] = str[i] - STR_NULL;
			}
		}
		return *this;
	}

	LongNumber& LongNumber::operator = (const LongNumber& x) {
		numbers = new int[x.length];
		length = x.length;
		sign = x.sign;

		for (int i = 0; i < this->length; ++i) {
			numbers[i] = x.numbers[i];
		}
		return *this;
	}

	LongNumber& LongNumber::operator = (LongNumber&& x) {
		if (this != &x) {
			numbers = x.numbers;
			length = x.length;
			sign = x.sign;

			x.numbers = new int[1];
			x.numbers[0] = 0;
			x.length = 1;
			x.sign = NULL;
		}

		return *this;
	}

	bool LongNumber::operator == (const LongNumber& x) {
		if (length != x.length || sign != x.sign) {
			return false;
		}
		for (int i = 0; i < length; ++i) {
			if (numbers[i] != x.numbers[i]) {
				return false;
			}
		}

		return true;
	}

	bool LongNumber::operator > (const LongNumber& x) {

		return true;
	}

	bool LongNumber::operator < (const LongNumber& x) {
		// TODO
		return true;
	}

	LongNumber LongNumber::operator + (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}

	LongNumber LongNumber::operator - (const LongNumber& x) {
		// TODO
		LongNumber result = x;
		return result;
	}

	LongNumber LongNumber::operator * (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}

	LongNumber LongNumber::operator / (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}

	LongNumber LongNumber::operator % (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}

	void LongNumber::print_numbers() {
		for (int i = 0; i < this->length; i++) {
			std::cout << this->numbers[i] << ' ';
		}
		std::cout << std::endl;
	}
	int LongNumber::get_digits_number() const {
		return length;
	}

	bool LongNumber::is_positive() const {
		return sign == POSITIVE;
	}

	int LongNumber::get_lenght(const char* const str) const {
		const char* l = str;
		while (*l) {
			++l;
		}
		auto length = (l - str);

		return length;
	}

	std::ostream& operator << (std::ostream& os, const LongNumber& x) {
		if (x.sign == -1)
			os << '-';

		for (int i = 0; i < x.length; ++i) {
			os << x.numbers[i];
		}

		return os;
	}

}