#include "long_number.hpp"

namespace MCherevko {
	LongNumber::LongNumber() {
		numbers = new int[1];
		numbers[0] = 0;
		length = 1;
		sign = NULL;
	}
	
	LongNumber::LongNumber(const char* const str) {
		length = get_length(str);

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
		// TODO
		return *this;
	}
	
	LongNumber& LongNumber::operator = (const LongNumber& x) {
		// TODO
		return *this;
	}
	
	LongNumber& LongNumber::operator = (LongNumber&& x) {
		// TODO
		return *this;
	}
	
	bool LongNumber::operator == (const LongNumber& x) {
		// TODO
		return true;
	}
	
	bool LongNumber::operator > (const LongNumber& x) {
		// TODO
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
	
	int LongNumber::get_digits_number() const {
		return length;
	}
	
	bool LongNumber::is_positive() const {
		return sign == POSITIVE;
	}
	
	// ----------------------------------------------------------
	// PRIVATE
	// ----------------------------------------------------------
	int LongNumber::get_length(const char* const str) const {
		const char* l = str;
		while (*l) {
			++l;
		}
		auto length = (l - str);
		
		return length;
	}
	
	// ----------------------------------------------------------
	// FRIENDLY
	// ----------------------------------------------------------
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		// TODO
		return os;
	}
}
