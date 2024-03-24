#include "long_number.h"

namespace MCherevko {
	LongNumber::LongNumber() : length(1), sign(NULL) {
		numbers = new int[length];
		numbers[0] = 0;
	}

	LongNumber::LongNumber(int length, int sign) : length(length), sign(sign) {
		numbers = new int[length];
		for (int i = 0; i < length; i++) {
			numbers[i] = 0;
		}
	}

	LongNumber::LongNumber(const char* const str) {
		length = get_length(str);

		if (str[0] == MINUS) {
			sign = NEGATIVE;
			length--;
			numbers = new int[length];
			for (int i = 0; i < length; i++) {
				numbers[i] = str[i + 1] - ZERO;
			}
		}
		else {
			int sign = POSITIVE;
			numbers = new int[length];
			for (int i = 0; i < length; i++) {
				numbers[i] = str[i] - ZERO;
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
		length = 0;
		delete[] numbers;
		numbers = nullptr;
	}

	LongNumber& LongNumber::operator = (const char* const str) {
		delete[] numbers;
		length = get_length(str);

		if (str[0] == MINUS) {
			sign = NEGATIVE;
			length--;
			numbers = new int[length];
			for (int i = 0; i < length; i++) {
				numbers[i] = str[i + 1] - ZERO;
			}
		}
		else {
			int sign = POSITIVE;
			numbers = new int[length];
			for (int i = 0; i < length; i++) {
				numbers[i] = str[i] - ZERO;
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

	bool LongNumber::operator == (const LongNumber& x) const {
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

	bool LongNumber::operator!= (const LongNumber& x) const {
		return !(*this == x);
	}

	bool LongNumber::operator > (const LongNumber& x) const {

		return true;
	}

	bool LongNumber::operator < (const LongNumber& x)  const {
		// TODO
		return true;
	}

	LongNumber LongNumber::operator + (const LongNumber& x) const {
		return *this;
	}

	LongNumber LongNumber::operator - (const LongNumber& x) const {
		// TODO
		LongNumber result = x;
		return result;
	}

	LongNumber LongNumber::operator * (const LongNumber& x) const {
		// TODO
		LongNumber result;
		return result;
	}

	LongNumber LongNumber::operator / (const LongNumber& x) const {
		// TODO
		LongNumber result;
		return result;
	}

	LongNumber LongNumber::operator % (const LongNumber& x) const {
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

	int LongNumber::get_length(const char* const str) const {
		const char* l = str;
		while (*l) {
			++l;
		}
		auto length = (l - str);

		return length;
	}
	bool LongNumber::is_negative() const {
		return sign == NEGATIVE;
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
