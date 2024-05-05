#pragma once
		
namespace MCherevko {
	template <typename T> 
	class Vector {
		private:
			T* arr;
			int capacity = 10;
			int vec_size = 0;

		public:
			Vector() noexcept;
			Vector(const Vector&) = delete;
			Vector& operator = (const Vector&) = delete;
			~Vector() noexcept;
			
			void push_back(const T& value) noexcept;
			bool has_item(const T& value) const noexcept;
			bool insert(const int position, const T& value);
			void print() const noexcept;
			bool remove_first(const T& value) noexcept;
			int size() const noexcept;
			bool remove_all(const T& value);
	};
}
