#include <Windows.h>

#include "Rtl.h"


/*
	__SystemInit Stub
*/
void __pascal16far __SystemInit(void)
{

}

/*
	https://www.freepascal.org/docs-html/rtl/system/halt.html
*/
void __regcall16far Halt(word code)
{
	std::exit(code);
}

/*
	https://www.freepascal.org/docs-html/rtl/system/getmem.html
*/
void* __pascal16far GetMem(word size)
{
	return std::malloc(size);
}

/*
	https://www.freepascal.org/docs-html/rtl/system/freemem.html
*/
void __pascal16far FreeMem(void* pointer, word size)
{
	std::free(pointer);
}

/*
	https://www.freepascal.org/docs-html/rtl/system/ioresult.html
*/
static volatile short IoState = 0; // WORD_1d2e_1254

word __pascal16far IOResult(void)
{
	return InterlockedExchange16(&IoState, 0);
}

/*
	__IOCheck Stub
*/
void __pascal16far __IOCheck(void)
{

}

/*
	__StackCheck Stub
*/
void __regcall16far __StackCheck(word size)
{

}

/*
	https://www.freepascal.org/docs-html/rtl/system/assign.html
*/
void __pascal16far Assign(FFileStream& stream, const PascalString255& name)
{
	stream.path = name.c_str();
}

/*
	https://www.freepascal.org/docs-html/rtl/system/reset.html
*/
void __pascal16far Reset(FFileStream& stream)
{
	stream.file = std::fstream{ stream.path, std::ios_base::in | std::ios_base::binary };
	if (!stream.file.is_open()) IoState = -1;
}

/*
	https://www.freepascal.org/docs-html/rtl/system/close.html
*/
void __pascal16far Close(FFileStream& stream)
{
	stream.file.close();
}

/*
	https://www.freepascal.org/docs-html/rtl/system/readln.html
*/
void __pascal16far ReadLn(FFileStream& stream)
{
	char buffer[256];
	stream.file.getline(buffer, sizeof(buffer), '\n');
	if (stream.file.fail()) IoState = -1;
}

/*
	https://www.freepascal.org/docs-html/rtl/system/read.html
*/
void __pascal16far Read(FFileStream& stream, PascalString255* string, word width)
{
	stream.file >> *string;
	if (stream.file.fail()) IoState = -1;
}

/*
	https://www.freepascal.org/docs-html/rtl/system/eof.html
*/
bool __pascal16far Eof(FFileStream& stream)
{
	return stream.file.peek() == std::fstream::traits_type::eof();
}

/*
	https://www.freepascal.org/docs-html/rtl/system/assign.html
*/
void __pascal16far Assign(UFileStream& stream, const PascalString255& name)
{
	stream.path = name.c_str();
}

/*
	https://www.freepascal.org/docs-html/rtl/system/reset.html
*/
void __pascal16far Reset(UFileStream& stream, word recsize = 128)
{
	stream.file = std::fstream{ stream.path, std::ios_base::in | std::ios_base::binary };
	if (!stream.file.is_open()) IoState = -1;
	stream.recsize = recsize;
}

/*
	https://www.freepascal.org/docs-html/rtl/system/rewrite.html
*/
void __pascal16far Rewrite(UFileStream& stream, word recsize = 128)
{
	stream.file = std::fstream{ stream.path, std::ios_base::out | std::ios_base::binary };
	if (!stream.file.is_open()) IoState = -1;
	stream.recsize = recsize;
}

/*
	https://www.freepascal.org/docs-html/rtl/system/close.html
*/
void __pascal16far Close(UFileStream& stream)
{
	stream.file.close();
}

/*
	https://www.freepascal.org/docs-html/rtl/system/read.html
*/
void __pascal16far Read(UFileStream& stream, byte* buffer)
{
	stream.file.read(reinterpret_cast<char*>(buffer), stream.recsize);
	if (stream.file.fail()) IoState = -1;
}

/*
	https://www.freepascal.org/docs-html/rtl/system/blockread.html
*/
void __pascal16far BlockRead(UFileStream& stream, byte* buffer, word count, word* result)
{
	std::streamsize lastg = stream.file.tellg();
	stream.file.read(reinterpret_cast<char*>(buffer), stream.recsize * count);
	if (stream.file.fail()) IoState = -1;
	word readcount = (stream.file.tellg() - lastg) / stream.recsize;
	if (result) *result = readcount;
}

