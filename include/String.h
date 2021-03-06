#pragma once
#include "Object.h"

NS_MPF

class Type;

class String : public Object
{
public:
	//创建空的 String
	MPF_API constexpr String() noexcept;
	//释放资源
	MPF_API virtual ~String();

	//从字面量和长度创建 String
	MPF_API String(const wchar_t chars[], size_t length);
	MPF_API explicit String(const wchar_t* chars);

	MPF_API String(const String& str);
	MPF_API String(String&& str) noexcept;

	//从字面量创建 String
	template<size_t N>
	constexpr String(const wchar_t(&chars)[N]) noexcept
		:chars(chars), length(N - 1), needDelete(false)
	{
		static_assert(N >= 1, "string literal must have 1 char at least.");
	}

	//获取长度
	MPF_API size_t GetLength() const noexcept;
	
	//获取数组指针
	MPF_API const wchar_t* GetDataPointer() const noexcept;

	//获取哈希值
	MPF_API virtual uint32_t GetHashCode() const noexcept;

	//测试相等
	MPF_API bool operator==(const String& str) const noexcept;
	//测试不相等
	MPF_API bool operator!=(const String& str) const noexcept;

	MPF_API wchar_t operator[](size_t index) const;

	MPF_API const String& operator=(const String& str);
	MPF_API const String& operator=(String&& str) noexcept;

	MPF_API bool IsEmpty() const noexcept;

	//获取空字符串
	MPF_API static const String& GetEmpty();

	//获取类型
	MPF_API DECLARE_GETTYPE(String)
private:
	void Dispose() noexcept;
private:
	static String empty;

	DECLARE_TYPE(String)
	const wchar_t* chars = L"";
	bool needDelete;
	size_t length = 0;
	mutable uint32_t hashCode = 0;
};

NS_ED

namespace std
{
	template<>
	class hash<MPF::String>
	{
	public:
		size_t operator()(const MPF::String& str) const
		{
			return str.GetHashCode();
		}
	};
}