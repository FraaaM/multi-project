#include "long_number.hpp"

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
		int str_length = get_length(str);
		if (str[0] == MINUS) {
			sign = -1;
			length = str_length - 1;
		}
		else {
			sign = 1;
			length = str_length;
		}

		numbers = new int[length];
		for (int i = 0; i < length; i++) {
			numbers[i] = str[str_length - i - 1] - ZERO;
		}
	}
	/*LongNumber::LongNumber(const char* const str) { // выдаёт неправельный ответ при вычитании (-) двух обектов
		length = get_length(str);						// из за этого конструктора

		if (str[0] == MINUS) {
			sign = NEGATIVE;
			length--;
			numbers = new int[length];
			for (int i = 0; i < length; i++) {
				numbers[i] = str[length - i] - ZERO;
			}
		}
		else {
			int sign = POSITIVE;
			numbers = new int[length];
			for (int i = 0; i < length; i++) {
				numbers[i] = str[length - i] - ZERO;
			}
		}
	}
	*/
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

		for (int i = 0; i < length; ++i) {
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

		if (sign == x.sign) {
			int max_length = length > x.length ? length : x.length;
			max_length++;
			LongNumber result(max_length, sign);

			for (int i = 0; i < length; i++) {
				result.numbers[i] += numbers[i];
			}
			for (int i = 0; i < x.length; i++) {
				result.numbers[i] += x.numbers[i];
			}
			for (int i = 0; i < result.length - 1; ++i) {
				if (result.numbers[i] >= 10) {
					result.numbers[i] %= 10;
					result.numbers[i + 1]++;
				}
			}
			while (result.numbers[result.length - 1] == 0) {
				result.length--;
			}
			return result;
		}

		if (sign != x.sign) {
			int max_length = length > x.length ? length : x.length;

			int max_sign = length > x.length ? sign : x.sign; // знак числа которое больше
			if (length == x.length) {
				for (int i = length - 1; i >= 0; i--) {
					if (numbers[i] > x.numbers[i]) {
						max_sign = sign;
						break;
					}
					if (numbers[i] < x.numbers[i]) {
						max_sign = x.sign;
						break;
					}
				}
			}

			LongNumber result(max_length, max_sign);

			if (max_sign == sign) {
				for (int i = 0; i < length; i++) {
					result.numbers[i] += numbers[i];
				}
				for (int i = 0; i < x.length; ++i) {
					result.numbers[i] -= x.numbers[i];
				}
			}
			if (max_sign == x.sign) {
				for (int i = 0; i < x.length; i++) {
					result.numbers[i] += x.numbers[i];
				}
				for (int i = 0; i < length; i++) {
					result.numbers[i] -= numbers[i];
				}
			}

			for (int i = 0; i < result.length; i++) {
				if (result.numbers[i] < 0) {
					result.numbers[i] += 10;
					result.numbers[i + 1]--;
				}
			}
			while (result.numbers[result.length - 1] == 0) {
				result.length--;
			}
			return result;
		}

	}

	LongNumber LongNumber::operator - (LongNumber& x) {
		if (x.sign == POSITIVE) {
			x.sign = NEGATIVE;
		}
		if (x.sign == NEGATIVE) {
			x.sign = POSITIVE;
		}
		return (*this + x);
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
		if (x.sign == LongNumber::NEGATIVE) {
			os << LongNumber::MINUS;
		}
		for (int i = 0; i < x.length; i++) {
			os << x.numbers[x.length - i - 1];
		}
		return os;

	}

}
