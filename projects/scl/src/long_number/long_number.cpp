#include "long_number.hpp"

namespace MCherevko {
	LongNumber::LongNumber() : length(1), sign(0) {
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
		for (int i = 0; i < length; i++) {
			numbers[i] = x.numbers[i];
		}
	}

	LongNumber::LongNumber(LongNumber&& x) {
		length = x.length;
		sign = x.sign;
		numbers = x.numbers;
		x.numbers = nullptr;
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
				numbers[i] = str[length - i - 1] - ZERO;
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
			x.sign = 0;
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
		if (this == &x) return false;

		if (sign != x.sign) {
			if (sign == POSITIVE) return true;
			else return false;
		}
		else {
			bool is_bigger = false;

			if (length > x.length) {
				is_bigger = true;
			}
			else if (length == x.length) {
				int i = 0;
				while (
					i < length - 1
					&& numbers[length - i - 1] == x.numbers[length - i - 1]
					) {
					i++;
				}
				if (numbers[length - i - 1] > x.numbers[length - i - 1]) {
					is_bigger = true;
				}
			}

			if (sign == POSITIVE) return is_bigger;
			else return !is_bigger;
		}
	}

	bool LongNumber::operator < (const LongNumber& x) const {
		return (*this != x) && !(*this > x);
	}

	// Не реализован случай когда результат равен 0
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

			if (result.length == 1 && result.numbers[0] == 0) {
				result.sign = POSITIVE;
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

			if (result.length == 1 && result.numbers[0] == 0) {
				result.sign = POSITIVE;
			}

			return result;
		}

	}

	LongNumber LongNumber::operator - (const LongNumber& x) const {
		LongNumber result = x;
		if (x.sign == POSITIVE) {
			result.sign = NEGATIVE;
		}
		if (x.sign == NEGATIVE) {
			result.sign = POSITIVE;
		}
		return (result + *this);
	}

	LongNumber LongNumber::operator * (const LongNumber& x) const {
		LongNumber result(length + x.length, sign * x.sign);

		for (int i = 0; i < x.length; i++) {
			for (int j = 0; j < length; j++) {
				result.numbers[j + i] += x.numbers[i] * numbers[j];
				if (result.numbers[i + j] > 9) {
					int q = result.numbers[i + j] / 10;
					result.numbers[i + j + 1] += q;
					result.numbers[i + j] -= q * 10;
				}
			}
		}

		while (result.length > 1 && result.numbers[result.length - 1] == 0) {
			result.length--;
		}

		return result;
	}

	LongNumber LongNumber::operator / (const LongNumber& x) const {
		LongNumber result;

		if (x.length == 1 && x.numbers[0] == 0) {
			// TODO ZeroDivisionException
		}

		LongNumber divident = *this;
		divident.sign = 1;
		if (divident < x) {
			return result;
		}
		else {
			result = LongNumber(length - x.length + 1, sign * x.sign);

			for (int i = 0; i < result.length; i++) {
				LongNumber divider = LongNumber(length - i, 1);

				for (int j = 0; j < x.length; j++) {
					divider.numbers[length - x.length - i + j] = x.numbers[j];
				}

				int k = 0;
				while (divident > divider || divident == divider) {
					k++;
					divident = divident - divider;
				}
				result.numbers[result.length - i - 1] = k;
			}
		}

		while (
			result.length > 1
			&& result.numbers[result.length - 1] == 0
			) {
			result.length--;
		}

		return result;
	}

	LongNumber LongNumber::operator % (const LongNumber& x) const {
		if (is_negative()) {
			LongNumber np_1 = x.is_negative() ? "1" : "-1";
			return *this - (*this / x + np_1) * x;
		}
		else {
			return *this - (*this / x) * x;
		}
	}

	int LongNumber::get_digits_number() const {
		return length;
	}

	int LongNumber::get_rank_number(int rank) const {
		// TODO OutOfBoundException
		return numbers[rank - 1];
	}

	bool LongNumber::is_negative() const {
		return sign == NEGATIVE;
	}

	void LongNumber::print_numbers() {
		for (int i = 0; i < this->length; i++) {
			std::cout << this->numbers[i] << ' ';
		}
		std::cout << std::endl;
	}

	int LongNumber::get_length(const char* const str) const {
		const char* l = str;
		while (*l) {
			++l;
		}
		auto length = (l - str);

		return length;
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