/*
	https://www.freepascal.org/docs-html/rtl/system/blockwrite.html
*/
void __pascal16far BlockWrite(UFileStream& stream, const byte* buffer, word count, word* result)
{
	std::streampos lastp = stream.file.tellp();
	stream.file.write(reinterpret_cast<const char*>(buffer), stream.recsize * count);
	if (stream.file.fail()) IoState = -1;
	word writecount = (stream.file.tellp() - lastp) / stream.recsize;
	if (result) *result = writecount;
}

/*
	https://www.freepascal.org/docs-html/rtl/system/paramstr.html
*/
void __pascal16far ParamStr(PascalString255& string, word index)
{
	string = __argv[index];
}

/*
	https://www.freepascal.org/docs-html/rtl/system/paramcount.html
*/
word __pascal16far ParamCount(void)
{
	return __argc - 1;
}

/*
	https://www.freepascal.org/docs-html/rtl/system/concat.html
*/
void __pascal16far Concat(PascalString255& dest, const PascalString255& src)
{
	size_t size = src.size_ + dest.size_;
	if (size > PascalString255::max_size) size = PascalString255::max_size;
	std::strncpy(dest.string_ + dest.size_, src.string_, size - dest.size_);
	dest.size_ = size;
	dest.string_[dest.size_] = '\0';
}

/*
	https://www.freepascal.org/docs-html/rtl/strings/strcomp.html
*/
int __pascal16far StrComp(const PascalString255& string1, const PascalString255& string2)
{
	return std::strcmp(string1.c_str(), string2.c_str());
}

/*
	Compute Set Offset & Bit Mask
	In:
	AL = Element number
	AH = 01H or 0FEH
	DL = Number of bytes in set
	DH = Offset of first byte in set
	Out:
	AL = Bit mask
	DX = Byte offset
*/
std::pair<byte, word> __regcall16far GetElemOffset(byte elem, byte mask, byte count, byte offset)
{
	byte index = (elem >> 3) - offset;
	if ((offset <= (elem >> 3)) && (index < count)) {
		return { _rotl8(mask, elem & 0x07), index };
	}
	return { static_cast<sbyte>(mask) >> 1, 0 };
}

/*
	Linear Congruential Generator
	x(n+1) = (134775813 * x(n) + 1) mod 2^32
*/
static dword RngSeed; // DWORD_1d2e_1256

/*
	Advance LCG
*/
dword __pascal16near FUN_1be6_1204(void)
{
	RngSeed = 134775813 * RngSeed + 1;
	return RngSeed;
}

/*
	https://www.freepascal.org/docs-html/rtl/system/random.html
*/
word __pascal16far Random(word range)
{
	return (static_cast<unsigned long long>(FUN_1be6_1204()) * range) >> 32;
}

/*
	https://www.freepascal.org/docs-html/rtl/system/randomize.html
*/
void __pascal16far Randomize(void)
{
	SYSTEMTIME lt;
	GetLocalTime(&lt);
	RngSeed = (lt.wSecond << 24) | ((lt.wMilliseconds / 10) << 16) | (lt.wHour << 8) | lt.wMinute;
}

/*
	https://www.freepascal.org/docs-html/rtl/system/str.html
*/
void __pascal16far Str(long value, word width, PascalString255* string, word size)
{
	int result = std::snprintf(string->string_, size + 1, "%*d", width, value); // +1 for '\0'
	if (result >= 0) string->size_ = std::min<int>(size, result);
}

/*
	https://www.freepascal.org/docs-html/rtl/system/eof.html
*/
bool __pascal16far Eof(UFileStream& stream)
{
	return stream.file.peek() == std::fstream::traits_type::eof();
}

/*
	https://www.freepascal.org/docs-html/rtl/system/move.html
*/
void __pascal16far Move(void* src, void* dest, word count)
{
	std::memmove(dest, src, count);
}

/*
	https://www.freepascal.org/docs-html/rtl/system/fillchar.html
*/
void __pascal16far FillChar(void* src, word count, byte ch)
{
	std::memset(src, ch, count);
}
