#pragma once

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <utility>


#define __pascal16near
#define __pascal16far
#define __regcall16near
#define __regcall16far
#define __thispascal16near
#define __thispascal16far

typedef unsigned char    byte;
typedef unsigned short   word;
typedef unsigned long    dword;
typedef signed char      sbyte;
typedef signed short     sword;
typedef signed long      sdword;
typedef unsigned char    undefined;
typedef unsigned char    undefined1;
typedef unsigned short   undefined2;
typedef unsigned long    undefined3;
typedef unsigned long    undefined4;

typedef unsigned int     uint;

/*
	Formatted File Stream
*/
struct FFileStream {
	std::string path;
	std::fstream file;
};

/*
	Unformatted File Stream
*/
struct UFileStream {
	std::string path;
	std::fstream file;
	size_t recsize;
};

/*
	Bare Minimum Unsafe Implementation of PascalString255
*/
class PascalString255
{
public:
	static constexpr size_t max_size = 255;

	PascalString255()
		: size_{ 0 }
		, string_{ '\0' }
	{ }

	PascalString255(char ch)
		: size_{ 1 }
		, string_{ ch }
	{
		string_[size_] = '\0';
	}

	PascalString255(const char* cstr, size_t size)
	{
		size = (std::min)(size, std::strlen(cstr));
		assert(size <= max_size);
		size_ = size;
		std::strncpy(string_, cstr, size_);
		string_[size_] = '\0';
	}

	template<size_t N>
	PascalString255(const char(&cstr)[N])
		: PascalString255(cstr, N)
	{ }

	PascalString255(const char* cstr)
		: PascalString255(cstr, std::strlen(cstr))
	{ }

	PascalString255(const PascalString255& other)
		: PascalString255(other.string_, other.size_)
	{ }

	PascalString255& operator=(char ch) {
		size_ = 1;
		string_[0] = ch;
		string_[size_] = '\0';
		return *this;
	}

	PascalString255& operator=(const char* cstr) {
		size_t size = std::strlen(cstr);
		size_ = (std::min)(size, max_size);
		std::strncpy(string_, cstr, size_);
		string_[size_] = '\0';
		return *this;
	}

	PascalString255& operator=(const PascalString255& other) {
		size_ = other.size_;
		std::strncpy(string_, other.string_, size_);
		string_[size_] = '\0';
		return *this;
	}

	void clear() {
		size_ = 0;
		string_[size_] = '\0';
	}

	void push_back(char ch) {
		if (size_ < max_size) {
			string_[size_++] = ch;
			string_[size_] = '\0';
		}
	}

	void pop_back() {
		if (size_ > 0) {
			string_[--size_] = '\0';
		}
	}

	byte size() const {
		return size_;
	}

	void resize(byte count, char ch = '\0') {
		assert(count <= max_size);
		if (count > size_) {
			std::memset(&string_[size_], ch, count - size_);
		}
		size_ = count;
		string_[size_] = '\0';
	}

	char& operator[](byte pos) {
		return string_[pos];
	}

	const char& operator[](byte pos) const {
		return string_[pos];
	}

	char* data() {
		return string_;
	}
	const char* data() const {
		return string_;
	}

	const char* c_str() const {
		return string_;
	}

	// Friend Functions

	friend void __pascal16far Concat(PascalString255& dest, const PascalString255& src);

	friend void __pascal16far Str(long value, word width, PascalString255* string, word size);

	friend std::istream& operator>>(std::istream& is, PascalString255& str) {
		is.get(str.string_, PascalString255::max_size, '\r');
		if (is.rdstate() == std::ios_base::failbit) is.clear();
		str.size_ = is.gcount();
		str.string_[str.size_] = '\0';
		return is;
	}

private:
	byte size_;
	char string_[max_size + 1]; // +1 for '\0'
};


/*
	CODE Section
	ram:1be6:0000-ram:1be6:147f
*/

void __pascal16far __SystemInit(void);
void __regcall16far Halt(word code);
void* __pascal16far GetMem(word size);
void __pascal16far FreeMem(void* pointer, word size);
word __pascal16far IOResult(void);
void __pascal16far __IOCheck(void);
void __regcall16far __StackCheck(word size);
void __pascal16far Assign(FFileStream& stream, const PascalString255& name);
void __pascal16far Reset(FFileStream& stream);
void __pascal16far Close(FFileStream& stream);
void __pascal16far ReadLn(FFileStream& stream);
void __pascal16far Read(FFileStream& stream, PascalString255* string, word width);
bool __pascal16far Eof(FFileStream& stream);
void __pascal16far Assign(UFileStream& stream, const PascalString255& name);
void __pascal16far Reset(UFileStream& stream, word recsize);
void __pascal16far Rewrite(UFileStream& stream, word recsize);
void __pascal16far Close(UFileStream& stream);
void __pascal16far Read(UFileStream& stream, byte* buffer);
void __pascal16far BlockRead(UFileStream& stream, byte* buffer, word count, word* result);
void __pascal16far BlockWrite(UFileStream& stream, const byte* buffer, word count, word* result);
void __pascal16far ParamStr(PascalString255& string, word index);
word __pascal16far ParamCount(void);
void __pascal16far Concat(PascalString255& dest, const PascalString255& src);
int __pascal16far StrComp(const PascalString255& str1, const PascalString255& str2);
std::pair<byte, word> __regcall16far GetElemOffset(byte elem, byte mask, byte count, byte offset);
word __pascal16far Random(word range);
void __pascal16far Randomize(void);
void __pascal16far Str(long value, word width, PascalString255* string, word size);
bool __pascal16far Eof(UFileStream& stream);
void __pascal16far Move(void* src, void* dest, word count);
void __pascal16far FillChar(void* src, word count, byte ch);
